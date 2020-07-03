#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

void foo(void) {
  int fd = open("./myfifo.p", O_RDONLY);
  if (fd < 0) {
    perror("e");
    exit(EXIT_FAILURE);
  }

  char buf[0x40] = { 0 };
  int size = read(fd, buf, sizeof(buf));
  printf("size = %d, %s", size, buf);

  close(fd);
}

int main(int argc, char *argv[]) {
  foo();

  return EXIT_SUCCESS;
}
