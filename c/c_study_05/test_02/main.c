#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  int a[3][2] = 
  { 
    {1, 2},
    {3, 4},
    {5, 6} 
  };

  int *p = a[1];
  for (int i = 0; i < 2; ++i) {
    printf("%d\n", *p);
    ++p;
  }

  return EXIT_SUCCESS;
}
