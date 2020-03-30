#include <iostream>
using namespace std;

#include <string.h>

class Person {
public:
  Person(int age, char *name = (char *)"DEFAULT") {
    this->m_age  = age;
    this->m_name = NULL;

    if (name != NULL) {
      this->m_name = new char[strlen(name) + 1];
      strcpy(this->m_name, name);
    }
  };

  Person(const Person &per) {
    this->m_age  = per.m_age;
    this->m_name = per.m_name;
  }
  ~Person() {
    cout << "Person destructor" << endl;
  }

private:
  int   m_age;
  char *m_name;
};

// ostream &operator<<(ostream &cout, Person *per) {
//   cout
// }

namespace Foo {}

int main(void) {
  Person per(1024, (char *)"Hello,World");
  per = Person(256);

  system("pause");
  return EXIT_SUCCESS;
}