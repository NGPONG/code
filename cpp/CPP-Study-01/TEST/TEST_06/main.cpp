#include <iostream>
using namespace std;

int &&test() {
  int a, b = 0x200;
  return a + b;
}

int main(void) {
  int &&a = test();
  cout << a << endl;
  cout << a << endl;
  cout << a << endl;
  cout << a << endl;
  cout << a << endl;
  cout << a << endl;
  cout << a << endl;

  system("pause");
  return EXIT_SUCCESS;
}