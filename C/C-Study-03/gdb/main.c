#include <stdio.h>
#include <stdlib.h>

#include "source.h"

void test(int _arg_1,char _agr_2,double _arg_3) {
  
}

int main(int argc, char *argv[]) {
  for (int i = 0; i < argc; i++) {
    printf("%s\n", *(argv + i));
  }
  
  foo();
  
  malloc(1024 * sizeof(int));
 
  return EXIT_SUCCESS;
}
