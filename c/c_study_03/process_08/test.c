#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  int fd = open("./log", O_WRONLY | O_CREAT, 0666);

  return EXIT_SUCCESS;
}
