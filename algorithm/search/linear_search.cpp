#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int foo(int *arrary, int key, int n) {
  for (size_t i = 0; i < n; ++i) {
    if(arrary[i] == key) {
      return i;
    }
  }
  return -1;
}

int main(void) {
  int arrary[] = { 1, 6, 3, 5, 9 };
  int idx = foo(arrary, 5, sizeof(arrary) / sizeof(int));

  system("pause");
  return EXIT_SUCCESS;
}
