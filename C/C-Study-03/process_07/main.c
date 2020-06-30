#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <wait.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  int pid = fork();
  if (pid < 0) {
    perror("E");
    return EXIT_FAILURE;
  } else if (pid > 0) { /* parent process */
    int stat;
    wait(&stat);

    printf("[%d] child process exit %s\n", getpid(), (stat == 1 ? "FAILURE" : "SUCCESS"));

    return EXIT_SUCCESS;
  } else if (pid == 0) { /* child process */
    printf("[%d] execute ps\n", getpid());
    int flag = execl("ps", "process_state", "aux", NULL);
    if (flag < 0) {
      perror("E");
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}
