#include <iostream>
#include <string>
#include <vector>
#include <memory>

class BASE {
public:
  BASE() {
    std::cout << "BASE constructor: " << this << std::endl;
  }

  ~BASE() {
    std::cout << "BASE destructor: " << this << std::endl;
  }
  BASE(const BASE& b) {
    std::cout << "BASE copy constructor, copy " << &b << " to " << this << std::endl;
  }
  BASE(BASE&& b) {
    std::cout << "BASE move constructor, move " << &b << " to " << this << std::endl;
  }
  BASE &operator=(BASE &&per) {
    std::cout << "BASE move constructor(operator=)" << std::endl;
    return *this;
  }
  BASE &operator=(const BASE &per) {
    std::cout << "BASE copy constructor(operator=)" << std::endl;
    return *this;
  }
};

void foo(std::shared_ptr<void>& sp) {
  std::cout << sp.use_count() << std::endl;
  std::cout << sp.get() << std::endl;

  std::cout << "B----------------------" << std::endl;

  std::shared_ptr<BASE> p = std::make_shared<BASE>();
  std::cout << p.use_count() << std::endl;
  std::cout << p.get() << std::endl;

  sp = std::move(p);

  std::cout << sp.use_count() << std::endl;
  std::cout << sp.get() << std::endl;

  std::cout << "C----------------------" << std::endl;
}

void bar() {
  std::shared_ptr<void> sp = nullptr;

  std::cout << sp.use_count() << std::endl;
  std::cout << sp.get() << std::endl;

  std::cout << "A----------------------" << std::endl;

  foo(sp);

  std::cout << sp.use_count() << std::endl;
  std::cout << sp.get() << std::endl;

  std::cout << "D----------------------" << std::endl;
}



int main(void) {
  std::vector<std::tuple<int32_t, std::string>> v;
  v.push_back(std::make_tuple(1024, "hello,world!"));

  std::cout << std::get<0>(v.front()) << std::endl;
  std::cout << std::get<1>(v.front()) << std::endl;

  auto& [i, r] = v.front();
  i = 256;
  r = "what the fuck";

  std::cout << std::get<0>(v.front()) << std::endl;
  std::cout << std::get<1>(v.front()) << std::endl;

  return EXIT_SUCCESS;
}
