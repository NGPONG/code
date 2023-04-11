#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  int32_t i = 0b10010101;
  i >>= 4;
  
  printf("%d\n", i);

  u_int32_t ui = 0b10010101;
  ui >>= 4;

  printf("%d\n", ui);

  return EXIT_SUCCESS;
}
