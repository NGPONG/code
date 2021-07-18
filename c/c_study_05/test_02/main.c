#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void fun_1() {
  int i = 10;
  i += 1024;

  int *p = NULL;
  *p = i;

  printf("%d\n", *p);
}

int main(int argc, char *argv[]) {
  fun_1();
  
  return EXIT_SUCCESS;
}
