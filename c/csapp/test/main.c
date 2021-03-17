#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int arr[6] = { 1, 2, 3, 4, 5 ,6 };
  
  /* 0x401114 */
  int *r13 = arr;
  for (int r12 = 0; r12 < 6; ++r12) {
    /* 0x401117 ~ 0x401123 */
    if ((*r13 - 1) > 5) {
      return EXIT_FAILURE;
    }

    int rbx = r12 + 1;
    while (rbx <= 5) {
      if (arr[rbx] == *r13) {
        return EXIT_FAILURE;
      }

      ++rbx;
    }
    r13 += 1;
  }
  /* 0x401151 */

  /* 0x401153 */
  int *rsi = arr + sizeof(arr); /* end pointer */
  int *rax = arr;
  while (rax == rsi) {
    *arr = 7 - *arr;
  }
  /* 0x40116d */

  
  

  return EXIT_SUCCESS;
}
