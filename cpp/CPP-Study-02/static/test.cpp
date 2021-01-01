#include <iostream>

#include "test.h"

void foo(void) {
  std::cout << "test.cpp: " << idx << std::endl;
  printf("0x%p\n", &idx);
}
