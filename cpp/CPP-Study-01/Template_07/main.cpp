#include <iostream>
using namespace std;

/** STEP 3
 * ���� STEP 2 ��ʹ���� Person<T>������ STEP 3 ȴ������ Person<T> ֮ǰ���ʻ�Ҫ�� STEP 2 ֮��Ϊ Person<T> ��һ�β��������͵�����
 */
template<class T>
class Person;

/** STEP 2
 * Ϊģ�����е���Ԫ�����ε���������һ���������ӵ��Ķ��壬���д���Ӧ�ó����� STEP 1 ֮��
 */
template<typename T>
void fun_test(Person<T> &per,T var) {
  cout << "FUN_TEST" << endl;
  cout << per.m_age + var << endl;
}

template<class T>
class Person {
public:
  /** STEP 1
   * ָ��������ʹ�ÿ�ģ�����ͣ�Ŀ����Ϊ���ܹ�׼ȷ�����ӵ� STEP 2 �е�ģ�嶨��
   */
  friend void fun_test<>(Person<T> &per, T var);

public:
  Person(T _age)
    : m_age(_age) {};

private:
  T m_age;
};

int main(void) {
  Person<int> per_int(0x400);
  fun_test(per_int, 0x400);

  system("pause");
  return EXIT_SUCCESS;
}