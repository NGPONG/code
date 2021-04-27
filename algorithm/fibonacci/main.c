#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

int fibonacci(unsigned int n) {
  if (n < 2) return n == 0 ? 0 : 1;

  return fibonacci(n - 1) + fibonacci(n - 2);
}

void foo_recursion(void) {
  for (int i = 0; i < 10; ++i) {
    printf("%d(%d)\n", fibonacci(i), i);
  }
}

void foo_unrecursion(void) {
  int arrary[10] = { 0 };
  arrary[0] = 0;
  arrary[1] = 1;

  for (size_t i = 2; i < 10; ++i) {
    arrary[i] = (arrary[i - 1]) + (arrary[i - 2]);
  }

  for (int i = 0; i < 10; ++i) {
    printf("%d(%d)\n", arrary[i], i);
  }
}

int main(void) {
  foo_recursion();
  foo_unrecursion();

  return EXIT_SUCCESS;
}
