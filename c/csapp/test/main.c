#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  int x = 0x80000000;

  int is_negative = (x >> 31) & 1;
  int TMax = (1 << 31) + (~0);
  int is_positive = ((x + TMax) >> 31 & 1);
  
  int result = is_negative | is_positive;

  return EXIT_SUCCESS;
}
