#include <stdio.h>
#include <stdlib.h>

#include "source.h"

int main(int argc, char *argv[]) {
  for (int i = 0; i < argc; i++) {
    printf("%s\n", *(argv + i));
  }
  foo();
  
  malloc(1024 * sizeof(int));
 
  return EXIT_SUCCESS;
}
