#include <stdio.h>
#include <Windows.h>

#define PI 3.1415926

int main(void) {

  int r = 3;

  // Round perimeter 2 * PI * r
  float perimeter = 2 * PI * r;
  printf("perimeter = %.2f\n", 3.147);

  // Round area PI * r * r 込込込
  float area = PI * r * r;
  printf("area = %.2f\n", area);

  printf("込込込\n");

  system("pause");
  return 0;
}