#include <iostream>
#include <vector>
#include <deque>

class BASE {
public:
  virtual void foo() {
    std::cout << "BASE foo" << std::endl;
  }

private:
  ~BASE() {
    foo();
    std::cout << "BASE destructor" << std::endl;
  }
};

// class CHILD : public BASE {
// private:
//   void foo() override {
//     std::cout << "CHILD foo" << std::endl;
//   }

//   ~CHILD() override {
//     std::cout << "CHILD destructor" << std::endl;
//   }
// };

int main(void) {
  // BASE *b = new CHILD();
  // b->foo();
  // delete b;
  BASE *b = new BASE;
  delete b;

  return EXIT_SUCCESS;
}
