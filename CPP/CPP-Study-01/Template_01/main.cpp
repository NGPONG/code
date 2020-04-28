#include <iostream>
using namespace std;

template<typename T> 
void fun_test(T value) {
  value += 1;
  cout << value << endl;
}

class Person {
  friend ostream &operator<<(ostream &cout, Person &_per) {
    cout << _per.m_age;
    return cout;
  }

public:
  Person(int _age)
      : m_age(_age){
    cout << "PERSON(" << this << ") CONTSRUCTOR"<< endl;
  };
  Person(Person &&_per) {
    this->m_age = _per.m_age;
    _per.m_age = 0x0;

    cout << "PERSON(" << this << ") MOVE(" << &_per << ") CONSTRUCTOR" << endl;
  }
  ~Person() {
    cout << "PERSON(" << this << ") DESTRUCTOR" << endl;
  }

public:
  Person &operator+=(int num) {
    this->m_age += num;
    return *this;
  }

public:
  int m_age;
};

int main(void) {
  fun_test<Person>(Person(0x400));
  fun_test<int>(0x200);

  system("pause");
  return EXIT_SUCCESS;
}