#include <iostream>
#include <vector>
#include <queue>

// 题目: 在一个无序数组中寻找中位数
//
// 将数据平均分配到最大堆和最小堆中，并且保证最小堆中的数据存放的数据都比
// 最大堆中是数据大，那么此时最小堆堆顶的元素一定是中位数
//
// 如何平均分配元素?
//  * 遍历数组，将基数下标的元素纳入最小堆，将复数下标的元素纳入最大堆

struct greater {
  bool operator()(int x, int y) {
    return x > y;
  }
};

int main(void) {
  std::vector<int> unorder_arr = {  2, 4, 3, 1, 7, 9, 5, 8, 6, 10, 0, 13 };

  std::priority_queue<int> max_heap;
  std::priority_queue<int, std::vector<int>, greater> min_heap;

  for (int i = 0; i < unorder_arr.size(); ++i) {
    // 平均分配元素
    // 将基数下标的元素纳入最小堆
    // 将复数下标的元素纳入最大堆
    //
    // 由于下标是从 0 开始的，所以最小堆的 size 是大与最小堆的
    if ((i & 1) == 1) {
      min_heap.push(unorder_arr[i]);
    } else {
      max_heap.push(unorder_arr[i]);
    }
    if (min_heap.empty() || max_heap.empty()) continue;

    // 交换大小堆顶种的内容
    // 使最小堆中装载最大堆的最大
    // 使最大堆中装载最小堆的最小
    //
    // 简而言之，就是使最小堆中的数据都比最大堆中的大
    min_heap.push(max_heap.top());
    max_heap.pop();
    max_heap.push(min_heap.top());
    min_heap.pop();
  }

  std::cout << min_heap.top() << std::endl;

  return EXIT_SUCCESS;
}
