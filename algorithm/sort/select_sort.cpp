#include "common.hpp"

// 选择排序
//
// 时间复杂度：
//  * avg  ：O(n^2)
//  * worst: O(n^2)
//  * best : O(n^2)
//
// 信息：
//  * 选择排序是一种就地的不稳定非自适应（原始状态下）排序算法。该算法将输入列表分为两部分：在列表前部（左侧）从
//  左到右建立的已排序项子列表，以及占据列表其余部分的未排序项子列表。最初，排序子列表是空的，未排序子列表是整个
//  输入列表。算法的步骤是找到未排序子列表中最小（或最大，取决于排序顺序）的元素，将其与最左边的最后一个未排序元
//  素交换（对调），重复至未排序子项为空时，排序则结束。
//
// 比较：
//  * 在二次方的排序算法中，选择排序几乎总是优于冒泡排序和侏儒排序。插入排序与此非常相似，在第 k 次迭代后，数组
//  中的前 𝑘 个元素将按排序顺序排列。插入排序的优势在于，它只需要扫描尽可能多的元素就能够放置第 K + 1 个元素；而
//  选择排序则反之，必须扫描所有剩余元素以找到第 𝑘 + 1 个元素。
//
//  * 简单的计算表明，插入排序执行的比较次数通常是选择排序的一半左右，不过根据排序前数组的顺序，它执行的比较次数
//  可能一样多，也可能少得多。对于某些实时应用程序来说，无论数组的顺序如何，选择排序的执行次数都是相同的，而插入
//  排序的运行时间可能会有很大差异，这可以看作是一种优势。
//
//  * 在写操作次数上，选择排序（n-1次交换，即2(n-1)次写入）优于插入排序（n(n−1)/2次移动）。但这大约是循环排序达到
//  的理论最小值的两倍，循环排序最多进行 n 次写入。如果写入比读取昂贵得多，比如 EEPROM 或 Flash 存储器，每次写入都
//  会缩短存储器的寿命，这一点可能很重要。
//
//  * 选择排序可以通过无预测的分支实现以使 CPU 分支预测器受益，方法是使用无分支代码找到最小值的位置，然后无条件地
//  执行交换。参照 solution_3，虽然可能不是最佳实现。
//
//  * 在较大的数组上由于常数因子太大导致选择/插入排序表现不佳；然而更小的内存开销、更小的尝试因子、更简单的缓存友
//  好实现使得对于较小数组（小于10~20个元素）普遍采用选择/插入排序的实现。
//
//  * 如果不执行交换而是插入到最后一个未排序元素的位置上，并将中间值同步上移，那么我们就能得到一个稳定的选择排序。
//  然而这种修改要么需要一个支持高效插入或删除的数据结构（如链表），要么会导致执行退化为 O(n^2) 的写入。
//
//  * 双向选择排序是一种优化方向。在每个步骤中需要同时找到最大值与最小值并执行矫正操作。与普通选择排序的每个元素执
//  行一次比较相比，双向选择排序每两个元素需要进行三次比较（将较大的元素与最大值比较，将较小的元
//  素与最小值比较，然后再比较这一对元素），但所需的次数只有普通选择排序的一半，净节省 25%。

void solution_1(Array &datas) {
  for (std::size_t i = 0; i < datas.size(); ++i) {
    std::int32_t max = i;

    for (std::size_t j = i + 1; j < datas.size(); ++j) {
      if (datas[max] > datas[j]) {
        max = j;
      }
    }

    std::swap(datas[i], datas[max]);
  }
}

void solution_2(Array &datas) {
  std::int32_t l = 0, r = datas.size() - 1;

  while (l < r) {
    std::int32_t min = l;
    for (size_t i = l + 1; i <= r; i++) {
      if (datas[i] < datas[min]) {
        min = i;
      }
    }
    std::swap(datas[min], datas[l]);

    std::int32_t max = r;
    for (std::size_t j = r - 1; j > l; --j) {
      if (datas[j] > datas[max]) {
        max = j;
      }
    }
    std::swap(datas[max], datas[r]);

    ++l;
    --r;
  }
}

void solution_3(Array &datas) {
  for (size_t i = 0; i < datas.size(); i++) {
    std::size_t min = i;

    for (size_t j = i + 1; j < datas.size(); j++) {
      std::int32_t diff = datas[j] - datas[min];
      std::int32_t mask = diff >> 31;
      min               = (min & ~mask) | (j & mask);
    }

    std::swap(datas[i], datas[min]);
  }
}

void solution_4(Array &datas) {
  std::int32_t left = 0, right = datas.size() - 1;

  while (left < right) {
    std::int32_t min = left, max = right;

    for (size_t i = left; i <= right; i++) {
      if (datas[i] < datas[min]) {
        min = i;
      }

      if (datas[i] > datas[max]) {
        max = i;
      }
    }

    std::swap(datas[left], datas[min]);

    if (max == left) {
      max = min;
    }

    std::swap(datas[right], datas[max]);

    ++left;
    --right;
  }
}

int main(void) {
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

  return EXIT_SUCCESS;
}
