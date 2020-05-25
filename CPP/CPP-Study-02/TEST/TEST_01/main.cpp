#include <iostream>
using namespace std;

#include <windows.h>
#include <functional>

function<void(void)> __fn;

void init(void) {
  int i = 1;
  __fn = [=]() mutable {
    cout << ++i << endl;
  };
}

void foo(void) {
  while (true) {
    __fn();
    Sleep(1000);
  }
}

int main(void) {
  /* init();
  foo(); */

  int i = 10;
  printf("%p\n", &i);

  int *p = &i;

  function<void(void)> _fn = [=]() mutable {
    cout << ((*p) += 1) << " ";
  };

  _fn();
  _fn();
  _fn();

  cout << i << endl;

  cout << sizeof(_fn) << endl;

  system("pause");
  return EXIT_SUCCESS;
}