#include <iostream>
#include <string>
#include <thread>

class BASE {
public:
  BASE() {
    std::cout << "BASE constructor" << std::endl;
  }
  BASE(int32_t val) {
    std::cout << "BASE constructor" << std::endl;
  }
  ~BASE() {
    std::cout << "BASE destructor" << std::endl;
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

BASE gb;

BASE TEST() {
  return std::move(gb);
}

BASE foo() {
  if (false)
    return {};

  return TEST();
}

int main(void) {
  BASE b = foo();

  sleep(2000);
  return EXIT_SUCCESS;
}
