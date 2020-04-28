#include <iostream>
using namespace std;

template<class T>
class Person {
public:
  friend void fun_test(Person<T> &per,T var) {
    cout << per.m_age + var << endl;
    cout << "Hello,World!" << endl;
  }

public:
  Person(T _age)
    : m_age(_age){};

public:
  T m_age;
};

int main(void) {
  Person<int> per(0x400);
  fun_test(per, 0x200);

  system("pause");
  return EXIT_SUCCESS;
}