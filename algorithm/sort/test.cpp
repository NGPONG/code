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

    std::swap(datas[i], datas[min]);
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
    if (max_val < datas[i]) {
      max_val = datas[i];
    }
  }
  max_val += 1;

  std::int32_t *count_arr = new std::int32_t[max_val]{ 0 };
  for (std::int32_t i = 0; i < datas.size(); ++i) {
    count_arr[datas[i]] += 1;
  }

  std::int32_t idx = 0;
  for (std::int32_t i = 0; i < max_val; ++i) {
    for (std::int32_t j = 0; j < count_arr[i]; ++j) {
      datas[idx++] = i;
    }
  }

  delete[] count_arr;
}

void solution_counting_sort(Array &datas) {
  std::int32_t max_val = datas[0];
  for (std::int32_t i = 0; i < datas.size(); ++i) {
    if (max_val < datas[i]) {
      max_val = datas[i];
    }
  }
  max_val += 1;

  std::int32_t *count_arr = new std::int32_t[max_val]{ 0 };
  std::int32_t *sort_arr  = new std::int32_t[datas.size()]{ 0 };

  for (std::int32_t i = 0; i < datas.size(); ++i) {
    count_arr[datas[i]] += 1;
  }

  for (std::int32_t i = 1; i < max_val; ++i) {
    count_arr[i] += count_arr[i - 1];
  }

  for (std::int32_t i = 0; i < datas.size(); ++i) {
    sort_arr[--count_arr[datas[i]]] = datas[i];
  }

  for (std::int32_t i = 0; i < datas.size(); ++i) {
    datas[i] = sort_arr[i];
  }

  delete[] count_arr;
  delete[] sort_arr;
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
      std::swap(datas[i], datas[larger]);
      heapify(n, larger);
    }
  });

  std::int32_t lst_idx = datas.size() - 1;

  for (std::int32_t parent = (lst_idx - 1) / 2; parent >= 0; --parent) {
    heapify(lst_idx, parent);
  }

  for (std::int32_t i = lst_idx; i > 0; --i) {
    std::swap(datas[0], datas[i]);
    heapify(i - 1, 0);
  }
}

void solution_quicksort_normal(Array &datas) {
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

void solution_quicksort_nonrecursive(Array &datas) {
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

  std::stack<std::int32_t> s;

  if (datas.size() > 1) {
    s.push(0);
    s.push(datas.size() - 1);
  }

  while (!s.empty()) {
    std::int32_t high = s.top(); s.pop();
    std::int32_t low  = s.top(); s.pop();

    std::int32_t mid = partition(low, high);

    if (low < mid - 1) {
      s.push(low);
      s.push(mid - 1);
    }

    if (high > mid + 1) {
      s.push(mid + 1);
      s.push(high);
    }
  }
}

void solution_quicksort_2way(Array &datas) {
  auto partition = [&](std::int32_t low, std::int32_t high) {
    std::swap(datas[low], datas[(low + high) / 2]);

    std::int32_t P = datas[low];

    std::int32_t lt = low;
    std::int32_t gt = high;

    while (lt < gt) {
      while (lt < gt && datas[gt] >= P) {
        --gt;
      }
      while (lt < gt && datas[lt] <= P) {
        ++lt;
      }
      if (lt < gt) {
        std::swap(datas[lt], datas[gt]);
      }
    }
    std::swap(datas[lt], datas[low]);

    return lt;
  };

  auto quick_sort = make_y_combinator([&](auto quick_sort, std::int32_t low, std::int32_t high) -> void {
    if (low >= high) {
      return;
    }

    std::int32_t mid = partition(low, high);

    quick_sort(low, mid - 1);
    quick_sort(mid + 1, high);
  });

  quick_sort(0, datas.size() - 1);
}

void solution_quicksort_3way_v1(Array &datas) {
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

void solution_merge_sort(Array &datas) {
  auto merge_split = make_y_combinator([&](auto merge_split, std::int32_t low, std::int32_t mid, std::int32_t high) -> void {
    std::int32_t left_size = mid - low;
    std::int32_t left[left_size];
    for (std::int32_t i = low; i < mid; ++i) {
      left[i - low] = datas[i];
    }

    std::int32_t right_size = high - mid + 1;
    std::int32_t right[right_size];
    for (std::int32_t i = mid; i <= high; ++i) {
      right[i - mid] = datas[i];
    }

    std::int32_t i = 0, j = 0, k = low;
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

  auto merge_sort = make_y_combinator([&](auto merge_sort, std::int32_t low, std::int32_t high) -> void {
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
    { solution_merge_sort,             "solution_merge_sort"             },
    { solution_quicksort_normal,       "solution_quicksort_normal"       },
    { solution_quicksort_nonrecursive, "solution_quicksort_nonrecursive" },
    { solution_quicksort_2way,         "solution_quicksort_2way"         },
    { solution_quicksort_3way_v1,      "solution_quicksort_3way_v1"      },
    { solution_heap_sort,              "solution_heap_sort"              },
    { solution_counting_sort,          "solution_counting_sort"          },
    { solution_bucket_sort,            "solution_bucket_sort"            },
    { solution_shell_sort,             "solution_shell_sort"             },
    { solution_insert_sort,            "solution_insert_sort"            },
    { solution_selection_sort,         "solution_selection_sort"         },
    { solution_bubble_sort,            "solution_bubble_sort"            },
  });

  solution_benchmark({
    { solution_merge_sort,             "solution_merge_sort"             },
    { solution_quicksort_normal,       "solution_quicksort_normal"       },
    { solution_quicksort_nonrecursive, "solution_quicksort_nonrecursive" },
    { solution_quicksort_2way,         "solution_quicksort_2way"         },
    { solution_quicksort_3way_v1,      "solution_quicksort_3way_v1"      },
    { solution_heap_sort,              "solution_heap_sort"              },
    { solution_counting_sort,          "solution_counting_sort"          },
    { solution_bucket_sort,            "solution_bucket_sort"            },
    { solution_shell_sort,             "solution_shell_sort"             },
    { solution_insert_sort,            "solution_insert_sort"            },
    { solution_selection_sort,         "solution_selection_sort"         },
    { solution_bubble_sort,            "solution_bubble_sort"            },
  });

  return 0;
}
