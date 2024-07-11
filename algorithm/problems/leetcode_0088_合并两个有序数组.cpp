#include "common.hpp"

// 题目: 合并两个有序的数组
//
// 该算法参考归并排序在合并 left 和 right 时的操作即可

std::vector<std::int32_t> solution(std::vector<std::int32_t>& left, std::int32_t m, std::vector<std::int32_t>& right, std::int32_t n) {
  std::vector<std::int32_t> ret = {};

  std::int32_t i = 0, j = 0;
  while (i < m && j < n) {
    if (left[i] < right[j]) {
      ret.push_back(left[i++]);
    } else {
      ret.push_back(right[j++]);
    }
  }

  while (i < m) {
    ret.push_back(left[i++]);
  }

  while (j < n) {
    ret.push_back(right[j++]);
  }

  return ret;
}

std::int32_t main(std::int32_t argc, char* argv[]) {
  std::vector<int> left  = { 1, 2, 3 };
  std::vector<int> right = { 2, 5, 6 };

  std::cout << solution(left, left.size(), right, right.size()) << std::endl;

  return 0;
}
