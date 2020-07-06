#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define FIFO_NAME "myfifo"

void foo_01(void) {
  int fd = open("./myfifo.p", O_RDONLY);
  if (fd < 0) {
    perror("e");
    exit(EXIT_FAILURE);
  }

  printf("[%d] start read\n", getpid());

  char buf[0x40] = { 0 };
  int size = read(fd, buf, sizeof(buf));
  printf("size = %d, %s\n", size, buf);

  close(fd);
}

void foo_02(void) {
  int pid = fork();
  if (pid < 0) {
    perror("e");
    exit(EXIT_FAILURE);
  } else if (pid == 0) { /* child process context */
    int fd_w = open(FIFO_NAME, O_WRONLY);
    if (fd_w < 0) {
      perror("e");
      exit(EXIT_FAILURE);
    }

    /* sleep(5); */
    printf("child start\n");

    /* char *str = "hello,world!"; */
    /* while (true) {                       */
    /* write(fd_w, str, strlen(str) + 1); */
    /*   sleep(1);                          */
    /* }                                    */

    char *str = "hello,world!";
    int size = write(fd_w, str, strlen(str) + 1);
    printf("child write %d bytes:%s", size, str);

    /* int num;                                               */
    /* char buf[64] = { 0 };                                  */
    /* while (fgets(buf, sizeof(buf), stdin), !feof(stdin)) { */
    /*   if ((num = write(fd_w, buf, strlen(buf))) < 0)       */
    /*     perror("child - write");                           */
    /*   else                                                 */
    /*     printf("child - wrote %d bytes\n", num);           */
    /* }                                                      */


    /* int idx = 0;                                  */
    /* char buf[0x10] = { 0 };                       */
    /* while (true) {                                */
    /*   ++idx;                                      */
    /*   sprintf(buf,"%d\n",idx);                    */
    /*   int size = write(fd_w,buf,sizeof(buf));     */
    /*   printf("child write %d bytes:%s",size,buf); */

    /*   memset(buf,0,sizeof(buf));                  */

    /*   sleep(2);                                   */
    /* }                                             */

    close(fd_w);
    exit(EXIT_SUCCESS);
  }

  /* parent process context */
  int fd_r = open(FIFO_NAME, O_RDONLY);
  if (fd_r < 0) {
    perror("e");
    exit(EXIT_FAILURE);
  }

  printf("parent start\n");

  char buf[64] = { 0 };
  while (true) {
    int size = read(fd_r, buf, sizeof(buf));
    printf("parent read %d bytes :%s\n", size, buf);

    memset(buf, 0x0, sizeof(buf));
  }

  close(fd_r);
  exit(EXIT_SUCCESS);
}

int foo_03(void) {
  char buf[256];
  int num, fd;
  pid_t pid;

  if (mkfifo(FIFO_NAME, 0666) < 0)
    perror("mkfifo");

  pid = fork();
  if (pid == 0) {
    printf("child - waiting for readers...\n");
    if ((fd = open(FIFO_NAME, O_WRONLY)) < 0)
      perror("child - open");

    printf("child - got a reader -- type some stuff\n");
    while (fgets(buf, sizeof(buf), stdin), !feof(stdin)) {
      if ((num = write(fd, buf, strlen(buf))) < 0)
        perror("child - write");
      else
        printf("child - wrote %d bytes\n", num);
    }

    close(fd);
    exit(0);
  } else {
    printf("parent - waiting for writers...\n");
    if ((fd = open(FIFO_NAME, O_RDONLY)) < 0)
      perror("parent - open");

    printf("parent - got a writer\n");
    do {
      if ((num = read(fd, buf, sizeof(buf))) < 0)
        perror("parent - read");
      else {
        buf[num] = '\0';
        printf("parent - read %d bytes: \"%s\"\n", num, buf);
      }
    } while (num > 0);

    close(fd);
    wait(0);
  }

  unlink(FIFO_NAME);
  return 0;
}

void foo_04(void) {
  if (mkfifo(FIFO_NAME, 0666) < 0)
    perror("mkfifo");

  int pid = fork();
  if (pid < 0) {
    printf("Create child process error\n");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    int fd_r = open(FIFO_NAME, O_RDONLY);
    if (fd_r < 0) {
      printf("Open reading-only fifo file error\n");
      exit(EXIT_FAILURE);
    }

    printf("[%d] Child process start read\n", getpid());

    char buf[14] = { 0 };
    int size;
    while ((size = read(fd_r, buf, sizeof(buf))) != 0) {
      printf("[%d] child process read %d bytes, value = %s", getpid(), size, buf);
    }

    printf("[%d] Child process ending\n", getpid());
    close(fd_r);
    return;
  } else {
    int fd_w = open(FIFO_NAME, O_WRONLY);
    if (fd_w < 0) {
      printf("Open writing-only fifo file error\n");
      exit(EXIT_FAILURE);
    }

    printf("[%d] Parent process start read\n", getpid());

    char buf[0x100] = { 0 };
    int idx = 0;
    int size;
    while (++idx < 10) {
      sprintf(buf, "%d\n", idx);
      int size = write(fd_w, buf, strlen(buf) + 1);

      printf("[%d] Parnet process write %d bytes, value = %s", getpid(), size, buf);

      memset(buf, 0, sizeof(buf));
    }

    printf("[%d] Parent process ending\n", getpid());
    close(fd_w);
    return;
  }
}

void foo_05(void) {
  int fd[2] = { 0 };
  if (pipe(fd) < 0) {
    perror("");
    return;
  }

  int i = 128;
  write(fd[1], &i, sizeof(int));

  char buf[32] = { 0 };
  memset(buf, 1, sizeof(buf));
  read(fd[0], buf, sizeof(buf));

  int a = 10;
}

void foo_06(void) {
  unlink(FIFO_NAME);
}

void foo_07(void) {
  int fd_w = open(FIFO_NAME, O_WRONLY);
  if (fd_w < 0) {
    printf("Open writing-only fifo file error\n");
    exit(EXIT_FAILURE);
  }

  printf("[%d] Parent process start read\n", getpid());

  char *str = "hello,world!\n";
  int size = write(fd_w, str, strlen(str) + 1);
  printf("[%d] Parnet process write %d bytes, value = %s", getpid(), size, str);

  close(fd_w);
  printf("[%d] Parent process ending\n", getpid());
  return;
}

int main(int argc, char *argv[]) {
  /* foo_01(); */
  /* foo_02(); */
  /* foo_03(); */
  /* foo_04(); */
  /* foo_05(); */
  /* foo_06(); */

  foo_07();

  return EXIT_SUCCESS;
}
