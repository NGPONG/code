#include <iostream>
using namespace std;

class base {
public:
  base(int age)
    : _age(age) {
    cout << "base constructor" << endl;
  }

public:
  int _age;
};


class perosn : public base {
public:
  perosn(int age)
    : base(age) {
    cout << "person constructor" << endl;
  };

  void print() {
    cout << base::_age << endl;
    cout << this->_age << endl;
  }
};

int main(void) {


  system("pause");
  return EXIT_SUCCESS;
}