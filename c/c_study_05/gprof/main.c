#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void foo_01() {
  int idx = 0;
  for (int i = 0; i < 0x40000000; ++i) {
    idx += i;
  }
}

int main(int argc, char *argv[]) {
  for (int i = 0; i < 10; ++i) {
    foo_01();
  }

  return EXIT_SUCCESS;
}
