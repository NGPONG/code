#include <stdio.h>
#include "./header/test_1.h"
#include "./header/test_2.h"

void foo_1(void) {
  printf("hello,foo_1\n");
  foo_2();
  return;
}
