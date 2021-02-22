#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  int i = 0x80000000;
  printf("%d\n", i * -1);

  return EXIT_SUCCESS;
}
