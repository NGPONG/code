#include <iostream>
using namespace std;

#include <string.h>

class Person {
public:
  Person() {
    this->m_age = 0x0;
  }
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
  ~Person() {
    cout << "Person destructor" << endl;
  }

  Person &operator=(const Person &per) {
    this->m_age = per.m_age;
    return *this;
  }

/*   Person &operator=(Person &&per) {
    this->m_age = per.m_age;
    this->m_name = per.m_name;

    delete[] per.m_name;
    per.m_age = 0x0;

    return *this;
  } */


private:
  int m_age;
/*   char *m_name = nullptr; */
};

class TEST {
public:
  TEST(Person per) {
    this->per = per;
  }

public:
  Person per;
};

int
main(void) {

  int a = 10;
  cout << &a << endl;
  cout << &(a = a + 1) << endl;


  system("pause");
  return EXIT_SUCCESS;
}