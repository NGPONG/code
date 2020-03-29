#include <iostream>
using namespace std;

class Person {

public:
  Person(int age, char *name) : m_age(age), m_name(name){};

  Person(const Person &person) {
    this->m_age = person.m_age;
    this->m_name = person.m_name;
  }

  ~Person() { 
    cout << "delete" << endl; 
  }

  void fun_test(const Person *per) { 
    ((Person)(*per)) + 10; 
  }

  void operator+(int num) { 
    cout << this->m_age + num << endl; 
  }

  int m_age;
  char *m_name;
};

int main(void) {

  Person per = Person(1024, (char *)"Hello,World");
  per.fun_test(&per);

  system("pause");
  return EXIT_SUCCESS;
}