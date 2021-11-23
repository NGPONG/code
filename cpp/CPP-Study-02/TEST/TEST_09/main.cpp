#include <iostream>

class BASE {
public:
  BASE() {
    std::cout << "BASE constructor" << std::endl;
  }
  ~BASE() {
    std::cout << "BASE destructor" << std::endl;
  }
  BASE(const BASE &b) {
    std::cout << "BASE copy constructor" << std::endl;
  }
  BASE(BASE &&b) {
    std::cout << "BASE move constructor" << std::endl;
  }

  int age;
};

BASE foo() {
  BASE b;
  b.age = 18;
  std::cout << b.age << std::endl;
  std::cout << &b << std::endl;

  return b;
}

int main(void) {
  BASE b = foo();
  std::cout << b.age << std::endl;
  std::cout << &b << std::endl;

  return -1;
}
