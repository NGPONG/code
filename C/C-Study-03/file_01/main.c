#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
  FILE *f_read = fopen("./text", "w");
  if (f_read == NULL) {
    perror("open file error");
  }

  char *str = malloc(sizeof(char) * 0x400);
  if (str == NULL) {
    perror("heap error!");
  }

  while (feof(f_read)) {
    fgets(str, 0x400, f_read);
    printf("%s\n", str);

    memset(str, 0x0, sizeof(char) * 0x400);
  }

  fclose(f_read);
  free(str);
  return EXIT_SUCCESS;
}
