#include <iostream>
using namespace std;

int main(void) {
  int a = 0x400;
  /* const int a_c = const_cast<const int>(a); */     /* 失败，仅支持指针类型的转换 */

  int *a_p = new int(0x400);
  const int *a_p_c = const_cast<const int *>(a_p);
  int *a_p_normal = const_cast<int *>(a_p_c);

  int &a_r = *a_p;
  const int &a_r_c = const_cast<const int &>(a_r);
  int &a_r_normal = const_cast<int &>(a_r_c);

  system("pause");
  return EXIT_SUCCESS;
}