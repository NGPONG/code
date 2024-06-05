#include "common.hpp"

// 冒泡排序
//
// 时间复杂度：
//  * avg  ：O(n^2)
//  * worst: O(n^2)
//  * best : O(n^2)
//
// 信息：
// * 冒泡排序，有时也称为下沉排序，是一种就地的、稳定的且自适应（优化后）排序算法。它逐元素重
// 复地遍历输入列表，将当前元素与其后的元素进行比较，如果需要则交换它们的值。这些对列表的遍历
// 会重复进行，直到在一次遍历期间不需要执行任何交换，这意味着列表已完全排序。这种比较排序的算
// 法是根据较大的元素 “冒” 到列表顶部/底部的方式而命名的。
//
// * 冒泡排序与现代 CPU硬件的交互性很差。它产生的写入次数至少是插入排序的两倍，缓存缺失次数是
// 插入排序的两倍，分支误预测次数也逐渐增多。 在 Java 中对字符串进行排序的实验表明，冒泡排序的
// 速度大约是插入排序的五分之一，是选择排序的 70%。
//
// * 在冒泡排序中，元素在排序过程中的移动方向和距离决定了该算法的性能。一个需要移到列表末尾的元
// 素可以通过连续交换迅速到达其位置，而需要移到列表开头的元素则移动较慢，因为每次只能移动一步。
// 如果列表末尾是最小元素，则需要 𝑛 − 1 次交换才能将其移到开头。这个现象导致这些元素分别被称为
// “兔子” 和“乌龟”，来源于《龟兔赛跑》的寓言故事。
//
// * 在持续循环的过程中可能数列已排序，那么此时我们就不需要继续往下进行。为实现这一点，我们可
// 以通过一个标志并在单次循环的过程中判断列表是否有序。如果列表已有序，则可以直接退出不用再
// 重复后续的过程，最佳时间复杂度能优化到 O(n)；如果没有则退回到冒泡排序的时间复杂度上。
//
// * 鸡尾酒算法是一种冒泡排序的变体。相较于原始的排序，其扩展了双向步进操作元素的顺序以提升了
// 性能的改进。需要意识到，这种性能提升是有限的，这是因为该算法并限制的减少所需的循环次数，
// 相反，由于双向遍历的特性这使得再处理某些情况下时该算法能有显著的优势，例如：设一个列表为
// (2,3,4,5,1)，那么鸡尾酒排序由于双向排序的原因，其仅需一次操作就可使列表为有序的；而冒泡
// 排序必须经过四次循环遍历。另外一点，更优的写法使得编译器、缓存、流水线拥有更多的优化空间。

// 原始实现
void solution_1(Array &datas) {
  for (std::size_t i = 0; i < datas.size(); ++i) {
    for (std::size_t j = 0; j < datas.size() - i - 1; ++j) {
      if (datas[j] > datas[j + 1]) {
        std::swap(datas[j], datas[j + 1]);
      }
    }
  }
}

// 鸡尾酒算法优化
void solution_2(Array &datas) {
  std::int32_t left = 0, right = datas.size() - 1;

  while (left < right) {
    for (size_t i = left; i < right; i++) {
      if (datas[i] > datas[i + 1]) {
        std::swap(datas[i], datas[i + 1]);
      }
    }
    right--;

    for (size_t i = right; i > left; i--) {
      if (datas[i - 1] > datas[i]) {
        std::swap(datas[i], datas[i - 1]);
      }
    }
    left++;
  }
}

// 提前结束优化：避免没必要的迭代
void solution_3(Array &datas) {
  for (size_t i = 0; i < datas.size(); i++) {
    bool is_swapped = false;

    for (size_t j = 0; j < datas.size() - i - 1; j++) {
      if (datas[j] > datas[j + 1]) {
        std::swap(datas[j], datas[j + 1]);
        is_swapped = true;
      }
    }

    if (!is_swapped) {
      break;
    }
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

  return 0;
}
