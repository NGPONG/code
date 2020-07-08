#include <stdio.h>
#include <stdlib.h>
#include "source.h"

int main(void) {
  printf("dynamic library test\n");
  int i = 0;
  while(1) {
    foo();
  }
  return EXIT_SUCCESS;
}
