#include <iostream>

std::int32_t x = 20;

void __attribute ((constructor)) init_function(void) {
  x = 100;
}

void __attribute ((destructor)) fini_function(void) {
  x = 0;
}

void foo(std::int32_t val) {
  std::cout << x << std::endl;
}
