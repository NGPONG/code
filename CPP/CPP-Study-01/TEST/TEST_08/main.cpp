#include <iostream>
using namespace std;

class Person {
public:
  Person(int age) {
    this->m_age = age;
  }
  Person(const Person &per) {
    this->m_age = per.m_age;
  }
  Person(Person &&per) {
    this->m_age = per.m_age;
    per.m_age = 0x0;
  }
  ~Person() {}

public:
  int m_age;
};

Person test_01(void) {
  Person per(0x400);
  return per;
}


int main(void) {
  test_01();

  Person &&per_02 = test_01();

  system("pause");
  return EXIT_SUCCESS;
}