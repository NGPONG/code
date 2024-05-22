#include <iostream>
#include <memory>

class A {
public:
  virtual ~A() = 0;
};

A::~A() {
  std::cout << "A destructor" << std::endl;
}

class B : public A {
public:
  virtual ~B() {
    std::cout << "B destructor" << std::endl;
  }
};

int main (int argc, char *argv[]) {
  A *ap = new B();
  delete ap;

  A &ar = *(new B());
  delete &ar;

  return 0;
}
