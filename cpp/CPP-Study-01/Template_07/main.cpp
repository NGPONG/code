#include <iostream>
using namespace std;

/** STEP 3
 * 由于 STEP 2 中使用了 Person<T>，但是 STEP 3 却定义在 Person<T> 之前，故还要在 STEP 2 之上为 Person<T> 做一次不完整类型的声明
 */
template<class T>
class Person;

/** STEP 2
 * 为模板类中的友元所修饰的声明构造一个即将链接到的定义，该行代码应该出现在 STEP 1 之上
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
   * 指定该声明使用空模板类型，目的是为了能够准确的链接到 STEP 2 中的模板定义
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