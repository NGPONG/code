#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int func(int a) {
  if (a == 1)
    return 1;
  else
    return a + func(a - 1);
}

int main(int argc, char *argv[]) {
  char str[1024] = { 0 };

  for (int i = 0; i < 1023; ++i) {
    str[i] = 'a';
  }

  printf("%s\n", str);

  return 0;
}
