#include <iostream>
using namespace std;

#include <string.h>

struct Student {

  int age;
}

class Person {

  friend ostream &operator<<(ostream &p_cout, Person per);

public:
  Person(int age, char *name = (char *)"DEFAULT") {
    this->m_age  = age;
    this->m_name = new char[strlen(name) + 1];
    strcpy(this->m_name, name);
  };
  Person(const Person &per) {
    this->m_age  = per.m_age;
    this->m_name = per.m_name;
  }
  ~Person() {
    cout << "Person destructor" << endl;
    delete[] this->m_name;
  }

  void fun_test(Person per) {
    cout << per.m_name << endl;
  }

private:
  int   m_age;
  char *m_name;
};

// ostream &operator<<(ostream &cout, Person *per) {
//   cout
// }

int main(void) {
  Person per(1024, (char *)"Hello,World");


  system("pause");
  return EXIT_SUCCESS;
}