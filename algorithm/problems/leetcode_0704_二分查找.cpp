#include "common.hpp"

std::int32_t solution(std::vector<std::int32_t> &nums, std::int32_t target) {
  std::int32_t lt = 0;
  std::int32_t gt = nums.size() - 1;

  while (lt <= gt) {
    std::int32_t mid = (lt + gt) / 2;

    if (target < nums[mid]) {
      gt = mid - 1; 
    } else if (target > nums[mid]) {
      lt = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}

std::int32_t main (std::int32_t argc, char *argv[]) {
  std::vector<std::int32_t> nums = { 1, 3, 6, 8, 8, 9, 10, 21, 33 };

  std::cout << solution(nums, 1) << std::endl;
  std::cout << solution(nums, 2) << std::endl;
  std::cout << solution(nums, 8) << std::endl;
  std::cout << solution(nums, 21) << std::endl;
  std::cout << solution(nums, 100) << std::endl;

  return 0;
}
