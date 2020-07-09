#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("%s\n", argv[0]);

  /* file number */
  int fd = atoi(argv[1]);
  if (fd < 0) {
    exit(EXIT_FAILURE);
  }

  char buf[5] = { 0 };
  read(fd, buf, sizeof(buf));
  printf("[%d] %s\n", fd, buf);

  return EXIT_SUCCESS;
}
