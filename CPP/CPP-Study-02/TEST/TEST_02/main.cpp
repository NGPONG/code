#include <iostream>
using namespace std;

class base {
public:
  int _age = 0x400;
};

int main(void) {
  const base __b;
  __b._age = 0x100;

  system("pause");
  return EXIT_SUCCESS;
}