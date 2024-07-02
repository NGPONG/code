#include <iostream>

template<class T>
class Animal {
public:
  static void foo();
};

class Dog {
};

class Cat {
};

template<>
void Animal<Dog>::foo() {
  std::cout << "dog say" << std::endl;
}

template<>
void Animal<Cat>::foo() {
  std::cout << "cat say" << std::endl;
} 

int main (int argc, char *argv[]) {
  Animal<Dog> an;
  an.foo();
  Animal<Dog>::foo();

  Animal<Cat> an2;
  an2.foo();

  Animal<Cat>::foo();

  return 0;
}
