#include <iostream>
using namespace std;

void foo(int _val = 0x400);

int main(void) {
  foo();

  system("pause");
  return EXIT_SUCCESS;
}

void foo(int _val) {
  cout << _val << endl;
}