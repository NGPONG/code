#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "myfifo"

void foo(void) {
  int fd_r = open(FIFO_NAME, O_RDONLY | O_NONBLOCK);
  if (fd_r < 0) {
    printf("Open reading-only fifo file error\n");
    exit(EXIT_FAILURE);
  }

  printf("[%d] Child process start read\n", getpid());

  sleep(5);

  char buf[14] = { 0 };
  int size = read(fd_r, buf, sizeof(buf));
  printf("[%d] child process read %d bytes, value = %s", getpid(), size, buf);

  close(fd_r);
  printf("[%d] Child process ending\n", getpid());
  return;
}

int main(int argc, char *argv[]) {
  foo();

  return EXIT_SUCCESS;
}
