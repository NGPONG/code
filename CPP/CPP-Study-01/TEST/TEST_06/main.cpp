#include <iostream>
using namespace std;

#pragma region CLASS_TEST
class Student {
public:
  Student(int age) {
    this->m_age       = age;
    Student::m_gender = 256;
  }
  static void Print() {
    cout << Student::m_gender << endl;
  }

public:
  int m_age;

private:
  static int m_gender;
};

int Student::m_gender;
#pragma endregion

struct Person {

  friend Person &operator+(Person &per_host, int age_plus) {
    per_host.m_age += age_plus;
    return per_host;
  };

public:
  Person(int age) {
    this->m_age = age;
  }
  Person(const Person &per) {
    cout << this->m_age << endl;
    this->m_age = per.m_age;
    cout << per.m_age << endl;
  }
  // Person &operator+(int age_plus) {
  //   this->m_age += age_plus;
  //   return *this;
  // }
  ~Person() {
    cout << "Person destructor" << endl;
  }

public:
  int m_age;
};

int &fun_test(int &a) {
  a += 256;
  return a;
}

int main(void) {
  Person per(1024);

  per + 1;

  cout << per.m_age << endl;

  system("pause");
  return EXIT_SUCCESS;
}