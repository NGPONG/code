#include "common.hpp"

template <typename T>
std::vector<T> parse_num(T num) {
  std::vector<T> res;

  while (num) {
    // 统计从 num 低位开始直到到达1时需要经过几个 0
    auto bit = __builtin_ctz(num);

    // 设置为掩码；加入返回数组；从 num 中去除已统计过的 1 位； 
    auto mask = 1 << bit;
    res.push_back(static_cast<T>(mask));
    num &= ~mask;
  }

  return res;
}

std::int32_t main(std::int32_t argc, char *argv[]) {
  uint16_t num = 0b0110'0010;
  std::cout << std::bitset<16>(num) << std::endl;

  for (auto &&item : parse_num(num)) {
    std::cout << std::bitset<16>(item) << std::endl;
  }

  return 0;
}
