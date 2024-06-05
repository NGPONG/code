#include "common.hpp"

// 基数排序

void solution_1(Array &datas) {
  std::int32_t max_val = datas[0];
  for (std::size_t i = 0; i < datas.size(); ++i) {
    if (max_val < datas[i]) {
      max_val = datas[i];
    }
  }

  max_val += 1;

  std::int32_t count_arr[max_val]; std::memset(count_arr, 0, sizeof(count_arr));
  std::int32_t sort_arr[datas.size()]; std::memset(sort_arr, 0, sizeof(sort_arr));

  for (std::size_t i = 0; i < datas.size(); ++i) {
    count_arr[datas[i]] += 1;
  }

  for (std::size_t i = 1; i < max_val; ++i) {
    count_arr[i] += count_arr[i - 1];
  }

  for (std::size_t i = 0; i < datas.size(); ++i) {
    sort_arr[--count_arr[datas[i]]] = datas[i];
  }

  for (std::size_t i = 0; i < datas.size(); ++i) {
    datas[i] = sort_arr[i];
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
