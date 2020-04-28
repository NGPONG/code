#include <iostream>
using namespace std;

class Person {
  friend void fun_test(void) {
    cout << "HELLO,WORLD!" << endl;
  }

  friend void fun_test_01(Person *per,int var) {
    cout << var << endl;
  }

public:
  Person(int _age)
    : m_age(_age) {
    cout << "Hello,World!" << endl;
  };

public:
  int m_age;
};

int main(void) {
  Person per(0x400);

  fun_test_01(&per,0x400);

  system("pause");
  return EXIT_SUCCESS;
}