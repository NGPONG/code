#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

void foo(void) {
  printf("Hello,world!\n");
}

int main(void) {
  void (*ptr)(void) = (void (*)(void))0;
  ptr();

  system("pause");
  return EXIT_SUCCESS;
}