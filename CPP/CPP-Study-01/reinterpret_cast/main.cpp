#include <iostream>
using namespace std;

int main(void) {
  int a = 0x400;
  int *a_p = reinterpret_cast<int *>(a);   /* unsafe:a_p->0x400 */

  system("pause");
  return EXIT_SUCCESS;
}