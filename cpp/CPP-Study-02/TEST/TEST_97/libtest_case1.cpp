#include <iostream>

extern "C" {

std::int32_t g_val = 100;

void bar() {
  std::cout << "libtest_case1.cpp *g_val: " << g_val << std::endl;
  std::cout << "libtest_case1.cpp &g_val: " << &g_val << std::endl;
}

}

void fix() {
  std::cout << "libtest_case1.cpp" << std::endl;
}
