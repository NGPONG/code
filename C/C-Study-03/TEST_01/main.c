#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *str = malloc(sizeof(char) * 0x400);

  fscanf(stdin, "%s\n", str);
  fprintf(stdout, "%s", str);

  return EXIT_SUCCESS;
}
