#include <iostream>
using namespace std;

class Person {

  friend ostream &operator<<(ostream &cout,const Person &per) {
    cout << per.m_age;
    return cout;
  }

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
  Person &operator++() {
    ++this->m_age;
    return *this;
  }

public:
  int m_age;
};

Person operator++(Person &per,int) {
  Person temp(per.m_age);
  ++per.m_age;
  return temp;
}


int main(void) {
  Person per(0x400);
  cout << per++ << endl;
  cout << per.m_age << endl;
  cout << ++per << endl;

  system("pause");
  return EXIT_SUCCESS;
}