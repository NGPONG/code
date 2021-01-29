#include <math.h>
#include <stdio.h>

float my_foo(float a, float b) { return fmax(a, b); }

int main() {
  printf("%f\n", my_foo(4.5, 3.1));
  return 0;
}
