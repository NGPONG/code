#include "common.hpp"

static constexpr std::int32_t K = 10;

static bool flag1 = true;
static bool flag2 = true;

// =======================================================================================================================

// 采用快排的思想
// 因为快排的每一次 partition 都能够将数组的顺序重组为: mid 左边序列都是比 mid 大的，mid 右边序列都是比 pmid小的
// 由此，我们可以知道，当返回的 mid 下标刚好等于 k 值时，则意味着 mid 左边序列都是比右边大的，自此得到 TOP K
//
// 空间复杂度 O(1)，不需要额外空间
// 由于快速选择只需要递归一边的数组，时间复杂度小于快速排序，期望时间复杂度为 O(n)，最坏情况下的时间复杂度为 O(n^2)
void solutions_1_1(Array datas, std::int32_t k) {
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

    if (k < lt) {
      quick_sort(low, lt - 1);
    } else if (k > lt) {
      quick_sort(lt + 1, high);
    } else {
      return;
    }
  });

  quick_sort(0, datas.size() - 1);
}
static void BM_solutions_1_1(benchmark::State &state) {
  for (auto _ : state) {
    solutions_1_1(get_total_random_array(), K);
  }
}
BENCHMARK(BM_solutions_1_1);
// 三路快排的优化版本
void solutions_1_2(Array datas, std::int32_t k) {
  auto quick_sort = make_y_combinator([&](auto quick_sort, std::int32_t low, std::int32_t high) {
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

    if (k < lt) {
      quick_sort(low, lt - 1);
    } else if (k > gt) {
      quick_sort(gt, high);
    } else {
      return;
    }
  });

  quick_sort(0, datas.size() - 1);
}
static void BM_solutions_1_2(benchmark::State &state) {
  for (auto _ : state) {
    solutions_1_2(get_total_random_array(), K);
  }
}
BENCHMARK(BM_solutions_1_2);

// =======================================================================================================================

// step 2
// 采用小顶堆的思想
// 首先将前 k 个构造为大顶堆，该大顶堆的对顶维护的则为数组内前 k 项中最大的那一项。此时，数组前 k 项已经维护为一个堆，故
// 接下来我们需要从 k + 1 项往后遍历。如果其中某一项比堆顶元素要小，则将二者交换。由于交换后此时大顶堆内相当于出现了一个
// 相较于之前的新元素，所以大顶堆内部再执行一次 heapify 找出新的最大的一项到对顶。次过程循环至数组末尾此时大顶堆内部则装
// 有前 K 项的元素
//
// 这里要注意，这里并没有开启额外的空间来构建堆，而是在原来的数组的基础上进行，所以构造堆的过程中，要保证构造堆的元素区
// 间不会影响到 k + 1 个元素
//
// 空间复杂度 O(1)，不需要额外空间
//
// heapify 的时间复杂度为 O(logK)，由于可能会存在所有数字都需要进行一次 heapify 的情况，故最坏时间复杂度为 O(nlogK)
void solutions_2(Array datas, std::int32_t k) {
  auto heapify = make_y_combinator([&](auto heapify, std::int32_t n, std::int32_t i) -> void {
    std::int32_t child_l = i * 2 + 1;
    std::int32_t child_r = i * 2 + 2;

    std::int32_t larger = i;
    if (child_l <= n && datas[larger] < datas[child_l]) {
      larger = child_l;
    }
    if (child_r <= n && datas[larger] < datas[child_r]) {
      larger = child_r;
    }

    if (i != larger) {
      std::swap(datas[larger], datas[i]);
      heapify(n, larger);
    }
  });

  std::int32_t lst_idx = k - 1;

  for (std::int32_t parent = (lst_idx - 1) / 2; parent >= 0; --parent) {
    heapify(lst_idx, parent);
  }

  for (std::int32_t i = k; i < datas.size(); ++i) {
    if (datas[i] < datas[0]) {
      std::swap(datas[0], datas[i]);
      heapify(lst_idx, 0);
    }
  }
}
static void BM_solutions_2(benchmark::State &state) {
  for (auto _ : state) {
    solutions_2(get_total_random_array(), K);
  }
}
BENCHMARK(BM_solutions_2);

// =======================================================================================================================

// step 3
// 采用数据分片的大小，将数据再分片，然后分布式的进行运算，比如分成 10 份，每一份再执行一次 topk 运算，最后返回十份的 topk
// 数据，在这个数据的基础上再进行 topk 即可

// =======================================================================================================================

BENCHMARK_MAIN();
