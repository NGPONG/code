#include "common.hpp"

// 原始实现
void solution_1(Array &datas) {
  for (std::size_t i = 0; i < datas.size(); ++i) {
    for (std::size_t j = 0; j < datas.size() - i - 1; ++j) {
      if (datas[j] > datas[j + 1]) {
        std::swap(datas[j], datas[j + 1]);
      }
    }
  }
}

// 鸡尾酒算法优化
void solution_2(Array &datas) {
  std::int32_t left = 0, right = datas.size() - 1;

  while (left < right) {
    for (size_t i = left; i < right; i++) {
      if (datas[i] > datas[i + 1]) {
        std::swap(datas[i], datas[i + 1]);
      }
    }
    right--;

    for (size_t i = right; i > left; i--) {
      if (datas[i - 1] > datas[i]) {
        std::swap(datas[i], datas[i - 1]);
      }
    }
    left++;
  }
}

// 提前结束优化：避免没必要的迭代
void solution_3(Array &datas) {
  for (size_t i = 0; i < datas.size(); i++) {
    bool is_swapped = false;

    for (size_t j = 0; j < datas.size() - i - 1; j++) {
      if (datas[j] > datas[j + 1]) {
        std::swap(datas[j], datas[j + 1]);
        is_swapped = true;
      }
    }

    if (!is_swapped) {
      break;
    }
  }
}
void solution_4(Array &datas) {
  // for (int k = 0; k < datas.size(); ++k) {
  //   std::vector<std::thread> threads;
  //
  //   for (int i = 0; i < datas.size() - 1; i += 2) {
  //     threads.emplace_back([&datas, i]() {
  //       if (datas[i] > datas[i + 1]) {
  //         std::swap(datas[i], datas[i + 1]);
  //       }
  //     });
  //   }
  //
  //   for (auto &th : threads) {
  //     if (th.joinable()) {
  //       th.join();
  //     }
  //   }
  //
  //   threads.clear();
  //
  //   for (int i = 1; i < datas.size() - 1; i += 2) {
  //     threads.emplace_back([&datas, i]() {
  //       if (datas[i] > datas[i + 1]) {
  //         std::swap(datas[i], datas[i + 1]);
  //       }
  //     });
  //   }
  //
  //   for (auto &th : threads) {
  //     if (th.joinable()) {
  //       th.join();
  //     }
  //   }
  // }
}

int main(void) {
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

  return 0;
}
