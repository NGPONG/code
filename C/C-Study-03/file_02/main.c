#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
  int _fd = open("test", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
  if (_fd == -1) {
    perror("E");
    return EXIT_FAILURE;
  }

  close(_fd);

  return EXIT_SUCCESS;
}
