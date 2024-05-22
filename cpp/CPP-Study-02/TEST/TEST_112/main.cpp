#include <iostream>
#include <csignal>

class Animal {
public:
  Animal(std::int32_t _val) {
    _val += 2;
    val = _val;

    std::cout << "animal consructor" << std::endl;
  }

  virtual ~Animal() {
    std::cout << "animal destructor" << std::endl;
  }

  virtual void foo() {
    std::cout << "animal foo" << std::endl;
  }

  virtual void bar() {
    std::cout << "animal bar" << std::endl;
  }

  void bala() {
    std::cout << "animal bala" << std::endl;
  }

private:
  std::int32_t val;
};

class Cat : public Animal {
public:
  Cat(std::int32_t _val) : Animal(_val) {
    std::cout << "cat constructor" << std::endl;

    _val += 1;
    val = _val;
  }
  ~Cat() {
    std::cout << "cat destructor" << std::endl;
  }

  void foo() override {
    std::cout << "cat foo" << std::endl;
  }

private:
  std::int32_t val;
};

class Chausie : public Cat {
public:
  Chausie(std::int32_t _val) : Cat(_val) {
    _val += 4;
    val = _val;

    std::cout << "chausie constructor" << std::endl;
  }
  
  ~Chausie() {
    std::cout << "chausie destructor" << std::endl;
  }

  void foo() override {
    std::cout << "chausie foo" << std::endl;
  }

  void bar() override {
    std::cout << "chausie bar" << std::endl;
  }

private:
  std::int32_t val;
};


int main (int argc, char *argv[]) {
  // std::raise(SIGSTOP);

  Animal *ani = new Chausie(10);
  ani->foo();
  ani->bar();
  delete ani;

  Chausie *cha = new Chausie(29);
  cha->foo();
  cha->bar();
  delete cha;

  // // 0x5558e51cbeb0 -> 0x5558e3f1cd30(.data.rel.ro) -> 0x5558e3f1cd30
  // Animal *ani1 = new Animal(1);
  // ani1->foo();
  //
  // // 0x5558e51cc2e0 -> 0x5558e3f1cd10(.data.rel.ro) -> 0x5558e3f1a3f6
  // Animal *ani2 = new Dog(2);
  // ani2->foo();
  //
  // // 0x5558e51cc300 -> 0x5558e3f1ccf0(.data.rel.ro) -> 0x5558e3f1ccf0
  // Animal *ani3 = new Cat(3);
  // ani3->foo();

  return 0;
}
