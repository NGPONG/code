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
   * ���� fun_test_01 ��û����ȫ���������£��������޷���ʾ��ָ����ģ���������͵ľ������ͣ�
   * ֻ�ܹ������ڲ���¼������������ʽָ���Ļ�������� 
   */
  fun_test_01(per, 0x200);

  fun_test_02<int>(per, 0x200);

  fun_test_03<int>(per, 0x100);

  system("pause");
  return EXIT_SUCCESS;
}