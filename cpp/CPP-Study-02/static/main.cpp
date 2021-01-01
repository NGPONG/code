#include <iostream>

#include "test.h"

int idx = 1024;

int main(void) {
  ++idx;
  foo();

  std::cout << "main.cpp: " << idx << std::endl;
  printf("0x%p\n", &idx);
  
  return EXIT_SUCCESS;
}
