#include <iostream>
#include <vector>

class BASE {
public:
  BASE() {
    std::cout << "BASE constructor: " << this << std::endl;
  }
  BASE(int32_t val) {
    std::cout << "BASE constructor" << std::endl;
  }
  ~BASE() {
    std::cout << "BASE destructor: " << this << std::endl;
  }
  BASE(const BASE& b) {
    std::cout << "BASE copy constructor" << std::endl;
  }
  BASE(BASE&& b) {
    std::cout << "BASE move constructor" << std::endl;
  }
  BASE &operator=(BASE &&per) {
    std::cout << "BASE move constructor(operator=)" << std::endl;
    return *this;
  }
  BASE &operator=(const BASE &per) {
    std::cout << "BASE copy constructor(operator=)" << std::endl;
    return *this;
  }

  void Add(int32_t val) { idx += val; }

public:
  int32_t idx;
};

// BASE foo(int32_t idx, std::vector<int32_t> v);
// BASE foo1();
// BASE foo2();

// BASE foo2(std::vector<int32_t> v) {
//   BASE b;

//   for (auto& i : v) {
//     b.Add(i);
//   }

//   return b;
// }

// BASE foo1(std::vector<int32_t> v) {
//   BASE b;

//   for (auto& i : v) {
//     if (1 == 3 || i == 4) {
//       BASE bb = foo(2, { 11,12,13,14,15,16,17,18 });
//       std::cout << "hahahahha" << std::endl;
//       b.Add(bb.idx);
//       continue;
//     }
//     else if (i == 8 || i == 6) {
//       BASE bb = foo(1, { 20, 30, 40, 50 });
//       std::cout << "what the fuck" << std::endl;
//       b.Add(bb.idx);
//       continue;
//     }

//     b.Add(i);
//   }

//   return b;
// }

// BASE foo(int32_t idx, std::vector<int32_t> v) {
//   // if (idx == 1)
//   //   return foo1(v);
//   // else if (idx == 2)
//   //   return foo2(v);
//   // else
//   //   return {};

//   BASE b;
//   return b;
// }

// int main(void) {
//   BASE b = foo(1, {1,2,3,4,5,6,7,8,9});

//   return EXIT_SUCCESS;
// }

void foo(const BASE& b) {
  std::cout << "const BASE& b" << std::endl;
}

void foo(BASE&& b) {
  std::cout << "BASE&& b" << std::endl;
}

BASE bar() {
  BASE b;
  return b;
}

int main(void) {
  BASE b = bar();

  foo(b);
  foo(std::move(b));
  foo(bar());

  return EXIT_SUCCESS;
}
