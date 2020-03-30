#include <iostream>
using namespace std;

#define SHORT_NAME       42
#define LONGER_NAME      0x007f
#define EVEN_LONGER_NAME (2)
#define foo(x)           (x * x)
#define bar(y, z)        (y + z)

class Person {
public:
  Person(int age, int gender, char *name) :
    m_age(age), m_gender(gender), m_name(name) {
    cout << "Person constructor" << endl;
  }

  void Print() {
    cout << this->m_age << endl;
    cout << this->m_name << endl;
    cpit << this->m_gender << endl;
  }

private:
  int m_age;
  int m_gender;
  char *m_name;
}

void fun_test(void) { }

int main(void) {

  system("pause");
  return EXIT_SUCCESS;
}