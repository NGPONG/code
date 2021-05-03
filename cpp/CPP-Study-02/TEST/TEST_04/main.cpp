#include <iostream>
#include <string>
using namespace std;

class FOO {
public:
  FOO() {
    printf("hello,world!");
  }

  FOO(const FOO &foo) {
    printf("hello,NGPONG!");
  }

  ~FOO() {
    printf("destructor!");
  }
};

FOO foo;

int main(void) {
  

  return EXIT_SUCCESS;
}
