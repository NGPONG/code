#include "common.hpp"

void insertsort(Array &datas, std::int32_t begin, std::int32_t end) {
  for (std::int32_t i = begin; i <= end; ++i) {
    std::int32_t min = i;

    for (std::int32_t j = i + 1; j <= end; ++j) {
      if (datas[min] > datas[j]) {
        min = j;
      }
    }

    std::swap(datas[min], datas[i]);
  }
}

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

void solution_3(Array &datas) {
  auto quick_sort = make_y_combinator([&](auto quick_sort, std::int32_t low, std::int32_t high) -> void {
    if (low >= high) {
      return;
    }

    std::int32_t P = datas[low];

    std::int32_t lt = low;
    std::int32_t i = low + 1;

    while (i <= high) {
      if (datas[i] <= P) {
        std::swap(datas[i], datas[lt + 1]);
        ++lt;
      }

      ++i;
    }
    for (std::int32_t i = lt + 1; i <= high; ++i) {
      if (datas[i] <= P) {
        std::swap(datas[i], datas[lt + 1]);
        ++lt;
      }
    }

    std::swap(datas[low], datas[lt]);

    quick_sort(low, lt - 1);
    quick_sort(lt + 1, high);
  });

  quick_sort(0, datas.size());
}

void solution_4(Array &datas) {
  auto quick_sort = make_y_combinator([&](auto quick_sort, std::int32_t low, std::int32_t high) -> void {
    if (high - low <= 15) {
      insertsort(datas, low, high);
      return;
    }

    std::swap(datas[low], datas[std::rand() % (high - low + 1) + low]);

    std::int32_t P = datas[low];

    std::int32_t lt = low;
    std::int32_t gt = high + 1;
    std::int32_t i = low + 1;

    while (i < gt) {
      if (datas[i] < P) {
        std::swap(datas[i], datas[lt + 1]);
        i++;
        lt++;
      } 
      else if (datas[i] > P) {
        std::swap(datas[i], datas[gt - 1]);
        gt--;
      }
      else {
        i++;
      }
    }

    std::swap(datas[lt], datas[low]);

    quick_sort(low, lt - 1);
    quick_sort(lt + 1, high);
  });

  quick_sort(0, datas.size() - 1);
}

std::int32_t main (std::int32_t argc, char *argv[]) {
  std::srand(std::time(NULL));

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
