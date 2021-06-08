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
  std::unordered_map<int, int> hash;
  for (int i = 0; i < nums.size(); ++i) {
    auto it = hash.find(target - nums[i]);
    if (it != hash.end()) {
      return { it->second, i };
    }

    hash[nums[i]] = i;
  }

  return {0, 0};
}

int main(void) {
  std::vector<int> nums = random_nums();
  two_sum_hash(nums, 23746);

  return EXIT_SUCCESS;
}
