#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  int i = 0x400;
  unsigned char *p = (unsigned char *)&i;
  
  printf("%d\n", (size_t)p);
  
  return EXIT_SUCCESS;
}
