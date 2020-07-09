#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int main(void) {

  char *str_src = "Hello,World!";

  int len = strlen(str_src);
  char str_des[len] = { 0 };

  strcpy_s(str_des, len + 1, str_src);

  printf("%s\n", str_des);

  system("pause");
  return EXIT_SUCCESS;
}