#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  char *str = "hello,world";

  int flag = isblank(str[3]);
  if (flag) { 
    printf("is blank");
  } else {
    printf("correct!");
  }

  return 0;
}
