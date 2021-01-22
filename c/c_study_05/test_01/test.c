#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  int x = 53191;
  
  char *p = (char *)&x;
  for (int i = 0; i < 4; ++i) {
    printf("%04x\n", *p);
    ++p;
  }
  
  return EXIT_SUCCESS;
}
