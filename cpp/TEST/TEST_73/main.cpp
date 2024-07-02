#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <set>
#include <algorithm>
#include <random>
#include <queue>
#include <functional>

enum class AnimalFlags : char
{
    HasClaws   = 1,
    CanFly     = 2,
    EatsFish   = 4,
    Endangered = 8
};

inline AnimalFlags operator|(AnimalFlags a, AnimalFlags b)
{
    return static_cast<AnimalFlags>(static_cast<int>(a) | static_cast<int>(b));
}

int main(void) {
  AnimalFlags flg = static_cast<AnimalFlags>(127);
  std::cout << static_cast<int32_t>(flg) << std::endl;

  std::function<void(const std::string&)> f{};

  f("");

  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 5); 

  std::vector<std::tuple<int64_t, std::vector<int32_t>>> v;

  while (true) {
    std::string exp;
    getline(std::cin, exp);

    std::cout << "+--------------------------------------+" << std::endl;

    int64_t slot = std::stoi(exp);

    std::vector<int32_t> s;
    for (int i = 0; i < dist6(rng); ++i)
      s.push_back(0);

    auto it = std::lower_bound(v.begin(), v.end(), slot, [] (const auto& ele, const int64_t val) {
      return std::get<0>(ele) < val;
    });
    
    if (it == v.end()) {
      std::cout << "find: end" << std::endl;
    }
    else {
      std::cout << "find: " << std::get<0>(*it) << std::endl;
    }

    if (it != v.end() && std::get<0>(*it) == slot) {
      std::get<1>(*it).push_back(0);
    }
    else {
      v.insert(it, std::make_tuple(slot, s));
    }

    for (auto& ele : v) {
      std::cout << std::get<0>(ele) << ": [" << std::get<1>(ele).size() << "]" << std::endl;
    }

    std::cout << "+--------------------------------------+" << std::endl;
  }

  return EXIT_SUCCESS;
}
