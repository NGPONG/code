#include <iostream>
#include <string>

using namespace std;

class Dog {
public:
  Dog(string _name) {
    this->d_name = _name;
  }
  Dog(const Dog &dog) {
    this->d_name = dog.d_name;
  }

public:
  Dog &operator=(const Dog &dog) {
    this->d_name = dog.d_name;
    return *this;
  }
public:
  string d_name;
};

int main(void) {
  Dog _dog1("1");
  Dog _dog2("2");

  _dog1 = _dog2;

  system("pause");
  return EXIT_SUCCESS;
}