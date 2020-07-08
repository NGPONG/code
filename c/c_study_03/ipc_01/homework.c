#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

void foo_01(void) {
  int fd_pipe[2] = { 0 };
  if (pipe(fd_pipe) == -1) {
    perror("e");
    exit(EXIT_FAILURE);
  }

  int pid = fork();
  if (pid < 0) {
    perror("e");
    exit(EXIT_FAILURE);
  } else if (pid == 0) { /* child process context */
    close(fd_pipe[0]);

    /* redirect stdin and stdout to pipe line */
    dup2(fd_pipe[1], STDOUT_FILENO);

    execlp("ps", "ps", "aux", NULL); /* execute ps command and write data to pipe line because we redirect stdout brefore */
  }

  /* parent process context */
  int stat;
  wait(&stat); /* wait for child process executed */

  close(fd_pipe[1]);

  /* redirect stdin */
  dup2(fd_pipe[0], STDIN_FILENO);

  execlp("grep", "grep", "--color=auto", "bash", NULL);
}

void foo_02(void) {
  int fd_pipe[2] = { 0 };
  if (pipe(fd_pipe) == -1) {
    perror("e");
    exit(EXIT_FAILURE);
  }
  
  /* set read is non-block */
  int fl = fcntl(fd_pipe[0], F_GETFL);
  fcntl(fd_pipe[0], F_SETFL, fl | O_NONBLOCK);

  for (size_t i = 0; i < 2; ++i) {
    int pid = fork();
    if (pid < 0) {
      perror("e");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      if (i == 0) {
        /* ps */
        close(fd_pipe[0]);

        /* redirect stdin and stdout to pipe line */
        dup2(fd_pipe[1], STDOUT_FILENO);

        execlp("ps", "ps", "aux", NULL); /* execute ps command and write data to pipe line because we redirect stdout brefore */
      } else {
        sleep(1);

        /* grep */
        close(fd_pipe[1]);

        /* redirect stdin */
        dup2(fd_pipe[0], STDIN_FILENO);

        execlp("grep", "grep", "--color=auto", "qv2ray", NULL);
      }
    }
  }

  int pid;
  while ((pid = waitpid(-1, 0x0, 0)) != -1) {
    printf("child process [%d] exited\n", pid);
  }

  /* close pipe line */
  for (size_t i = 0; i < 2; ++i) {
    close(fd_pipe[i]);
  }

  exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
  /* foo_01(); */
  foo_02();

  return EXIT_SUCCESS;
}
