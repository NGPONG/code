#include <iostream>
#include <memory>
#include <map>

class BASE {
public:
  // BASE(int32_t val) {
  //   std::cout << val << std::endl;
  // }

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

class BAR : public BASE
{
  
};

std::map<int32_t, std::shared_ptr<BASE>> m;

std::shared_ptr<BASE> foo() {
  // std::shared_ptr<BASE> bp = m[1];

  // auto it = m.find(1);
  // std::cout << bp.use_count() << std::endl;

  // return bp;

  // auto it = m.find(1);
  // if (it == m.end()) {
  //   return nullptr;
  // }
  // else {
  //   std::cout << it->second.use_count() << std::endl;
  //   return it->second;
  // }

  std::shared_ptr<BASE> bp = nullptr;

  auto it = m.find(1);
  if (it == m.end()) {
    return bp;
  }
  else {
    std::cout << it->second.use_count() << std::endl;
    new (&bp) std::shared_ptr<BASE>(std::move(it->second));
    std::cout << bp.use_count() << std::endl;
    return bp;
  }
}

int main(void) {
  // m.insert({1, std::make_shared<BASE>()});

  // // std::shared_ptr<BASE> bp1 = m[1];
  // // std::cout << bp1.use_count() << std::endl;

  // std::shared_ptr<BASE> bp2(std::move(foo()));
  // std::cout << bp2.use_count() << std::endl;

  BAR ba();

  return EXIT_SUCCESS;
}
