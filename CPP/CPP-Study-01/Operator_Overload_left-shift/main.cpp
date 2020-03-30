#include <iostream>
using namespace std;

#include <string.h>

class Person {

  friend ostream &operator<<(ostream &cout, Person *per) {
    cout << "Person name = " << per->m_name << " ,Person age  = " << per->m_age;
    return cout;
  }

public:
  Person(int age, char *name = (char *)"DEFAULT") {
    this->m_age  = age;
    this->m_name = new char[strlen(name) + 1];
    strcpy(this->m_name, name);
  }
  Person(const Person &per) {
    this->m_age  = per.m_age;
    this->m_name = per.m_name;
  }
  ~Person() {
    cout << "Person destructor" << endl;
    delete[] this->m_name;
  }

  void fun_test_01(void) {
    cout << "Hello,World!" << endl;
  }

public:
  ostream &operator<<(ostream &cout) {
    cout << "Person name = " << this->m_name << " ,Person age  = " << this->m_age;
    return cout;
  }

private:
  int   m_age;
  char *m_name;
};

int main(void) {
  Person per_01(1024, (char *)"Hello,World!");
  Person per_02(256, (char *)"NGPONG!");

  per_01 << cout
         << endl
         << &per_02
         << endl;

  system("pause");
  return EXIT_SUCCESS;
}