#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>
#include <functional>
#include <memory>

class BASE {
public:
  BASE() {
    std::cout << "BASE constructor: " << this << std::endl;
  }

  ~BASE() {
    std::cout << "BASE destructor: " << this << std::endl;
  }
  BASE(const BASE& b) {
    std::cout << "BASE copy constructor, copy " << &b << " to " << this << std::endl;
  }
  BASE(BASE&& b) {
    std::cout << "BASE move constructor, move " << &b << " to " << this << std::endl;
  }
  BASE &operator=(BASE &&per) {
    std::cout << "BASE move constructor(operator=)" << std::endl;
    return *this;
  }
  BASE &operator=(const BASE &per) {
    std::cout << "BASE copy constructor(operator=)" << std::endl;
    return *this;
  }

  void hello() {
    std::cout << "hello,world!" << std::endl;
  }
};

void bar(const std::vector<std::function<void(void)>>& v) {
  for (auto& func : v) {
    func();
  }
}

std::function<void(void)> foo() {
  auto b = std::make_shared<BASE>();

  return [=] () {
    b->hello();
  };
}

void foo_2(std::function<void(void)>&& fuc) {
  bar({fuc});

  std::cout << "after call bar()" << std::endl;
}

void foo_1(std::function<void(void)>&& fuc) {
  foo_2(std::move(fuc));

  std::cout << "after call foo_2()" << std::endl;
}

void fooo(const BASE b) {
  std::cout << "haha" << std::endl;
}

int main(void) {
  // foo_2(foo());

  // std::cout << "after call foo_1()" << std::endl;

  BASE b;
  fooo(b);

  std::cout << "aa" << std::endl;

  return EXIT_SUCCESS;
}

