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

  function<void(void)> _fn = [=]() mutable {
    cout << ++i << " ";
    printf("%p\n", &i);
  };

  _fn();
  _fn();
  _fn();

  [=]() mutable {
    cout << ++i << endl;
  }();

  cout << i << endl;

  system("pause");
  return EXIT_SUCCESS;
}