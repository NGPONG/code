#include <iostream>
#include <map>
#include <unistd.h>
#include <vector>
#include <cmath>

class BASE {
public:
  class Iterator {
  public:
    Iterator(std::vector<int>::iterator _it, BASE* _pb) {
      it = _it;
      pb = _pb;
    }
    Iterator operator++() {
      ++it; 
      if (it == pb->v1.end()) {
          it = pb->v2.begin();
      }
      return *this;
    }
    bool operator!=(const Iterator& target) {
        return it != target.it;
    }
    auto& operator*() {
      return *it;
    }

    private:
      std::vector<int>::iterator it;
      BASE* pb;
  };

  Iterator begin() {
    return Iterator(v1.begin(), this);
  }

  Iterator end() {
    return Iterator(v2.end(), this);
  }

  std::vector<int> v1{1, 2, 3};
  std::vector<int> v2{4, 5, 6};
};

auto foo() {
  std::string str = "hello,world!";

  return [&] () {
    std::cout << str << std::endl;
  };
}

int main(int argc, char *argv[]) {
  std::cout << std::ceil(0.02) << std::endl;
}
