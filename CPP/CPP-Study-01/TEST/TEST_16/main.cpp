#include <iostream>
using namespace std;

void fun_test(int _val) {
  cout << _val + 0x400 << endl;
}

template<typename T>
void fun_test_02(T __fu) {
  cout << typeid(__fu).name() << endl;
  __fu(0x200);
}

template<typename T>
void fun_test_03(T _val) {
  cout << typeid(_val).name() << endl;
  cout << _val << endl;
}

int main(void) {
  fun_test_02(fun_test);
  fun_test_03<int>(0x200);

  system("pause");
  return EXIT_SUCCESS;
}