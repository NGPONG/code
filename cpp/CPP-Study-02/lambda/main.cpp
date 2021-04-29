#include <iostream>
using namespace std;

class base {
public:
  base(int _val)
    : m_val(_val) {
    cout << "base constructor" << endl;
  }
  base(const base &_b)
    : m_val(_b.m_val) {
    cout << "base copy constructor" << endl;
  }
  ~base() {
    cout << "base destructor" << endl;
  }

public:
  void foo(void) {
    [this]() {
      this->m_val = 0x200;
      cout << this->m_val << endl;
    }();

    cout << this->m_val << endl;
  }

public:
  int m_val;
};

int a = 0x100;

int (*inv)(bool) = [](bool _flag) -> int {
  if (_flag)
    return 0x400;
  else
    return 0x200;
};

int main(void) {
  base b(0x400);

  cout << b.m_val << endl;

  cout << inv(false) << endl;

  system("pause");
  return EXIT_SUCCESS;
}
