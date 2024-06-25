#include "common.hpp"

void insertsort(Array &datas, std::int32_t low, std::int32_t high) {
  for (std::int32_t i = low; i <= high; ++i) {
    std::int32_t min = i;

    for (std::int32_t j = i + 1; j <= high; ++j) {
      if (datas[min] > datas[j]) {
        min = j;
      }
    }

    std::swap(datas[min], datas[i]);
  }
}

// 双向快速排序
void solution_1(Array &datas) {
  auto quick_sort = make_y_combinator([&](auto quick_sort, std::int32_t low, std::int32_t high) -> void {
    if (low >= high) {
      return;
    }

    std::int32_t p = datas[low];

    std::int32_t lt = low, gt = high;
    while (lt < gt) {
      while (lt < gt && datas[gt] >= p) {
        --gt;
      }
      while (lt < gt && datas[lt] <= p) {
        ++lt;
      }
      if (lt < gt) {
        std::swap(datas[lt], datas[gt]);
      }
    }
    std::swap(datas[lt], datas[low]);

    // datas[low...lt-1] <= datas[lt] <= datas[lt+1...high]

    quick_sort(low, lt - 1);
    quick_sort(lt + 1, high);
  });

  quick_sort(0, datas.size() - 1);
}

// 无递归快速排序
void solution_2(Array &datas) {
  auto partition = make_y_combinator([&](auto partition, std::int32_t low, std::int32_t high) -> std::int32_t {
    std::int32_t p = datas[low];

    std::int32_t lt = low, gt = high;
    while (lt < gt) {
      while (lt < gt && datas[gt] >= p) {
        --gt;
      }
      while (lt < gt && datas[lt] <= p) {
        ++lt;
      }
      if (lt < gt) {
        std::swap(datas[lt], datas[gt]);
      }
    }
    std::swap(datas[lt], datas[low]);

    return lt;
  });

  auto quick_sort = make_y_combinator([&](auto quick_sort, std::int32_t low, std::int32_t high) {
    std::stack<std::int32_t> sk;

    if (low < high) {
      sk.push(low);
      sk.push(high);
    }

    while (!sk.empty()) {
      std::int32_t _high = sk.top();
      sk.pop();
      std::int32_t _low = sk.top();
      sk.pop();

      std::int32_t mid = partition(_low, _high);

      if (_low < mid - 1) {
        sk.push(_low);
        sk.push(mid - 1);
      }

      if (_high > mid + 1) {
        sk.push(mid + 1);
        sk.push(_high);
      }
    }
  });

  quick_sort(0, datas.size() - 1);
}

// 单向快速排序
void solution_3(Array &datas) {
  auto quick_sort = make_y_combinator([&](auto quick_sort, std::int32_t low, std::int32_t high) -> void {
    if (low >= high) {
      return;
    }

    std::int32_t p = datas[low];

    std::int32_t lt = low, i = low + 1;
    while (i <= high) {
      if (datas[i] <= p) {
        std::swap(datas[i], datas[++lt]);
      }
      ++i;
    }
    std::swap(datas[low], datas[lt]);

    quick_sort(low, lt - 1);
    quick_sort(lt + 1, high);
  });

  quick_sort(0, datas.size() - 1);
}

// 三向快速排序
void solution_4(Array &datas) {
  auto quick_sort = make_y_combinator([&](auto quick_sort, std::int32_t low, std::int32_t high) -> void {
    if (low >= high) {
      return;
    }

    std::int32_t p = datas[low];

    std::int32_t lt = low, gt = high + 1, i = low + 1;
    while (i < gt) {
      if (datas[i] < p) {
        std::swap(datas[i++], datas[lt++]);
      } else if (datas[i] > p) {
        std::swap(datas[i], datas[--gt]);
      } else {
        i++;
      }
    }

    quick_sort(low, lt - 1);
    quick_sort(gt, high);
  });

  quick_sort(0, datas.size() - 1);
}

