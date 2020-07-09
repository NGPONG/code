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
  /* preload-value-increment assignment operator */
  Person &operator++() {
    ++this->m_age;
    return *this;
  }
  /** post-value-increment assignment operator
   * Argument of type int is a placeholder-argument, 
   * It's designed to tell the compiler this function 
   * is a post-value-increment assignment operator function.
   */
  Person operator++(int) {
    Person temp(this->m_age);
    ++this->m_age;
    return temp;
  }

public:
  int m_age;
};


int main(void) {
  Person per(0x400);
  cout << per++ << endl;
  cout << per.m_age << endl;
  cout << ++per << endl;

  system("pause");
  return EXIT_SUCCESS;
}