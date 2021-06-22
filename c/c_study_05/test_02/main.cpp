#include <pwd.h>
#include <sys/types.h>
#include <stdio.h>

struct test {
  void *p;
};

void foo_3(void) {
  struct test t;
  t.p = (int *)0x12345678;

  int *p = (int *)0x12345678;
  int val = *p;
}

void foo_2(void) {
  foo_3();
}

void foo_1(void) {
  foo_2();
}

int main() {
  foo_1();

  return -1;
}
