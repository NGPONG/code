#include "common.hpp"

// 选择排序
//
// 时间复杂度：
//  * avg  ：O(n^2)
//  * worst: O(n^2)
//  * best : O(n^2)
//
// 比较：
//  * 选择排序可以通过无预测的分支实现以使 CPU 分支预测器受益，方法是使用无分支代码找到最小值的位置，然后无条件地
//  执行交换。参照 solution_3，虽然可能不是最佳实现。
//
//  * 
//

// 普通选择排序
void solution_1(Array &datas) {
  for (std::size_t i = 0; i < datas.size(); ++i) {
    std::int32_t max = i;

    for (std::size_t j = i + 1; j < datas.size(); ++j) {
      if (datas[max] > datas[j]) {
        max = j;
      }
    }

    std::swap(datas[i], datas[max]);
  }
}

// 鸡尾酒算法优化
void solution_2(Array &datas) {
  std::int32_t l = 0, r = datas.size() - 1;

  while (l < r) {
    std::int32_t min = l;
    for (size_t i = l + 1; i <= r; i++) {
      if (datas[i] < datas[min]) {
        min = i;
      }
    }
    std::swap(datas[min], datas[l]);

    std::int32_t max = r;
    for (std::size_t j = r - 1; j > l; --j) {
      if (datas[j] > datas[max]) {
        max = j;
      }
    }
    std::swap(datas[max], datas[r]);

    ++l;
    --r;
  }
}

// 无预测分支实现 
void solution_3(Array &datas) {
  for (size_t i = 0; i < datas.size(); i++) {
    std::size_t min = i;

    for (size_t j = i + 1; j < datas.size(); j++) {
      std::int32_t diff = datas[j] - datas[min];
      std::int32_t mask = diff >> 31;
      min               = (min & ~mask) | (j & mask);
    }

    std::swap(datas[i], datas[min]);
  }
}

// 稳定的快速排序
void solution_4(Array &datas) {
  std::int32_t left = 0, right = datas.size() - 1;

  while (left < right) {
    std::int32_t min = left, max = right;

    for (size_t i = left; i <= right; i++) {
      if (datas[i] < datas[min]) {
        min = i;
      }

      if (datas[i] > datas[max]) {
        max = i;
      }
    }

    std::swap(datas[left], datas[min]);

    if (max == left) {
      max = min;
    }

    std::swap(datas[right], datas[max]);

    ++left;
    --right;
  }
}

std::int32_t main(void) {
  solution_test({
    { solution_1, "solution_1" },
    { solution_2, "solution_2" },
    { solution_3, "solution_3" },
    { solution_4, "solution_4" },
  });

  solution_benchmark({
    { solution_1, "solution_1" },
    { solution_2, "solution_2" },
    { solution_3, "solution_3" },
    { solution_4, "solution_4" },
  });

  return EXIT_SUCCESS;
}
