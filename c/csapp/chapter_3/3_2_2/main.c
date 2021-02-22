#include <stdio.h>

void multstore(long, long, long *);

long mult2(long a, long b) {
  long s = a * b;
  return s;
}

int main(void) {
  long d;
  multstore(2, 3, &d);
  printf("2 * 3 --> %ld\n", d);
  
  return 0;
}
