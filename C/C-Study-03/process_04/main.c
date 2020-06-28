#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

void foo_01(void) {
  int *ptr = malloc(sizeof(int));
  memset(ptr, 0x0, sizeof(int));

  int _pid = fork();
  if (_pid < 0) {
    perror("E");
    exit(EXIT_FAILURE);
  }

  /* Parent process context. */
  if (_pid > 0) {
    while (true) {
      ++(*ptr);
      printf("F[%d] %d(%p)\n", getpid(), *ptr, ptr);

      if (*ptr == 0x400) {
        return;
      }

      sleep(3);
    }
  }

  /* Child process context. */
  if (_pid == 0) {
    while (true) {
      ++(*ptr);
      printf("C[%d] %d(%p)\n", getpid(), *ptr, ptr);

      if (*ptr == 0x400) {
        return;
      }

      sleep(1);
    }
  }
}

void foo_02(void) {
  bool is_first_create = true;

  for (size_t i = 0; i < 3; ++i) {
    if (i > 0 && is_first_create) is_first_create = false;

    /* Child Process */
    int pid = fork();
    if (pid < 0) {
      perror("E");
      exit(EXIT_FAILURE);
    }
    if (pid > 0) {
      printf("create [%d]\n", pid);
      sleep(5);
      continue;
    }

    if (is_first_create) {
      /* Child_Child process */
      int ch_pid = fork();
      if (ch_pid < 0) {
        perror("E");
        exit(EXIT_FAILURE);
      }

      if (ch_pid == 0) {
        while (true) {
          printf("[%d] -> [%d]\n", getppid(), getpid());
          sleep(1);
        }
      }
    }

    while (true) {
      printf("[%d] -> [%d]\n", getppid(), getpid());
      sleep(1);
    }
  }

  /* Root process */
  while (true) {
    /* printf("[%d] -> [%d]\n",getppid() ,getpid()); */
    sleep(1);
  }
}

void foo_03(void) {
  int pid = fork();
  if (pid < 0) {
    perror("E");
    exit(EXIT_SUCCESS);
  } else if (pid == 0) { /* child process */
    /* make an error manually */
    /* char *str = "hello,world!";            */
    /* str[0] = 'A';                          */

    /* int idx = 0x5;                         */
    /* while ((--idx)) {                      */
    /*   printf("[%d]: %d\n", getpid(), idx); */
    /*   sleep(1);                            */
    /* }                                      */

    return;
    /* exit(EXIT_FAILURE); */
  } else if (pid > 0) { /* parent process */
    int status;
    wait(&status);
    printf("child exit: is_normal_exited = %d, exit_status = %d\n", WIFEXITED(status), WEXITSTATUS(status));
  }
}

/* Zombie process test */
void foo_04(void) {
  int pid = fork();
  if (pid < 0) {
    perror("E");
    exit(EXIT_FAILURE);
  } else if (pid == 0) { /* child process */
    int idx = 0;
    while (true) {
      if ((++idx) == 15) {
        char *str = "hello,world!";
        str[0] = 'A';

        exit(EXIT_SUCCESS);
      }
      printf("%d\n", idx);
      sleep(1);
    }
  }
  int idx = 0;
  while (true) {
    if ((++idx) == 5) {
      exit(EXIT_SUCCESS);
    }
    sleep(1);
  }
}

int main(int argc, char *argv[]) {
  /* foo_01(); */
  /* foo_02(); */
  /* foo_03(); */
  foo_04();

  return EXIT_SUCCESS;
}
