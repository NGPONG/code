#include <iostream>
using namespace std;

#include <string.h>

class Person {
  // friend Person &operator+(const Person &per, int num){
  //   return (Person &)per;
  // }

public:
  Person(int age, char *name) {
    this->m_age = age;
  };
  Person(const Person &per) {
    this->m_age = per.m_age;
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

  Person per_01 = Person(4, (char *)"NGPONG");
  Person per_02 = Person(8, (char *)"Hello,World");

  Person per = per_01 + per_02;

  system("pause");
  return EXIT_SUCCESS;
}