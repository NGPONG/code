#include <stdio.h>

#include "test.h"

int idx = 0x200;

void foo() {
  printf("test.c: %p\n", &idx);
}
