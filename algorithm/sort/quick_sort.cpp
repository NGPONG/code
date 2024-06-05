#include "common.hpp"

void solution_1(Array &datas) {
  auto quick_sort = make_y_combinator([&](auto quick_sort, std::int32_t begin, std::int32_t end) -> void {
    if (begin >= end) {
      return;
    }

    std::int32_t L = begin;
    std::int32_t R = end;
    std::int32_t P = datas[begin];

    while (L < R) {
      while (L < R && datas[R] >= P) {
        R--;
      }

      while (L < R && datas[L] <= P) {
        L++;
      }

      if (L < R) {
        std::swap(datas[L], datas[R]);
      }
    }

    std::swap(datas[L], datas[begin]);

    quick_sort(begin, L - 1);
    quick_sort(L + 1, end);
  });

  quick_sort(0, datas.size() - 1);
}

std::int32_t main (std::int32_t argc, char *argv[]) {
  solution_test({
    { solution_1, "solution_1" },
  });

  solution_benchmark({
    { solution_1, "solution_1" },
  });

  return 0;
}
