#include <iostream>
using namespace std;

void fun_test(int _val) {
  cout << _val << endl;
}

void foo(void (*inv)(int)) {
  inv(0x400);
}

int main(void) {
  foo(fun_test);

  system("pause");
  return EXIT_SUCCESS;
}