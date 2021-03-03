#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int x = 0x7FFFFFFF;

  int sign = (x >> 31) & 1;
  int cond = (sign << 0x1F) >> 0x1F;
  x = (cond & ~x) | (~cond & x);

  return EXIT_SUCCESS;
}
