#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  int x = -49;
  printf("%d\n", !((!(x ^ (x & 0x37))) | (!(x ^ (x & 0x39)))));

  return EXIT_SUCCESS;
}
