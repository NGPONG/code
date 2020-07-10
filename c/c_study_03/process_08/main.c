#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

void foo_01(void) {
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

    for (int i = 0; i < 5; ++i) {
      int pid = fork();
      if (pid == 0) {
        int idx = 0;
        while ((++idx) < 0x400) {
          printf("[%d] Child process executing, value = %d\n", getpid(), idx);
          usleep(1000 * 1000);
        }

        printf("Child process exit: %d\n", getpid());
        exit(EXIT_SUCCESS);
      } else if (pid > 0) {
        printf("[%d] Create child process [%d]\n", getpid(), pid);
      }
    }

    while (true) {
      usleep(1000 * 1000);
    }

  } else {
    /* Parent process exit. */
    printf("[%d] Create child process [%d]\n", getpid(), s_pid);
    exit(EXIT_SUCCESS);
  }

  printf("Child process exit: %d\n", getpid());
}

void handler(int _sig) {
  int fd_w = open("./log", O_WRONLY | O_APPEND, 0644);
  if (fd_w < 0) {
    perror("open file error");
    exit(EXIT_FAILURE);
  }

  static int idx = 0;
  char *buff = malloc(32);
  if (buff == NULL) {
    perror("memory error");
    exit(EXIT_FAILURE); /* 等下试试这玩意 */
  }
  memset(buff, 0x0, 32);

  sprintf(buff, "%d\n", ++idx);

  /* strlen(xx) + 1 means ensure writed full bytes('\0') */
  write(fd_w, buff, strlen(buff) + 1);

  free(buff);
  close(fd_w);
}
void foo(void) {
  int pid = fork();
  if (pid < 0) {
    perror("create child process error\n");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    /* Improve child process to be session leader. */
    int sid = setsid();
    /* Reset file mask */
    umask(0000);
    /* Registered a clock */
    signal(SIGALRM, handler);

    struct itimerval time_value;
    time_value.it_value.tv_sec = 0;
    time_value.it_value.tv_usec = 1 * 1000;
    time_value.it_interval.tv_sec = 1;
    time_value.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &time_value, NULL);

    printf("server [%d] started\n", getpid());
    while (true) {
      sleep(1);
    }
  }
}

int main(int argc, char *argv[]) {
  /* foo_01(); */
  foo();
 // int fd_w = open("./log", O_CREAT | O_APPEND | O_EXCL, 0644);
 // if (fd_w < 0) {
 //   perror("open file error");
 //   exit(EXIT_FAILURE);
 // }

 // static int idx = 0;
 // char *buff = malloc(sizeof(32));
 // if (buff == NULL) {
 //   perror("memory error");
 //   exit(EXIT_FAILURE); /* 等下试试这玩意 */
 // }
 // memset(buff, 0x0, 32);

 // sprintf(buff, "%d\n", ++idx);

 // /* strlen(xx) + 1 means ensure writed full bytes('\0') */
 // write(fd_w, buff, strlen(buff) + 1);

 // free(buff);
 // close(fd_w);

  return EXIT_SUCCESS;
}
