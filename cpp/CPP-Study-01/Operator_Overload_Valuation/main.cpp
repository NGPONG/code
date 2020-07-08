#include <iostream>
using namespace std;

class Person {
public:
  Person(int age) {
    this->m_age = age;
  }
  ~Person() {
    this->m_age = 0x0;
  }

public:
  /** Valuation assignment operator
   * 1. '=' 重载运算符函数只能够作为一个成员函数而存在
   * 2. '=' 重载运算符函数通常用于构成移动语义和拷贝语义，不细谈
   */

  /* Person copy assignment operator */
  Person &operator=(const Person &per) {
    this->m_age = per.m_age;
    return *this;
  }
  /* Person move assignment operator */
  Person &operator=(Person &&per) {
    this->m_age = per.m_age;
    per.m_age = 0x0;
    return *this;
  }
  /* Person assignment operator */
  Person &operator=(int age) {
    this->m_age = age;
    return *this;
  }

public:
  int m_age;
};

int main(void) {
  Person per_a(0);
  Person per_b(0);

  /** TODO
   * 
   * 1. 0x400 create a temporary unnamed variable, m_age is 0x400
   * 
   * 2. Person(0) create a temporary unnamed variable, m_age is 0, 
   * Then call the move assignment operator function to move the data 0x400 to Person(0)
   * 
   * 3. Call copy assignment operator to copy (Person(0) = 0x400) 
   * data to per_a Because of move assignment operator function return value type is lvalue
   * 
   * 4. Call copy assignment operator to copy per_a data to per_b Because of per_a is lvalue
   * 
   */
  Person &per_b_ref = per_b = per_a = Person(0) = 0x400;

  per_b_ref = 0x100;

  cout << per_b_ref.m_age << endl;

  system("pause");
  return EXIT_SUCCESS;
}