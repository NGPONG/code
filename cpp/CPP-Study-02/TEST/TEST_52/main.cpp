#include <iostream>
#include <vector>
#include <utility>
#include <tuple>

class BASE {
  using BASE_IT = std::vector<int32_t>::iterator;

public:
  BASE() {
    for (int i = 0; i < 8; ++i)
      BASE::v1.push_back(i);

    // for (int i = 8; i < 15; ++i)
    //   BASE::v2.push_back(i);
  }

public:
  class Iterator {
  public:
    Iterator(BASE_IT _it)
      : it(_it) {}

    Iterator operator++() {
      if (++it == BASE::v1.end()) {
        it = v2.begin();
      }
      return *this;
    }
    bool operator!=(const Iterator &target) {
      return it != target.it;
    }
    auto &operator*() {
      return *it;
    }

  private:
    BASE_IT it;
  };
  class ConstIterator {
  public:
    ConstIterator(std::vector<int32_t>::const_iterator _it, const std::vector<int32_t> &_v1, const std::vector<int32_t> &_v2) {
      it = _it;
      v1_begin = _v1.cbegin();
      v1_end = _v1.cend();
      v2_begin = _v2.cbegin();
      v2_end = _v2.cend();
    }

    ConstIterator operator++() const {
      if (++it == v1_end) {
        if (v2_begin == v2_end)
          it = v2_end;
        else
          it = v2_begin;
      }
      return *this;
    }
    bool operator!=(const ConstIterator &target) const {
      return it != target.it;
    }
    const auto &operator*() const {
      return *it;
    }

  private:
    mutable std::vector<int32_t>::const_iterator it;

    mutable std::vector<int32_t>::const_iterator v1_begin;
    mutable std::vector<int32_t>::const_iterator v1_end;
    mutable std::vector<int32_t>::const_iterator v2_begin;
    mutable std::vector<int32_t>::const_iterator v2_end;
  };

public:
  Iterator begin() {
    return Iterator(v1.begin());
  };
  Iterator end() {
    return Iterator(v2.end());
  };
  ConstIterator begin() const {
    return ConstIterator(v1.cbegin(), v1, v2);
  };
  ConstIterator end() const {
    return ConstIterator(v2.cend(), v1, v2);
  };

private:
  static std::vector<int32_t> v1;
  static std::vector<int32_t> v2;
};
std::vector<int32_t> BASE::v1 = {};
std::vector<int32_t> BASE::v2 = {};

void bar(int a, double b, std::string c) {
  std::cout << a << " " << b << " " << c << std::endl;
}

int main(void) {
  BASE b;

  for (auto &i : std::as_const(b)) {
    std::cout << i << std::endl;
  }

  // auto f = [](int a, double b, std::string c) { std::cout<<a<<" "<<b<<" "<<c<< std::endl; };
  // auto params = std::make_tuple(1, 2.0, "Hello");
  // std::apply(bar, params);
  // std::cout << "ops" << std::endl;

  return EXIT_SUCCESS;
}
