#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  int i = 3;
  int y = 0;
  printf("%d\n", (y - i) >> 31);

  return EXIT_SUCCESS;
}
