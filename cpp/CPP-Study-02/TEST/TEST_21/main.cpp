#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <list>

int main(void) {
  std::vector v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

  auto seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
  std::default_random_engine e(seed);

  std::shuffle(v.begin(), v.end(), e);

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i] << std::endl;
  }

  return EXIT_SUCCESS;
}
