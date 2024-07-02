#include <iostream>
using namespace std;

#include "m_string.h"

void test() {
  m_string str_1 = "NGPONG";
  m_string str_2 = "World!";

  m_string str_test_1 = str_1;
  m_string str_test_2 = move(str_2);

  str_test_1 = str_1;
  str_test_2 = move(str_2);

  str_1 = "Hello,";

  cout << str_1[0] << str_1[1] << str_1[2] << str_1[3] << endl;
  
  cout << str_1 + str_2 << endl;
  m_string str_3 = str_2 + "Hello!!!!";

  int a = 1024;
}

int main(void) {

  test();

  system("pause");
  return EXIT_SUCCESS;
}