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

void solution_2(Array &datas) {
  auto partition = make_y_combinator([&](auto partition, std::int32_t low, std::int32_t high) -> std::int32_t {
    std::int32_t L = low;
    std::int32_t R = high;
    std::int32_t P = datas[low];

    while (L < R) {
      while (L < R && datas[R] >= P) {
        --R;
      }

      while (L < R && datas[L] <= P) {
        ++L;
      }

      if (L < R) {
        std::swap(datas[L], datas[R]);
      }
    }

    std::swap(datas[low], datas[L]);

    return L;
  });

  auto quick_sort = make_y_combinator([&](auto quick_sort, std::int32_t low, std::int32_t high) {
    std::stack<std::int32_t> sk;

    if (low < high) {
      sk.push(high);
      sk.push(low);
    }

    while (!sk.empty()) {
      std::int32_t _low = sk.top(); sk.pop();
      std::int32_t _high = sk.top(); sk.pop();

      std::int32_t mid = partition(_low, _high);

      if (_low < mid - 1) {
        sk.push(mid - 1);
        sk.push(_low);
      }

      if (_high > mid + 1) {
        sk.push(_high);
        sk.push(mid + 1);
      }
    }
  });

  quick_sort(0, datas.size() - 1);
}

std::int32_t main (std::int32_t argc, char *argv[]) {
  solution_test({
    { solution_1, "solution_1" },
    { solution_2, "solution_2" },
  });

  solution_benchmark({
    { solution_1, "solution_1" },
    { solution_2, "solution_2" },
  });

  return 0;
}
