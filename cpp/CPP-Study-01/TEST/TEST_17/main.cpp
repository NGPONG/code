#include <iostream>
using namespace std;

template<class T>
class Printer {
public:
  Printer(T val)
    : _val(val) {
    cout << "PRINTER CONSTRUCTOR" << endl;
  }

public:
  void operator()() {
    cout << this->_val << endl;
  }
  void operator()(int num_01,int num_02,int num_03,int num_04) {
    cout << this->_val + num_01 + num_02 + num_03 + num_04 << endl;
  }

public:
  T _val;
};

void foo(void) {
  Printer<string> _p("HELLO,WORLD");
  _p();

  Printer<int> __p(0x400);
  __p(1, 2, 3, 4);
}

int main(void) {
  foo();

  system("pause");
  return EXIT_SUCCESS;
}