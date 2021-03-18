#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  int x = 0x400;
  int y = 1;
  int z = 2;

  int *arr[3] = { &x, &y, &z };
  
  int **p_x = &arr[0];
  
  printf("%d\n", **(p_x + 1));

  return EXIT_SUCCESS;
}
