#include <iostream>
using namespace std;

class BASE { virtual ~BASE() {}; };

class DERIVED : public BASE {};

class OTHER {};

int main(void) {
  /* 基础类型的转换 */
  int *p_a = new int(0x400);
  long *p_b = dynamic_cast<long *>(p_a);                                          /* 失败，动态类型转换不支持基础数据类型和基础数据类型指针间的转换 */


  /* 类的指针/引用的转换 */
  BASE *base_non_polymorphism = new BASE;
  DERIVED *der_non_polymorphism = dynamic_cast<DERIVED *>(base_non_polymorphism); /* 失败，expression 无法构成多态，故向下类型转换失败，并返回一个空指针 */

  BASE *base_polymorphism = new DERIVED;
  DERIVED *der_polymorphism = dynamic_cast<DERIVED *>(base_polymorphism);         /* 成功，expression 可以构成多态 */
  BASE *base_more = dynamic_cast<BASE *>(der_polymorphism);                       /* 成功，向上类型转换 */

  OTHER *other = dynamic_cast<BASE *>(der_polymorphism);                          /* 失败，OTHER 和 expression 并不存在于同一条继承体系当中 */

  

  system("pause");
  return EXIT_SUCCESS;
}