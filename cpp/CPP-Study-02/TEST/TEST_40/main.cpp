#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iterator>
#include <random>
#include <chrono>

int main() {
  std::vector<int32_t> v = { 1,2,3,4,5,6,7,8,9,10 };

  for (int i = 0; i < 3; ++i) {
    std::cout << "------------------------------" << std::endl;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(v.begin(), v.end(), std::default_random_engine { seed });

    for (auto& i : v)
      std::cout << i << std::endl;

    std::cout << "------------------------------" << std::endl;
  }

  return 0;
}
