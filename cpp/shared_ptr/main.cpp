#include <iostream>
#include <memory>
using namespace std;

class test {
  int idx;

public:
  test(int _idx) {
    this->idx = _idx;
  };

  test(const test &te) {
    this->idx = te.idx;
  }

  test(test &&te) {
    this->idx = te.idx;
    te.idx = 0;
  }

  ~test() {
    printf("test destructor\n");
  }
  
};

unique_ptr<test> foo() {
  test *p = new test(1024);
  printf("0x%p\n", p);

  unique_ptr<test> up(p);

  test t2(0x200);

  return up;
}

int main(void) {
  /* unique_ptr<test> up = foo();
  printf("0x%p\n", up.get()); */

  test t1 = test(1024);

  return EXIT_SUCCESS;
}