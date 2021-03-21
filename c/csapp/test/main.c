#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  char *str = "1 2 hello,world";

  int d1 = 0;
  int d2 = 0;
  char buf[64] = { 0 };
  int nums = sscanf(str, "%d %d %s", &d1, &d2, buf);
  
  return EXIT_SUCCESS;
}
