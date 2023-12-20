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

enum RewardFlag : int64_t
{
    N = 1u << 0,
    A = 1u << 1,
    B = 1u << 2,
    C = 1u << 3,
    D = 1u << 4,
    E = 1u << 5,
};

int32_t main(void) {
  uint64_t flag = RewardFlag::A | RewardFlag::C;

  std::vector<RewardFlag> res;

  // for (int i = 1; i < 64; ++i) {
  //   uint64_t mask = int64_t{1} << i;

  //   if (flag & mask) {
  //     res.push_back(static_cast<RewardFlag>(mask));
  //   }
  // }

  // while (flag) {
  //   auto bit = std::countr_zero(flag);
  //   auto mask = 1 << bit;
  //   res.push_back(static_cast<RewardFlag>(mask));
  //   flag &= ~mask;
  // }

  for (auto f : res) {
    std::cout << f << std::endl;
  }

  return 0;
}
