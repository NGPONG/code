#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <wait.h>

void foo(void) {
  for (size_t i = 0; i < 3; ++i) {
    int pid = fork();
    if (pid < 0) {
      perror("E");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {  /* child process */
      sleep(1);

      if (i == 0) {         /* execute sys command */
        printf("[%d] STEP 1 -------------------------------------->\n\n", getpid());
        execlp("ps", "process_state", "aux", NULL);
      } else if (i == 1) {  /* make an error */
        printf("[%d] STEP 2 -------------------------------------->\n\n", getpid());

        /* Segmentation fault */
        char *str = "Hello,world!";
        str[1] = 'B';
      } else if (i == 2) {  /* execute custom command */
        printf("[%d] STEP 3 -------------------------------------->\n\n", getpid());
        execl("./main", "", NULL);
      }
    }
  }

  int pid;
  int stat;
  while ((pid = waitpid(0, &stat, 0)) != -1) {
    printf("resouce [%d], state [%d]\n", pid, WEXITSTATUS(stat));
    memset(&stat, 0x0, sizeof(int));
  }
}

int main(int argc, char *argv[]) {
  foo();

  return EXIT_SUCCESS;
}
