#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
  FILE *f_read = fopen("/home/ngpong/code/C/C-Study-03/file_01/test.txt", "r");
  if (f_read == NULL) {
    perror("E");
    return EXIT_FAILURE;
  }
  printf("fp = %p\n", f_read);

  char *str = malloc(sizeof(char) * 0x400);
  if (str == NULL) {
    perror("heap error!");
  }
  printf("str = %p\n", str);

  while (!feof(f_read)) {
    fgets(str, sizeof(char) * 0x400, f_read);
    printf("%s", str);
    memset(str, 0x0, sizeof(char) * 0x400);
  }

  fclose(f_read);
  printf("free %p\n", f_read);
  free(str);
  printf("free %p\n", str);
  return EXIT_SUCCESS;
}
