#include <iostream>
using namespace std;


int main(void) {


  int a = 5;                  /* a:左值, 5:右值 */
  int b = a;                  /* b:左值, b:左值 */
  int c = 5;                  /* c:左值, 5:右值 */
  int d = a + 1;              /* d:左值, a + 1:右值 */
  int *e = &a;                /* e:左值, &a:右值 */

  //int &a_ref = a + 1;         /* a_ref:左值引用, a + 1:右值, 编译失败 */
  const int &a_ref_c = a + 1; /* a_ref_c:常量左值引用, a + 1:右值, 编译通过 */

  int &&a_r_r = a + 1;        /* a_r_r:右值引用, a + 1:右值 */
  int &&a_r_r_c = move(a);    /* a_r_r_c:右值引用, move(a):将亡值 */


  return EXIT_SUCCESS;
}