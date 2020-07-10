#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

void foo(void) {
  int s_pid = fork();
  if (s_pid == -1) {
    perror("create child process error");
    exit(EXIT_FAILURE);
  } else if (s_pid == 0) {
    /* Improve this child process to be a session leader. */
    int sid = setsid();
    if (sid < 0) {
      perror("create session error");
      exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < 3; ++i) {
      int pid = fork();
      if (pid == 0) {
        int idx = 0;
        while ((++idx) < 0x400) {
          printf("[%d] Child process executing, value = %d\n", getpid(), idx);
          usleep(1000 * 1000);
        }
      } else if (pid > 0) {
        printf("[%d] Create child process [%d]\n", getpid(), pid);
      }

      while (true) {
        usleep(1000 * 1000);
      }
    }

  } else {
    /* Parent process exit. */
    printf("[%d] Create child process [%d]\n", getpid(), s_pid);
    exit(EXIT_SUCCESS);
  }
}

int main(int argc, char *argv[]) {

  return EXIT_SUCCESS;
}
