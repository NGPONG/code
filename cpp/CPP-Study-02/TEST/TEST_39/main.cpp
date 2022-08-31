#include <iostream>
#include <string>
#include <thread>

class BASE {
public:
  BASE() {
    std::cout << "BASE constructor: " << this << std::endl;
  }
  BASE(int32_t val) {
    std::cout << "BASE constructor" << std::endl;
  }
  ~BASE() {
    std::cout << "BASE destructor: " << this << std::endl;
  }
  BASE(const BASE& b) {
    std::cout << "BASE copy constructor" << std::endl;
  }
  BASE(BASE&& b) {
    std::cout << "BASE move constructor" << std::endl;
  }
  BASE &operator=(BASE &&per) {
    std::cout << "BASE move constructor(operator=)" << std::endl;
    return *this;
  }
  BASE &operator=(const BASE &per) {
    std::cout << "BASE copy constructor(operator=)" << std::endl;
    return *this;
  }
};

BASE foo() {
  if (true)
    return {};

  BASE b;
  return b;
}

int main(void) {
  BASE b = foo();
  return EXIT_SUCCESS;
}
