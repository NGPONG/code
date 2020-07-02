#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <wait.h>

void foo_01(void) {
  int fd_r_w[2] = { -1 };
  if (pipe(fd_r_w) == -1) {
    perror("e");
    exit(EXIT_FAILURE);
  }

  int pid = fork();
  if (pid < 0) {
    perror("e");
    exit(EXIT_FAILURE);
  } else if (pid == 0) { /* child process context */
    /* read */
    printf("[%d] child start read\n", getpid());
    char buf[64] = { 0 };
    read(fd_r_w[0], buf, sizeof(buf));
    printf("%s\n", buf);
    printf("[%d] child end read\n", getpid());

    /* write */
    printf("[%d] child start write\n", getpid());
    char *str = "hello,NGPONG!";
    write(fd_r_w[1], str, strlen(buf) + 1);
    printf("[%d] child end write\n", getpid());

    exit(EXIT_SUCCESS);
  } else if (pid > 0) { /* parent process context */
    /* write */
    printf("[%d] parent start write\n", getpid());
    char *str = "hello,world!";
    write(fd_r_w[1], str, strlen(str) + 1);
    printf("[%d] parent end write\n", getpid());

    sleep(5);

    /* read */
    printf("[%d] parent start read\n", getpid());
    char buf[64] = { 0 };
    read(fd_r_w[0], buf, sizeof(buf));
    printf("%s\n", buf);
    printf("[%d] parent end read\n", getpid());

    int state;
    wait(&state);
    printf("[%d] child process exit:%d\n", getpid(), pid);
  }
}

void foo_02(void) {
  int fd[2];
  pipe(fd);

  /* begin wirte */
  char *str = "hello,world!";
  write(fd[1], str, strlen(str) + 1);

  /* begin read */
  char buf[64] = { 0 };
  read(fd[0], buf, sizeof(buf));

  printf("%s\n", buf);
}

void foo_03(void) {
  int fd[2] = { 0 };
  if (pipe(fd) == -1) {
    perror("e");
    exit(EXIT_FAILURE);
  }
  /* create child process */
  int pid = fork();
  if (pid < 0) {
    perror("");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    sleep(3);

    int idx = 0;
    char buf[128] = { 0 };
    while (true) {
      read(fd[0], buf, sizeof(buf));
      printf("[%d] child read data to pipe:%s\n", ++idx, buf);

      memset(buf, 0x0, sizeof(buf));

      usleep(200 * 1000);
    }

    exit(EXIT_SUCCESS);
  }

  /* parent process context */
  int idx = 0;
  char buf[64] = { 0 };
  while (true) {
    memset(buf, 64, sizeof(buf));
    printf("[%d] parent write data to pipe:%s\n", ++idx, buf);
    write(fd[1], buf, sizeof(buf));
    memset(buf, 0x0, sizeof(buf));

    /* usleep(20 * 1000); */
  }
}

/* error */
void foo_04(void) {
  int fd[2] = { 0 };
  if (pipe(fd) == -1) {
    perror("e");
    exit(EXIT_FAILURE);
  }

  close(fd[0]);

  write(fd[1], "hello", strlen("hello") + 1);

  printf("OK!");
}

void foo_05(void) {
  int fd[2] = { 0 };
  if (pipe(fd) == -1) {
    perror("e");
    exit(EXIT_FAILURE);
  }

  close(fd[1]);

  char buf[64] = { 0 };
}

void foo_06(void) {
  int fd[2] = { 0 };
  if (pipe(fd) == -1) {
    perror("e");
    exit(EXIT_FAILURE);
  }

  int pid = fork();
  if (pid < 0) {
    perror("e");
    exit(EXIT_FAILURE);
  } else if (pid == 0) { /* child process context */
    /* read */
    printf("[%d] child start read\n", getpid());
    char buf[0x8] = { 0 };
    int ln = read(fd[0], buf, sizeof(buf));
    printf("[%d] child end read, size = (%d)\n", getpid(), ln);
    printf("[%d] %s\n", getpid(), buf);

    /* write */
    printf("[%d] child start write\n", getpid());
    char *data = "child data @@@@@@@@@@@@@@@@@@@2";
    int sz = write(fd[1], data, strlen(data) + 1);
    printf("[%d] child end write, size = (%d)\n", getpid(), sz);

    exit(EXIT_SUCCESS);
  }

  /* parent process context */

  /* sleep 500ms to wait child process for read data */
  usleep(500 * 1000);

  /* write */
  printf("[%d] parent start write\n", getpid());
  char *data_1 = "hello,world!";
  int sz_1 = write(fd[1], data_1, strlen(data_1) + 1);
  char *data_2 = "hello,NGPONG!";
  int sz_2 = write(fd[1], data_2, strlen(data_2) + 1);
  printf("[%d] parent end write, size_1 = (%d), size_2 = (%d)\n", getpid(), sz_1, sz_2);

  /* read */
  printf("[%d] parent start read\n", getpid());
  char buf[0x40] = { 0 };
  int ln = read(fd[0], buf, sizeof(buf));
  printf("[%d] parent end read, size = (%d)\n", getpid(), ln);
  printf("[%d] %s\n", getpid(), buf);

  /* wait for child process executed */
  int stat;
  wait(&stat);

  /* close all pipe */
  for (size_t i = 0; i < 2; ++i) {
    close(fd[i]);
  }

  /* end */
  exit(EXIT_SUCCESS);
}

int main(void) {
  /* foo_01(); */
  /* foo_02(); */
  /* foo_03(); */
  /* foo_04(); */
  foo_06();

  return EXIT_SUCCESS;
}
