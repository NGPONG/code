#include <iostream>
#include <vector>
#include <limits.h>

// 题目: 给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列
//
// leetcode 思路: 
//  * https://leetcode-cn.com/problems/increasing-triplet-subsequence/solution/c-xian-xing-shi-jian-fu-za-du-xiang-xi-jie-xi-da-b/
//
// 我的思路: 
//  * 就是一个维护中位数的过程，我们需要使一个数永远都是最小的，其次以这个最小的基础上去维护这个中位数

bool increasing_triplet(std::vector<int> &nums) {
  int len = nums.size();
  if (len < 3) return false;

  int small = INT_MAX, mid = INT_MAX;
  for (auto num : nums) {
    if (num <= small) {
      small = num;
    } else if (num <= mid) {
      mid = num;
    } else if (num > mid) {
      return true;
    }
  }

  return false;
}

int main(void) {
  std::vector<int> nums = { 2, 4, 3, 1, 5 };
  std::cout << increasing_triplet(nums) << std::endl;

  return EXIT_SUCCESS;
}
