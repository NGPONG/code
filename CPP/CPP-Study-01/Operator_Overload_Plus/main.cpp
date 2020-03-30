#include <iostream>
using namespace std;

#include <string.h>

class Person {
public:
  Person(int age, char *name) {
    this->m_age = age;
    this->m_name = new char[strlen(name) + 1];
    strcpy(this->m_name, name);
  };
  Person(const Person &per) {
    this->m_age = per.m_age;
    this->m_name = new char[strlen(per.m_name) + 1];
    strcpy(this->m_name, per.m_name);
  }
  ~Person() {
    printf("delete %p", this->m_name);
    delete[] this->m_name;
  }

public:
  Person operator+(Person &per) {
    Person per_temp = Person(per.m_age + this->m_age, (char *)"DEFAULT");
    return per_temp;
  }

public:
  int m_age;
  char *m_name;
};

/*
Person operator+(Person &per_01, Person &per_02) {
  Person per_temp = Person(per_01.m_age + per_02.m_age, (char *)"DEFAULT");
  return per_temp;
}
*/

int main(void) {

  Person per_01 = Person(4, (char *)"NGPONG");
  Person per_02 = Person(8, (char *)"Hello,World!");

  

  Person per_03 = per_01 + per_02;

  system("pause");
  return EXIT_SUCCESS;
}