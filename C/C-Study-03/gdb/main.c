#include <stdio.h>
#include <stdlib.h>

#include "source.h"

int main(int argc, char *argv[]) {
  for (int i = 0; i < argc; i++) {
    printf("%s\n", *(argv + i));
  }

  foo();
  return EXIT_SUCCESS;
}
