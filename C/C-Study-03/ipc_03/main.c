#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

void foo_01(void) {
  int fd = open("./myfifo.p", O_RDONLY);
  if (fd < 0) {
    perror("e");
    exit(EXIT_FAILURE);
  }

  char buf[0x40] = { 0 };
  int size = read(fd, buf, sizeof(buf));
  printf("size = %d, %s\n", size, buf);

  close(fd);
}

void foo_02(void) {
  int fd_r = open("./myfifo.p", O_RDONLY);
  if (fd_r < 0) {
    perror("e");
    exit(EXIT_FAILURE);
  }

  /* int fd_w = open("./myfifo.p", O_WRONLY); */
  /* if (fd_w < 0) {                          */
  /*   perror("e");                           */
  /*   exit(EXIT_FAILURE);                    */
  /* }                                        */

  printf("123123");

  int pid = fork();
  if (pid < 0) {
    perror("e");
    exit(EXIT_FAILURE);
  } else if (pid == 0) { /* child process context */
    printf("child start");

    /* int idx = 0;                      */
    /* while (true) {                    */
    /*   ++idx;                          */
    /*   write(fd_w, &idx, sizeof(int)); */

    /*   sleep(1);                       */
    /* }                                 */

    exit(EXIT_SUCCESS);
  }

  printf("parent start");

  /* parent process context */
  char buf[64] = { 0 };

  /* while (true) {                   */
  /*   read(fd_r, buf, sizeof(buf));  */
  /*   printf("%s", buf);             */

  /*   memset(buf, 0x0, sizeof(buf)); */
  /* }                                */
  
  exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
  /* foo_01(); */
  foo_02();

  return EXIT_SUCCESS;
}
