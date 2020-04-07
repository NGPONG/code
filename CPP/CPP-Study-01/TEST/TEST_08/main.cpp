#include <iostream>
using namespace std;

#include <string.h>

class Person {
public:
  Person() {
    this->m_age = 0x0;
  }
  Person(int age) {
    this->m_age = age;
  }
  Person(const Person &per) {
    this->m_age = per.m_age;
  }
  Person(Person &&per) {
    this->m_age = per.m_age;
    per.m_age = 0x0;
  }
  ~Person() {
    cout << "Person destructor" << endl;
  }

  Person &operator=(const Person &per) {
    this->m_age = per.m_age;
    return *this;
  }

public:
  int m_age;
};

class TEST {
public:
  TEST(Person per) {
    printf("%d\n", per.m_age);
    this->per = per;
  }

public:
  Person per;
};

int main(void) {

  Person per(1024);

  TEST test(per);
  
  /** 
   * Person per(1024) == 0x62fe08
   * Person per       == 0x62fe0c
   * 0x62fe04 这个地址是干啥的
   * 0x62fde8 又是一个不一样的地址？？？ 
   * 在 拷贝操作符重载函数中 这个per的地址就正确了，就是理想中的 0x62fe0c
   * 0x62fe04 这个应该是当前实例的地址
   * 0x62fe04 是的，
   */

  system("pause");
  return EXIT_SUCCESS;
}