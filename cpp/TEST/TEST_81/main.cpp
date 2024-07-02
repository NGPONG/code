#include <iostream>

std::string&& foo() {
  return "hello,world";
}

int32_t main(void) {
  std::string str = foo();

  for (int i = 0; i < 10; ++i) {
    std::cout << str << std::endl;
  }

  return 0;
}
