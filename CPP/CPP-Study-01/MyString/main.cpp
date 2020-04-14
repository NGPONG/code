#include <iostream>
using namespace std;

#include "m_string.h"

void test() {
  m_string str = "NGPONG";
  str = "Hello,World!";
}

int main(void) {

  test();

  system("pause");
  return EXIT_SUCCESS;
}