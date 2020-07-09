#include <iostream>
using namespace std;

class BASE {};

class DERIVED : public BASE {};

class OTHER {};

int main(void) {
  /* 1. 基础数据类型转换 */
  int a = 0x400;
  long a_l = static_cast<long>(a);                        /* 典型的非强制转换 */     
  int b = 364;                    
  char b_c = static_cast<char>(b);                        /* 窄化转换，可能会丢失精度 */

  /* 2. 无法应用于自定义数据类型的转换 */
  BASE base_01;
  DERIVED derived_01 = static_cast<BASE>(base_01);

  /* 3. 指针类型的转换，对于除了非 void * 的指针类型，对会 目标类型与表达式类型 之间的指针类型进行校验 */
  char *c_p = static_cast<char *>(&a);                    /* 失败，int * 与 char * 不匹配 */
  void *p_01 = static_cast<void *>(&a);                   /* 成功，void * 指针类型不做检验 */
  int *p_02 = static_cast<int *>(p_01);                   /* 成功，void * 指针类型不做检验 */
  int *p_03 = static_cast<int *>(p_02);                   /* 成功，int * 与 int * 匹配 */

  /* 4. 类指针的静态定位 */
  BASE base;
  DERIVED derived;
  OTHER other;
  BASE *p_base = static_cast<BASE *>(&derived);           /* 上行转换 */
  DERIVED *p_derived = static_cast<DERIVED *>(p_base);    /* 下行转换 */
  OTHER *p_other = static_cast<OTHER *>(p_base);          /* 失败，转换对象间不存在继承体系 */

  system("pause");
  return EXIT_SUCCESS;
}