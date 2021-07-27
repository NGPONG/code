#include <iostream>
#include <exception>

class base {
public:
  int num;

  base(int _num) {
    this->num = _num;
    std::cout << "constructor" << std::endl;
  }

  base(const base &b) {
    this->num = b.num;
    std::cout << "copy constructor" << std::endl;
  }

  base(base &&b) {
    this->num = b.num;
    std::cout << "move constructor" << std::endl;
  }

  ~base() {
    std::cout << "destructor" << std::endl;
  }
};

base foo(void) {
  int num = 0;
  for (int i = 0; i < 10; ++i) {
    num += i;
  }

  num *= 10;

  base b(num);
  std::cout << &b << std::endl;

  return b;
}

void test() {
  base b = foo();
  std::cout << &b << std::endl;

  for (int i = 0; i < 10; ++i) {
    std::cout << b.num << std::endl;
  }
}

int main(void) {
  test();

  return EXIT_SUCCESS;
}
