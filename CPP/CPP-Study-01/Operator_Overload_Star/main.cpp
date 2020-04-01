#include <iostream>
using namespace std;

class Person {
public:
  Person(int age, char *name) {
    this->m_age = age;
    this->m_name = name;
  }

public:
  void Print() {
    cout << "Person age = " << this->m_age << endl;
    cout << "Person name = " << this->m_name << endl;
  }

private:
  int m_age;
  char *m_name;
};

class SmartPointer {
public:
  SmartPointer(Person *ptr) {
    this->m_ptr = ptr;
  };
  ~SmartPointer() {
    delete this->m_ptr;
  }

public:
  Person &operator*() {
    return *this->m_ptr;
  }
  Person *operator->() {
    return this->m_ptr;
  }

public:
  Person *m_ptr;
};

int main(void) {
  SmartPointer sp(new Person(1024, (char *)"Person"));
  (*sp).Print();
  sp->Print();

  system("pause");
  return EXIT_SUCCESS;
}