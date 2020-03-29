#include <iostream>
using namespace std;

class Person {

public:
  Person(int age, char *name) : m_age(age), m_name(name){};

  Person(const Person &per) {
    this->m_age = per.m_age;
    this->m_name = per.m_name;
  }

  int m_age;
  char *m_name;
};

void operator<<(ostream *cout, Person &per) {
  *cout << "Person Age = "
        << per.m_age
        << endl
        << "Person Name = "
        << per.m_name
        << endl;
}

int main(void) {

  Person per = Person(1024, (char *)"NGPONG!");
  &cout << per;

  system("pause");
  return EXIT_SUCCESS;
}