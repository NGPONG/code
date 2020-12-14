#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Test {
  int a;
  char b;
  short c;
};

int main(int argc, char *argv[]) {
  /* printf("%d\n", sizeof(struct Test)); */
  /* struct Test te;                      */
  /* printf("%d\n", sizeof(te));          */

  struct Test *te = NULL;
  printf("%p\n", &te->a);
  printf("%p\n", &te->b);
  printf("%p\n", &te->c);

  return EXIT_SUCCESS;
}
