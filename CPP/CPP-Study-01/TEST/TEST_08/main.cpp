#include <iostream>
using namespace std;


int main(void) {


  int a = 5;                  /* a:��ֵ, 5:��ֵ */
  int b = a;                  /* b:��ֵ, b:��ֵ */
  int c = 5;                  /* c:��ֵ, 5:��ֵ */
  int d = a + 1;              /* d:��ֵ, a + 1:��ֵ */
  int *e = &a;                /* e:��ֵ, &a:��ֵ */

  //int &a_ref = a + 1;         /* a_ref:��ֵ����, a + 1:��ֵ, ����ʧ�� */
  const int &a_ref_c = a + 1; /* a_ref_c:������ֵ����, a + 1:��ֵ, ����ͨ�� */

  int &&a_r_r = a + 1;        /* a_r_r:��ֵ����, a + 1:��ֵ */
  int &&a_r_r_c = move(a);    /* a_r_r_c:��ֵ����, move(a):����ֵ */


  return EXIT_SUCCESS;
}