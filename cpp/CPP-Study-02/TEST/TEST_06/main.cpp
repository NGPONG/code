#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdint.h>
<<<<<<< HEAD
#include <memory>
=======
#include <chrono>
#include <assert.h>
>>>>>>> 61a111507049e9b286349976c858c8fcb80823ab

class base {
public:
  int num;

  base(int _num) {
    this->num = _num;
  }

  base(const base &b) {
    this->num = b.num;
    std::cout << "copy constructor" << std::endl;
  }

  base(base &&b) {
    this->num = b.num;
    std::cout << "move constructor" << std::endl;
  }

  ~base() {
  }

  bool operator==(base &per_) {
    return true;
  }
};

void foo(const base &b) {
    std::cout << "left" << std::endl;

    base a(b);
}

void foo(base &&b) {
    std::cout << "right" << std::endl;

    base a(std::forward<base>(b));
}

int main(void) {
    // base b(1);

    // foo(b);
    // foo(base(2));

    bool flg = false;
    if (flg) {
#define D_TEST
    } else {
        std::cout << "hello,world" << std::endl;
    }

#ifdef D_TEST
    std::cout << "hello,NGPONG" << std::endl;
#endif

    return EXIT_SUCCESS;
}
