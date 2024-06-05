#include "common.hpp"

void solution_1(Array &datas) {
  auto merge_split = make_y_combinator([&] (auto merge_split, std::int32_t L, std::int32_t M, std::int32_t R) {
    std::int32_t left_size = M - L;
    std::int32_t left[left_size];
    for (std::int32_t i = L; i < M; ++i) {
      left[i - L] = datas[i];
    }

    std::int32_t right_size = R - M + 1;
    std::int32_t right[right_size];
    for (std::int32_t i = M; i <= R; ++i) {
      right[i - M] = datas[i];
    }

    std::int32_t i = 0, j = 0, k = L;
    while (i < left_size && j < right_size) {
      if (left[i] < right[j]) {
        datas[k++] = left[i++];
      } else {
        datas[k++] = right[j++];
      }
    }

    while (i < left_size) {
      datas[k++] = left[i++];
    }

    while (j < right_size) {
      datas[k++] = right[j++];
    }
  });

  auto merge_sort = make_y_combinator([&] (auto merge_sort, std::int32_t low, std::int32_t high) {
    if (low == high) {
      return;
    }

    std::int32_t mid = (low + high) / 2;
    merge_sort(low, mid);
    merge_sort(mid + 1, high);

    merge_split(low, mid + 1, high);
  });

  merge_sort(0, datas.size() - 1);
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
