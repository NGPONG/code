#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

int main(void) {
  int a = 0x400;
  const int c_a = a;

  printf("%d\n",c_a);

  system("pause");
  return EXIT_SUCCESS;
}