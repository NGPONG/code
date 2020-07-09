#include <iostream>
using namespace std;

#include <string.h>

class Person {
  friend char *operator+(Person &&per, int num){
    per.m_age += num;
    return (char *)"SUCCESS!";
  }

public:
  Person(int age) {
    this->m_age = age;
  };
  Person(const Person &per) {
    this->m_age = per.m_age;
  }
  Person(Person &&per) {
    this->m_age = per.m_age;
    per.m_age = 0x0;
  }
  ~Person() {
    cout << "Person destructor" << endl;
  }

public:
  Person operator+(Person &per) {
    this->m_age += per.m_age;
    return *this;
  }

public:
  int m_age;
};

int main(void) {

  Person per_01 = Person(4);
  Person per_02 = Person(8);

  cout << ((per_01 + per_02) + 10) << endl;

  system("pause");
  return EXIT_SUCCESS;
}