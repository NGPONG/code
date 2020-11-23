#include <iostream>
using namespace std;

class TEST {
public:
  const char *name;
  TEST(const char *_name) : name(_name) {}

  bool m_foo(int _val) {   
    cout << _val << endl;
    cout << this->name << endl;
  }
};

void foo() {
  /* 通过一个实例的依赖去获取成员函数在内存中的地址 */
  TEST __t("hello,world");
  bool (TEST::*invoker_instance)(int) = __t.m_foo;

  (__t.*invoker_instance)(10);

  /* 通过 :: 操作符去引用至具体某个类型下并拿到成员函数的名字同样也可以用作获取成员函数地址的一种方式 */
  bool (TEST::*invoker_none)(int) = TEST::m_foo;
  (__t.*invoker_none)(10);
}
int main(void) {
  foo();

  return EXIT_SUCCESS;
}