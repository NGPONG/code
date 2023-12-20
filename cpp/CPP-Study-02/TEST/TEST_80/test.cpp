#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <map>

#include "zip.hpp"

int32_t main(void) {
  std::vector<int32_t> v = {1,2,3,4,5};
  std::set<std::string> s = {"A","B","C","D","E"};
  std::list<int32_t> l = {6,7,8,9,10};
  std::map<int32_t, int32_t> m;

  std::cout << "====================================" << std::endl;

  for (auto& ele : v) {
    std::cout << "v [" << &ele << "]" << std::endl;
  }

  std::cout << "====================================" << std::endl;

  std::cout << "====================================" << std::endl;

  for (auto& ele : s) {
    std::cout << "s [" << &ele << "]" << std::endl;
  }

  std::cout << "====================================" << std::endl;

  std::cout << "====================================" << std::endl;

  for (auto& ele : l) {
    std::cout << "l [" << &ele << "]" << std::endl;
  }

  std::cout << "====================================" << std::endl;

  std::cout << "====================================" << std::endl;

  for (auto&& [ve, se, le] : zip(v,s,l)) {
    ve = le;
    std::cout << "v [" << &ve << "], s [" << &se << "], l [" << &le << "]." << std::endl;
  }

  std::cout << "====================================" << std::endl;

  std::cout << "====================================" << std::endl;

  for (auto& ele : v) {
    std::cout << "v [" << ele << "]" << std::endl;
  }

  std::cout << "====================================" << std::endl;
}
