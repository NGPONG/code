#include <stdio.h>
#include "source.h"

void foo() {
  int _val = 0x400;

  int *p = &_val;
  ++(*p);

  printf("source value = %d\n",*p);

  return;
}

