#include <iostream>
using namespace std;

#include <string.h>

class Animal {
public:
  Animal(int _age)
    : a_age(_age) {
    cout << "ANIMAL CONSTRUCTOR" << endl;
  }
  ~Animal() {
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
  ~Cat() {
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
  ~HEITAN() {
    cout << "HEITAN DESTRUCTOR" << endl;
  }
};

int main(void) {
  Animal animal = HEITAN(1, (char *)"heitan");

  return EXIT_SUCCESS;
}
