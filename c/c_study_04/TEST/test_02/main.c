#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct S {
  unsigned int a : 3;
  unsigned int b : 9;
  /* unsigned int c : 16; */
  /* unsigned int d : 32; */
  unsigned char e;
};

int main(void) {
  struct S *s = 0x0;
  printf("%p\n", &s->e);

  system("pause");
  return EXIT_SUCCESS;
}
