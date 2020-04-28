#include <iostream>
using namespace std;

template<class T>
class Person {
public:
  Person(T _age)
      : m_age(_age) {
    cout << "PERSON CONSTRUCTOR" << endl;
  };

public:
  T m_age;
};

template<class T1, class T2>
class Student : public Person<T2> {
public:
  Student(T1 _name, T2 _age)
      : Person<T2>(_age), m_name(_name) {
    cout << "STUDENT CONSTRUCTOR" << endl;
  };

public:
  void fun_test();

public:
  T1 m_name;
};

template<class T1, class T2>
void Student<T1, T2>::fun_test() {
  cout << this->m_age << endl;
  cout << this->m_name << endl;
}

int main(void) {
  /* char *name = (char *)"Hello,World!";
  int age = 24;

  Student<char *, int> stu(name, age);
  stu.funB_test(); */

  Person<int> *per = new Student<char *, int>((char *)"NGPONG", 0x400);
  cout << per->m_age << endl;

  system("pause");
  return EXIT_SUCCESS;
}