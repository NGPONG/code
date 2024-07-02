#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> random_nums() {
  std::vector<int> ret;
  std::unordered_map<int, bool> cont;

  srand((unsigned)time(NULL));
  for (int i = 0; i < 50000; ++i) {
    int num = rand() % 50000;
    if (cont.find(num) != cont.end()) {
      --i;
      continue;
    }

    ret.push_back(num);
    cont[num] = true;
  }

  return ret;
}

// 题目: 给定一个无序数组，寻找两数之和等于给定的 target，要求返回两数的下标
//
// 解:
// 两数之和，解 target = a + b，那么假设知道 a 的情况下，这其实就是一个求 b = target - a 的过程
// 在这里使用了 hash 表，键为值，值下标
// 每次遍历的过程中，寻找 target - a(当前下标对应元素的值) 是否已存在，如果存在则代表着当前数组
// 中存在 a + b = target 的关系
std::pair<int, int> two_sum_hash(std::vector<int> &nums, int target) {
  // target = a + b
  // std::unordered_map<std::int32_t, std::int32_t> hash;
  // for (std::int32_t i = 0; i < nums.size(); ++i) {
  //   auto it = hash.find(target - nums[i]);
  //   if (it != hash.end()) {
  //     return { it->second, i };
  //   }
  //
  //   hash[nums[i]] = i;
  // }

  // std::int32_t left = 0, right = nums.size() - 1;
  //
  // while (left < right) {
  //   for (size_t i = left + 1; i <= right; i++) {
  //     if (target == nums[left] + nums[i]) {
  //       return { left, i };
  //     }
  //   }
  //   left++;
  //
  //   for (size_t i = right - 1; i >= left; i--) {
  //     if (target == nums[right] + nums[i]) {
  //       return { right, i };
  //     }
  //   }
  //   right--;
  // }

  for (std::int32_t i = 0; i < nums.size(); ++i) {
    std::int32_t x = nums[i];
    for (std::int32_t j = i + 1; j < nums.size(); ++j) {
      std::int32_t y = nums[j];
      std::cout << i << "," << j << std::endl;
      if (target == x + y) {
        return { i, j };
      }
    }
  }

  return {};
}

int main(void) {
  std::vector<std::int32_t> nums = { 3,2,4, 7, 2, 1, 0, 5, 4, 9, 11, 20, 21, 22, 23 };

  auto pair = two_sum_hash(nums, 100);

  std::cout << pair.first << std::endl;
  std::cout << pair.second << std::endl;

  return EXIT_SUCCESS;
}
