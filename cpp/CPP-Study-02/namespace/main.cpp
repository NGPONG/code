#include <iostream>
using namespace std;

#include <string.h>

class Animal {
public:
  Animal() {
    cout << "animal constructor" << endl;
  }
  
  /* ���麯�� */
  virtual void speak() = 0;

  virtual ~Animal() {
    cout << "animal destructor" << endl;
  };
};

void foo(Animal &ani) {
  
}

int main(void) {
  Animal *animal;

  return EXIT_SUCCESS;
}