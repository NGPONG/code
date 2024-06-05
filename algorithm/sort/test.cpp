#include "common.hpp"

void solution_bubble_sort(Array &datas) {
  for (std::int32_t i = 0; i < datas.size(); ++i) {
    for (std::int32_t j = 0; j < datas.size() - i - 1; ++j) {
      if (datas[j] > datas[j + 1]) {
        std::swap(datas[j], datas[j + 1]);
      }
    }
  }
}

void solution_selection_sort(Array &datas) {
  for (std::int32_t i = 0; i < datas.size(); ++i) {
    std::int32_t min = i;

    for (std::int32_t j = i + 1; j < datas.size(); ++j) {
      if (datas[min] > datas[j]) {
        min = j;
      }
    }

    std::swap(datas[min], datas[i]);
  }
}

void solution_insert_sort(Array &datas) {
  for (std::int32_t i = 1; i < datas.size(); ++i) {
    std::int32_t key = datas[i];

    std::int32_t j = i - 1;
    for (; j >= 0 && key < datas[j]; --j) {
      datas[j + 1] = datas[j];
    }

    datas[j + 1] = key;
  }
}

void solution_shell_sort(Array &datas) {
  for (std::int32_t gs = datas.size() / 2; gs > 0; gs /= 2) {
    for (std::int32_t i = gs; i < datas.size(); ++i) {
      std::int32_t key = datas[i];

      std::int32_t j = i;
      for (; j >= gs && key < datas[j - gs]; j -= gs) {
        datas[j] = datas[j - gs];
      }

      datas[j] = key;
    }
  }
}

void solution_bucket_sort(Array &datas) {
  std::int32_t max_val = datas[0];
  for (std::int32_t i = 0; i < datas.size(); ++i) {
    if (datas[i] > max_val) {
      max_val = datas[i];
    }
  }
  max_val += 1;

  std::int32_t *count_datas = new std::int32_t[max_val] { 0 };
  for (std::int32_t i = 0; i < datas.size(); ++i) {
    count_datas[datas[i]] += 1;
  }

  std::int32_t idx = 0;
  for (std::int32_t i = 0; i < max_val; ++i) {
    for (std::int32_t j = 0; j < count_datas[i]; ++j) {
      datas[idx++] = i;
    }
  }

  delete[] count_datas;
}

void solution_counting_sort(Array &datas) {
  std::int32_t max_val = datas[0];
  for (std::int32_t i = 0; i < datas.size(); ++i) {
    if (datas[i] > max_val) {
      max_val = datas[i];
    }
  }
  max_val += 1;

  std::int32_t *count_datas = new std::int32_t[max_val] { 0 };
  std::int32_t *sort_datas = new std::int32_t[datas.size()] { 0 };

  for (std::int32_t i = 0; i < datas.size(); ++i) {
    count_datas[datas[i]] += 1;
  }

  for (std::int32_t i = 1; i < max_val; ++i) {
    count_datas[i] += count_datas[i - 1];
  }

  for (std::int32_t i = 0; i < datas.size(); ++i) {
    sort_datas[--count_datas[datas[i]]] = datas[i];
  }

  for (std::int32_t i = 0; i < datas.size(); ++i) {
    datas[i] = sort_datas[i];
  }

  delete[] count_datas;
  delete[] sort_datas;
}

void solution_heap_sort(Array &datas) {
  auto heapify = make_y_combinator([&](auto heapify, std::int32_t n, std::int32_t i) -> void {
    std::int32_t child_l = i * 2 + 1;
    std::int32_t child_r = i * 2 + 2;

    std::int32_t larger = i;
    if (child_l <= n && datas[child_l] > datas[larger]) {
      larger = child_l;
    }
    if (child_r <= n && datas[child_r] > datas[larger]) {
      larger = child_r;
    }

    if (larger != i) {
      std::swap(datas[larger], datas[i]);
      heapify(n, larger);
    }
  });

  std::int32_t lst_idx = datas.size() - 1;
  std::int32_t lst_pat = (lst_idx - 1) / 2;

  for (std::int32_t i = lst_pat; i >= 0; --i) {
    heapify(lst_idx, i);
  }

  for (std::int32_t i = lst_idx; i > 0; --i) {
    std::swap(datas[0], datas[i]);
    heapify(i - 1, 0);
  }
}

void solution_quick_sort(Array &datas) {
  auto quick_sort = make_y_combinator([&](auto quick_sort, std::int32_t low, std::int32_t high) -> void {
    if (low >= high) {
      return;
    }

    std::int32_t L = low;
    std::int32_t R = high;
    std::int32_t P = datas[low];

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

    std::swap(datas[L], datas[low]);

    quick_sort(low, L - 1);
    quick_sort(L + 1, high);
  });

  quick_sort(0, datas.size() - 1);
}

void solution_merge_sort(Array &datas) {
  auto merge_split = make_y_combinator([&](auto merge_split, std::int32_t L, std::int32_t M, std::int32_t R) {
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

  auto merge_sort = make_y_combinator([&](auto merge_sort, std::int32_t low, std::int32_t high) -> void{
    if (low >= high) {
      return;
    }

    std::int32_t mid = (low + high) / 2;
    merge_sort(low, mid);
    merge_sort(mid + 1, high);

    merge_split(low, mid + 1, high);
  });

  merge_sort(0, datas.size() - 1);
}

std::int32_t main(void) {
  solution_test({
    { solution_merge_sort,     "solution_merge_sort"     },
    { solution_quick_sort,     "solution_quick_sort"     },
    { solution_heap_sort,      "solution_heap_sort"      },
    { solution_counting_sort,  "solution_counting_sort"  },
    { solution_bucket_sort,    "solution_bucket_sort"    },
    { solution_shell_sort,     "solution_shell_sort"     },
    { solution_insert_sort,    "solution_insert_sort"    },
    { solution_selection_sort, "solution_selection_sort" },
    { solution_bubble_sort,    "solution_bubble_sort"    },
  });

  solution_benchmark({
    { solution_merge_sort,     "solution_merge_sort"     },
    { solution_quick_sort,     "solution_quick_sort"     },
    { solution_heap_sort,      "solution_heap_sort"      },
    { solution_counting_sort,  "solution_counting_sort"  },
    { solution_bucket_sort,    "solution_bucket_sort"    },
    { solution_shell_sort,     "solution_shell_sort"     },
    { solution_insert_sort,    "solution_insert_sort"    },
    { solution_selection_sort, "solution_selection_sort" },
    { solution_bubble_sort,    "solution_bubble_sort"    },
  });

  return 0;
}
