#include <iostream>

std::int32_t x = 100;
std::int32_t z = 2000;

extern "C" void foo() {
  std::cout << x << std::endl;
  std::cout << z << std::endl;
}
