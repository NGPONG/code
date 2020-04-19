#include <iostream>
using namespace std;

__stdcall int fun_test(char a, short b) {
  printf("Hello,World!%d", a + b);
  return 0;
}

void test() {
  int(__fastcall * invoker)(char, short) = fun_test;
  invoker('a', 256);
}

int main(void) {
  test();

  system("pause");
  return EXIT_SUCCESS;
}