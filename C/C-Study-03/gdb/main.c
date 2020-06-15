#include <stdio.h>
#include <stdlib.h>

#include "source.h"

int main(int argc, char *argv[]) {
  foo();

  for (int i = 0; i < 10; ++i) {
    printf("Hello,NGPONG!");
  }

  return EXIT_SUCCESS;
}
