#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <unordered_set>
#include <variant>
#include <type_traits>
#include <map>
#include <set>
#include <unordered_set>
#include <random>
#include <chrono>
#include <algorithm>
#include <bit>
#include <bitset>
#include <array>
#include <utility>
#include <list>
#include <functional>
#include <sstream>
#include <regex>

#include "test.h"

int32_t main(void) {
  auto us = foo();

  for (auto& str : us) {
    std::cout << str << std::endl;
  }

  return 0;
}
