#include <stdio.h>
#include <stdlib.h>

#include "test.h"

int main(int argc, char *argv[]) {
  int arrary[3] = { 1,2,3 };
	int (*p_arrary)[3] = arrary;

  printf("main.c: %p\n", &idx);

  foo();

  return EXIT_SUCCESS;
}
