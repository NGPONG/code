#include <iostream>

std::int32_t g_val = 1024;

extern "C" void foo() {
  std::cout << g_val << std::endl;
}
