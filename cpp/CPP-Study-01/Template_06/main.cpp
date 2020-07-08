#include <iostream>
using namespace std;

#include "test.hpp"

template<typename T>
void fun_test(T var);

template<typename T>
void fun_test(T var) {
  cout << var << endl;
}

int main(void) {
  fun_test(0x400);

  system("pause");
  return EXIT_SUCCESS;
}