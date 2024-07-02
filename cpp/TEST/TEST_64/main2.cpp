#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main(void) {
  std::vector<int32_t> ivec(10);
  std::iota(ivec.begin(), ivec.end(), 0);

  // auto it = std::find_if(ivec.begin(), ivec.end(), [](const int32_t i) {
  //   return i == 3;
  // });
  // ivec.erase(it);

  // ivec.erase(std::remove_if(ivec.begin(), ivec.end(), [] (const int32_t i) {
  //   return i == 3;
  // }), ivec.end());

  auto it = std::find_if(ivec.begin(), ivec.end(), [](const int32_t i) {
    return i == 3;
  });
  std::iter_swap(it, ivec.rbegin());
  ivec.erase(std::next(ivec.rbegin()).base());

  for (auto i : ivec)
    std::cout << i << std::endl;

  return EXIT_SUCCESS;
}
