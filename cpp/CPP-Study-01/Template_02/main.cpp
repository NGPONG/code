#include <iostream>
using namespace std;

template<typename T>
void fun_test(T var1, T var2) {
  cout << "template function" << endl;
  cout << var1 << endl;
  cout << var2 << endl;
}

int main(void) {
  fun_test(0x400, 0x200);

  system("pause");
  return EXIT_SUCCESS;
}