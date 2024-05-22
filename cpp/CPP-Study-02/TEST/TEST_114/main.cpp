#include <iostream>
#include <string>

#include "test.hpp"

int main(int argc, char *argv[]) {
  BaseWrapper::foo();

  Base b;
  b.set_val(1111);
  // std::cout << b.val << std::endl;

  return 0;
}
