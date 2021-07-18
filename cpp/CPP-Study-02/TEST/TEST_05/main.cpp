#include <iostream>
#include <vector>
#include <deque>

class BASE {
public:
  virtual void foo() {
    std::cout << "BASE foo" << std::endl;
    std::cout << *(int *)((char *)this + 8) << std::endl;
  }

  virtual ~BASE() {
    foo();
    std::cout << "BASE destructor" << std::endl;
  }
};

class CHILD : public BASE {
int var = 1024;

public:
  void foo() override {
    std::cout << "CHILD foo" << std::endl;
  }

  ~CHILD() override {
    std::cout << "CHILD destructor" << std::endl;
  }
};

int main(void) {
  BASE *b = new CHILD();
  b->foo();

  delete b;

  return EXIT_SUCCESS;
}
