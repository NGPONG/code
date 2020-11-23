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
  /* ͨ��һ��ʵ��������ȥ��ȡ��Ա�������ڴ��еĵ�ַ */
  TEST __t("hello,world");
  bool (TEST::*invoker_instance)(int) = __t.m_foo;

  (__t.*invoker_instance)(10);

  /* ͨ�� :: ������ȥ����������ĳ�������²��õ���Ա����������ͬ��Ҳ����������ȡ��Ա������ַ��һ�ַ�ʽ */
  bool (TEST::*invoker_none)(int) = TEST::m_foo;
  (__t.*invoker_none)(10);
}
int main(void) {
  foo();

  return EXIT_SUCCESS;
}