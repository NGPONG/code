#include "common.hpp"

// 一个元素也可以称之为大顶堆
//
//

// parent: (i - 1) / 2
// left_c: i * 2 + 1
// righ_c: i * 2 + 2

void solution_1(Array &datas) {
  auto heapify = make_y_combinator([&](auto heapify, std::int32_t n, std::int32_t idx) -> void {
    std::int32_t l = idx * 2 + 1;
    std::int32_t r = idx * 2 + 2;

    std::int32_t larger = idx;
    if (l <= n && datas[l] > datas[larger]) {
      larger = l;
    }
    if (r <= n && datas[r] > datas[larger]) {
      larger = r;
    }

    if (larger != idx) {
      std::swap(datas[larger], datas[idx]);
      heapify(n, larger);
    }
  });

  std::int32_t index  = datas.size() - 1;
  std::int32_t parent = (index - 1) / 2;

  for (std::int32_t i = parent; i >= 0; --i) {
    heapify(index, i);
  }

  for (std::int32_t i = index; i > 0; --i) {
    std::swap(datas[0], datas[i]);
    heapify(i - 1, 0);
  }
}

std::int32_t main(std::int32_t argc, char *argv[]) {
  solution_test({
    { solution_1, "solution_1" },
  });

  solution_benchmark({
    { solution_1, "solution_1" },
  });

  return 0;
}
