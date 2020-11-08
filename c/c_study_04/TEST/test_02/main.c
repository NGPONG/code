#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
  int *p = malloc(sizeof(int));

  printf("%p\n", p);
  printf("%p\n", &(*p));

  system("pause");
  return EXIT_SUCCESS;
}