#include <iostream>
using namespace std;

class Person {
public:
  Person(int age, char *name) {
    this->m_age = age;
    this->m_name = name;
  }

public:
  void Print() {
    cout << "Person age = " << this->m_age << endl;
    cout << "Person name = " << this->m_name << endl;
  }

private:
  int m_age;
  char *m_name;
};

class SmartPointer {
public:
  SmartPointer(Person *ptr) {
    this->m_ptr = ptr;
  };
  ~SmartPointer() {
    delete this->m_ptr;
    this->m_ptr = nullptr;
  }

public:
  /** '*' assginment operator
   * 1. 运算符 '*' 是一个一元运算符，故声明在复合类型内部的运算符重载函数无需形参 ('*' 所构成的运算符表达式从左至右的第一个参数即为当前 复合类型 的实例)，
   */
  Person &operator*() {
    return *this->m_ptr;
  }

  /** '->' assignment operator
   * 1. 运算符 '->' 是一个一元运算符，故声明在复合类型内部的运算符重载函数无需形参 ('->' 所构成的运算符表达式从左至右的第一个参数即为当前 复合类型 的实例)
   * 2. '->' 虽然是一个一元符，但是它却不支持单独使用，即他所构造出来的表达式在之后往往需要承接着对于另一方的调用才能够通过编译
   * 3. '->' 重载运算符函数只能够作为一个成员函数而存在
   * 4. '->' 的返回值问题要么返回一个裸指针，要么（按引用或值）返回同样重载了运算符 -> 的对象，由于其返回值的限制还有 '->' 无法单独使用的特性，意味着我们使用 '->' 所构成的表达式在映射到对应的函数调用完毕并且返回相应的值后，我们还要承接着一次 '->' 的调用，意味着实际要调用的表达式需要有两次 '->' 操作符的使用 '->->' 但是编译器会帮我省去后一次 '->'
   */
  Person *operator->() {
    return *this->m_ptr;
  }

public:
  Person *m_ptr;
};

int main(void) {
  SmartPointer sp(new Person(1024, (char *)"Person"));
  (*sp).Print();
  sp->Print();

  Person &per_ref = *sp;
  per_ref.Print();

  /* faild */
  /* Person *per = sp->; */

  system("pause");
  return EXIT_SUCCESS;
}