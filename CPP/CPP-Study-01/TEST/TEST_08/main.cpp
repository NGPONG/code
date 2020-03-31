#include <iostream>
using namespace std;

struct Person {
  friend void operator+(Person &per_01, char age) {
    per_01.m_age += age;
    return;
  };

public:
  Person(int age)
      : m_age(age) {}

  Person(const Person &per) {
    this->m_age = per.m_age;
  }
  ~Person() {
    cout << "Person descturctor" << endl;
  }

  Person &operator+(int age) {
    this->m_age += age;
    return *this;
  }

public:
  int m_age;
};

int main(void) {

  Person per_01(0);
  Person per_02(256);
  per_01 + 1 + 2;

  system("pause");
  return EXIT_SUCCESS;
}