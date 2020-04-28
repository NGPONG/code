#include <iostream>
using namespace std;

class Person {
  template<typename T>
  friend void fun_test_01(Person &per, T var) {
    cout << "FUN_TEST_01" << endl;
    cout << per.m_age + var << endl;
  }

  template<typename T>
  friend void fun_test_02(Person &per, T var) {
    cout << "FUN_TEST_02" << endl;
    cout << per.m_age + var << endl;
  }

  template<typename T>
  friend void fun_test_03(Person &per, T var);

public:
  Person(int _age)
    : m_age(_age){};

private:
  int m_age;
};

template<typename T>
void fun_test_02(Person &per, T var);

template<typename T>
void fun_test_03(Person &per, T var) {
  cout << "FUN_TEST_03" << endl;
  cout << per.m_age + var << endl;
}

int main(void) {
  Person per(0x400);

  /** 
   * 由于 fun_test_01 并没有在全局作用域下，故我们无法显示的指定该模板虚拟类型的具体类型，
   * 只能够依赖于参数录入所触发的隐式指定的机制来完成 
   */
  fun_test_01(per, 0x200);

  fun_test_02<int>(per, 0x200);

  fun_test_03<int>(per, 0x100);

  system("pause");
  return EXIT_SUCCESS;
}