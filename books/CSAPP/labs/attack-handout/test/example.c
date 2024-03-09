#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void foo_1(void) {
  srand(time(NULL));

  unsigned cookie = 0x59b997fa;
  char *sval = "59b997fa";

  char cbuf[110] = { 0 };
  char *s = cbuf + rand() % 100;

  sprintf(s, "%.8x", cookie);

  int flag = strncmp(sval, s, 7) == 0;

  printf("sval = %s\n", sval);
  printf("s = %s\n", s);

  printf("flag = %d\n", flag);
}

void foo_2(void) {
  char *src = "59b997fa";
  char *dst = "59b997fa";
}

int main(int argc, char *argv[]) {
  char *str = "59b997fa";
  printf("%s\n", str);

  return EXIT_SUCCESS;
}
