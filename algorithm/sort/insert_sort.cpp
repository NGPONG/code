#include "common.hpp"

void solution_1(Array &datas) {
  for (size_t i = 1; i < datas.size(); i++) {
    std::int32_t key = datas[i];

    std::int32_t j = i - 1;
    for (; j >= 0 && datas[j] > key; --j) {
      datas[j + 1] = datas[j];
    }
    datas[j + 1] = key;
  }
}

void solution_2(Array &datas) {
  auto insert_sort = make_y_combinator(
    [&](auto insert_sort, std::int32_t i = 1) -> void {
      if (i >= datas.size()) {
        return;
      }

      std::int32_t key = datas[i];

      std::int32_t j = i - 1;
      for (; j >= 0 && key < datas[j]; --j) {
        datas[j + 1] = datas[j];
      }
      datas[j + 1] = key;

      insert_sort(++i);
    });

  insert_sort();
}

std::int32_t binarySearch(Array &datas, std::int32_t target, std::int32_t low, std::int32_t high) {
  if (high <= low)
    return (target > datas[low]) ? (low + 1) : low;

  int mid = (low + high) / 2;

  if (target == datas[mid])
    return mid + 1;
  if (target > datas[mid])
    return binarySearch(datas, target, mid + 1, high);

  return binarySearch(datas, target, low, mid - 1);
}

void solution_3(Array &datas) {
  for (std::int32_t i = 1; i < datas.size(); ++i) {
    std::int32_t key = datas[i];

    std::int32_t j = i - 1;

    std::int32_t loc = binarySearch(datas, key, 0, j);
    while (j >= loc) {
      datas[j + 1] = datas[j];
      --j;
    }
    datas[j + 1] = key;
  }
}

int main(void) {
  solution_test({
    { solution_1, "solution_1" },
    { solution_2, "solution_2" },
    { solution_3, "solution_3" },
  });

  solution_benchmark({
    { solution_1, "solution_1" },
    { solution_2, "solution_2" },
    { solution_3, "solution_3" },
  });

  return EXIT_SUCCESS;
}
