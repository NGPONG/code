#include <iostream>
using namespace std;

#include "test.h"

static void fun_test_01(void) { cout << "TEST!FUNCTON____01" << endl; }

int main() {

  ::fun_test_01();

  int a = 1024;
  cout << a << endl;

  system("pause");
  return EXIT_SUCCESS;
}