// 双向快速排序（优化pivot的选择）
void solution_5(Array &datas) {
  // 该函数将序列分布为：mid...high...low
  auto select_pivot = make_y_combinator([&](auto select_pivot, std::int32_t low, std::int32_t high) -> void {
    std::int32_t mid = (low + high) / 2;

    if (datas[mid] < datas[high]) {
      std::swap(datas[mid], datas[high]);
    }

    if (datas[low] < datas[high]) {
      std::swap(datas[low], datas[high]);
    }

    if (datas[mid] < datas[low]) {
      std::swap(datas[mid], datas[low]);
    }
  });

  auto quick_sort = make_y_combinator([&](auto quick_sort, std::int32_t low, std::int32_t high) -> void {
    if (low >= high) {
      return;
    }

    select_pivot(low, high);

    std::int32_t p = datas[low];

    std::int32_t lt = low, gt = high;
    while (lt < gt) {
      while (lt < gt && datas[gt] >= p) {
        --gt;
      }
      while (lt < gt && datas[lt] <= p) {
        ++lt;
      }
      if (lt < gt) {
        std::swap(datas[lt], datas[gt]);
      }
    }
    std::swap(datas[lt], datas[low]);

    quick_sort(low, lt - 1);
    quick_sort(lt + 1, high);
  });

  quick_sort(0, datas.size() - 1);
}
void solution_6(Array &datas) {
  auto select_pivot = make_y_combinator([&](auto select_pivot, std::int32_t low, std::int32_t high) -> void {
  std::int32_t mid = (low + high) / 2;
  
  if (datas[high] < datas[low]) {
    std::swap(datas[high], datas[low]);
  }
  
  if (datas[high] < datas[mid]) {
    std::swap(datas[high], datas[mid]);
  }
  
  if (datas[high] < datas[mid]) {
    std::swap(datas[mid], datas[high]);
  }
  });

  auto quick_sort = make_y_combinator([&](auto quick_sort, std::int32_t low, std::int32_t high) -> void {
    if (low >= high) {
      return;
    }

    select_pivot(low, high);

    std::int32_t p = datas[low];

    std::int32_t lt = low, gt = high;
    while (lt < gt) {
      while (lt < gt && datas[gt] >= p) {
        --gt;
      }
      while (lt < gt && datas[lt] <= p) {
        ++lt;
      }
      if (lt < gt) {
        std::swap(datas[lt], datas[gt]);
      }
    }
    std::swap(datas[lt], datas[low]);

    quick_sort(low, lt - 1);
    quick_sort(lt + 1, high);
  });

  quick_sort(0, datas.size() - 1);
}
void solution_7(Array &datas) {
  auto fix_pivot = make_y_combinator([&](auto fix_pivot, std::int32_t low, std::int32_t high) -> void {
    std::int32_t mid = (low + high) / 2;

    std::int32_t l = datas[low];
    std::int32_t m = datas[mid];
    std::int32_t r = datas[high];

    if ((l <= m && m <= r) || (r <= m && m <= l)) {
      std::swap(datas[low], datas[mid]);
    } else if ((l <= r && r <= m) || (m <= r && r <= l)) {
      std::swap(datas[low], datas[high]);
    }
  });

  auto quick_sort = make_y_combinator([&](auto quick_sort, std::int32_t low, std::int32_t high) -> void {
    if (low >= high) {
      return;
    }

    fix_pivot(low, high);

    std::int32_t pivot = datas[low];

    std::int32_t lt = low, gt = high;
    while (lt < gt) {
      while (lt < gt && datas[gt] >= pivot) {
        --gt;
      }
      while (lt < gt && datas[lt] <= pivot) {
        ++lt;
      }
      if (lt < gt) {
        std::swap(datas[lt], datas[gt]);
      }
    }
    std::swap(datas[low], datas[lt]);

    quick_sort(low, lt - 1);
    quick_sort(lt + 1, high);
  });

  quick_sort(0, datas.size() - 1);
}

std::int32_t main(std::int32_t argc, char *argv[]) {
  std::srand(std::time(NULL));

  solution_test({
    // { solution_1, "solution_1" },
    // { solution_2, "solution_2" },
    // { solution_3, "solution_3" },
    // { solution_4, "solution_4" },
    // { solution_5, "solution_5" },
    // { solution_6, "solution_6" },
    // { solution_7, "solution_7" },
  });

  solution_benchmark({
    // { solution_1, "solution_1" },
    // { solution_2, "solution_2" },
    // { solution_3, "solution_3" },
    // { solution_4, "solution_4" },
    // { solution_5, "solution_5" },
    // { solution_6, "solution_6" },
    // { solution_7, "solution_7" },
  });

  return 0;
}
