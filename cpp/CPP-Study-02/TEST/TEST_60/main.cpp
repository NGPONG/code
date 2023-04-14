#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

int main(void) {
  std::vector<int32_t> v = {20,18,16,15,12,11,10,7,6,5,4,2,1};//{1,2,4,5,6,7,10,11,12,15,16,18,20}; //{20,18,16,15,12,11,10,7,6,5,4,2,1};

  if (auto it = std::lower_bound(v.rbegin(), v.rend(), 21, [&](const auto& l, const auto& r) {
    return l < r;
  }); true) {
      if (it == v.rend())
        std::cout << "ops" << std::endl;

      std::cout << *it << std::endl;
  } 

  if (auto it = std::lower_bound(v.rbegin(), v.rend(), 10021, [&](const auto& l, const auto& r) {
    return l < r;
  }); true) {
      if (it == v.rend())
        std::cout << "ops" << std::endl;

      std::cout << *it << std::endl;
  }

  if (auto it = std::lower_bound(v.rbegin(), v.rend(), 3, [&](const auto& l, const auto& r) {
    return l < r;
  }); true) {
      std::cout << *it << std::endl;
  }

  if (auto it = std::lower_bound(v.rbegin(), v.rend(), 0, [&](const auto& l, const auto& r) {
    return l < r;
  }); true) {
      if (it == v.rbegin())
        std::cout << "ops" << std::endl;

      std::cout << *it << std::endl;
  }

  if (auto it = std::lower_bound(v.rbegin(), v.rend(), -1, [&](const auto& l, const auto& r) {
    return l < r;
  }); true) {
      if (it == v.rbegin())
        std::cout << "ops" << std::endl;

      std::cout << *it << std::endl;
  }

  return EXIT_SUCCESS;
}
