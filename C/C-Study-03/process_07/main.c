#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>

void foo_01() {
  int pid = fork();
  if (pid < 0) {
    perror("E");
    exit(EXIT_FAILURE);
  } else if (pid > 0) { /* parent process */
    int stat;
    wait(&stat);

    printf("[%d] child process exit %s\n", getpid(), (stat == 1 ? "FAILURE" : "SUCCESS"));

    exit(EXIT_SUCCESS);
  } else if (pid == 0) { /* child process */
    printf("[%d] execute ps\n", getpid());
    int flag = execl("ps", "process_state", "aux", NULL);
    if (flag < 0) {
      perror("E");
      exit(EXIT_FAILURE);
    }
  }
}

void foo_02(void) {
  int pid = fork();
  if (pid < 0) {
    perror("E");
    exit(EXIT_FAILURE);
  } else if (pid == 0) { /*child process*/
    printf("[%d] child process\n", getpid());
    exit(EXIT_SUCCESS);
  } else if (pid > 0) {
    printf("[%d] parent process\n", getpid());

    int stat;
    wait(&stat);

    printf("%d\n", stat);
    printf("%d\n", WIFEXITED(stat));
    printf("%d\n", WEXITSTATUS(stat));
    printf("%d\n", WIFSIGNALED(stat));
    printf("%d\n", WTERMSIG(stat));
  }
}

void foo_03(void) {
  for (int i = 0; i < 2; ++i) {
    int pid = fork();
    if (pid < 0) {
      perror("E");
      exit(EXIT_FAILURE);
    } else if (pid == 0) { /* child process */
      int idx = 0;
      while (true) {
        sleep(1);

        if (i == 1 && idx == 10) {
          exit(EXIT_SUCCESS);
        } else if (idx == 25) {
          exit(EXIT_SUCCESS);
        }

        printf("[%d] %d\n", getpid(), idx);
        ++idx;
      }
    }
  }

  /* parent process */
  printf("[%d] parent process\n", getpid());

  int stat;
  wait(&stat);

  printf("child exit [%d]\n", WEXITSTATUS(stat));
}

void foo_04(void) {
  int state;
  pid_t pid = wait(&state);

  printf("%d\n", pid);
}

void foo_05(void) {
  for (size_t i = 0; i < 3; ++i) {
    int pid = fork();
    if (pid < 0) {
      perror("E");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      /* int fd = open("./test.log", O_RDONLY); */

      /* char buf[5] = { 0 };                   */
      /* read(fd, buf, sizeof(buf));            */
      /* printf("%s\n", buf);                   */

      printf("[%d]\n", getpid());
      exit(EXIT_FAILURE);
    }
    /* printf("create process [%d]\n", pid); */
    /* continue;                             */
  }

  printf("hello,world!");

  /* parent process context */
  int idx = 0;
  while ((++idx) < 0x400) {
    printf("[%d]\n", idx);
    sleep(1);
  }
}

int main(int argc, char *argv[]) {
  /* foo_02(); */
  /* foo_03(); */
  /* foo_04(); */
  foo_05();

  return EXIT_SUCCESS;
}
