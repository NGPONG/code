#include <stdio.h>
#include <stdlib.h>

#include "test.h"

int main(int argc, char *argv[]) {
  printf("main.c: %p\n", &idx);

  foo();

  return EXIT_SUCCESS;
}
