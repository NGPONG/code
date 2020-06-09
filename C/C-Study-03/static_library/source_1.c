#include <stdio.h>
#include "./headr/test.h"

void foo_1(void) {
  printf("hello,foo_1\n");
  foo_2();
  return;
}
