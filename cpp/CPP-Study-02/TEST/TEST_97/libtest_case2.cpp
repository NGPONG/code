
#include <iostream>

extern "C" {

std::int32_t g_val = 200;

void bar() {
  std::cout << "test2.cpp g_val: " << g_val << std::endl;
  std::cout << "test2.cpp &g_val: " << &g_val << std::endl;
}

}

void fix() { }
