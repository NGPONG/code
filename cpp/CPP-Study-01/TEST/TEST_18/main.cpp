#include <iostream>
using namespace std;

#include <list>
#include <vector>
#include <algorithm>
#include <functional>

class Person {
public:
  Person(int _age)
    : m_age(_age){};

public:
  void speak(void) {
    cout << "PERSON AGE = " << this->m_age << endl;
  };
  void eat(string food) {
    cout << "PERSON EAT " << food << endl;
  }

public:
  int m_age;
};

bool fun_test(Person &_left, Person &_right) {
  return _left.m_age > _right.m_age;
}

void foo(void) {
  vector<Person> __v;
  __v.push_back(Person(3));
  __v.push_back(Person(5));
  __v.push_back(Person(2));
  __v.push_back(Person(4));
  __v.push_back(Person(1));

  sort(__v.begin(), __v.end(), &fun_test);

  for_each(__v.begin(), __v.end(), mem_fun_ref(Person::speak));
  /* for_each(__v.begin(), __v.end(), [](Person &_val) { _val.speak(); }); */
}

void test(void) {
/*   void (Person::*speak)(void) = &Person::speak;

  Person per(0x400);
  (per.*speak)(); */
/*   Person per(0x200);
  (bind2nd(mem_fun_ref(&Person::eat), "GGGG"))(per); */


  Person per(0x400);
  void (Person::*invoker)(void) = per.speak;
}

int main(void) {
  /* foo(); */
  test();

  system("pause");
  return EXIT_SUCCESS;
}