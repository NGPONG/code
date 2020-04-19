#include <iostream>
using namespace std;

#include <string.h>

/* class Animal {
public:
  Animal(int _age)
      : a_age(_age) {
    cout << "ANIMAL CONSTRUCTOR" << endl;
  }

  virtual ~Animal() {
    cout << "ANIMAL DESCRTUCTOR" << endl;
  }

public:
  virtual void speak() {
    cout << "ANIMAL SPEACKING!" << endl;
    cout << "AGE:" << this->a_age << endl;
  };

public:
  int a_age;
};

class Cat : public Animal {
public:
  Cat(int _age, char *_name)
      : Animal(_age) {
    cout << "CAT CONSTRUCTOR" << endl;
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
  }

  ~Cat() {
    cout << "CAT DESTRUCTOR" << endl;
    delete[] this->name;
  }

public:
  void speak() override {
    cout << "CAT SPEAKING" << endl;
  }

public:
  char *name = nullptr;
};

class HEITAN : public Cat {
public:
  HEITAN(int _age, char *name)
      : Cat(_age, name) {
    cout << "HEITAN CONSTRUCTOR" << endl;
  }

  ~HEITAN() {
    cout << "HEITAN DESTRUCTOR" << endl;
  }

public:
  void speak() override {
    cout << "HEITAN SPEAKING" << endl;
  }
}; */


class Animal {
public:
  Animal(int _age)
      : a_age(_age) {
    cout << "ANIMAL CONSTRUCTOR" << endl;
  }
  virtual ~Animal() {
    cout << "ANIMAL DESCRTUCTOR" << endl;
  }

public:
  int a_age;
};

class Cat : public Animal {
public:
  Cat(int _age, char *_name)
      : Animal(_age) {
    cout << "CAT CONSTRUCTOR" << endl;
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
  }
  ~Cat() override {
    cout << "CAT DESTRUCTOR" << endl;
    delete[] this->name;
  }

public:
  char *name = nullptr;
};

class HEITAN : public Cat {
public:
  HEITAN(int _age, char *name)
      : Cat(_age, name) {
    cout << "HEITAN CONSTRUCTOR" << endl;
  }
  ~HEITAN() override {
    cout << "HEITAN DESTRUCTOR" << endl;
  }
};

void fun_test() {
  Animal *heitan = new HEITAN(0x400, (char *)"Hello,World!");
  delete heitan;
}


int main(void) {
  fun_test();

  return EXIT_SUCCESS;
}