#include "common.hpp"

void solutions(std::vector<std::int32_t> nums) {
  for (std::int32_t i = nums.size() - 1; i >= 0; --i) {
    std::swap(nums[i], nums[std::rand() % i + 1]);
  }
}

std::int32_t main (std::int32_t argc, char *argv[]) {
  std::vector<std::int32_t> nums = { 1, 3, 6, 8, 8, 9, 10, 21, 33 };
  
  solutions(nums);

  std::cout << nums << std::endl;

  return 0;
}
