#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  int x = 0x80000000;
  int y = !x;

  return EXIT_SUCCESS;
}
