#include <iostream>
using namespace std;

class Person {
public:
  Person(int age_) {
    this->m_age = age_;
  }
  ~Person() {
    this->m_age = 0x0;
  }

public:
  char *operator!=(Person &per_) {
    if (this->m_age == per_.m_age) {
      return (char *)"!=:SUCCESS!";
    } else {
      return (char *)"!=:FAILURE!";
    }
  }

public:
  int m_age;
};

bool operator==(Person &per_, int age_) {
  return per_.m_age == age_;
}

int main(void) {
  Person per_01(0x400);
  Person per_02(0x80);
  cout << (per_01 != per_02) << endl;

  if(per_01 == 0x400) {
    cout << "==:SUCCESS!" << endl;
  } else {
    cout << "==:FAILURE!" << endl;
  }


  system("pause");
  return EXIT_SUCCESS;
}