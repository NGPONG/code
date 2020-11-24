#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

union object {
  short s;
  char c[sizeof(short)];
};

int main(int argc, char *argv[]) {
  union object obj;
  obj.s = 0x0102;

  if (obj.c[0] == 0x02) {
    printf("least significant digit\n");
  } else {
    printf("most significant digit\n");
  }
  

  return EXIT_SUCCESS;
}
