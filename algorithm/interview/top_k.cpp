#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>

using namespace std;

#define SWAP(x, y) \
  if (x != y) {    \
    x = x ^ y;     \
    y = x ^ y;     \
    x = x ^ y;     \
  }
#define TOP_K 5

std::vector<int> random_nums() {
  std::vector<int> ret;
  std::unordered_map<int, bool> cont;
  
  srand((unsigned)time(NULL));
  for (int i = 0; i < 200000; ++i) {
    int num = rand() % 200000;
    if (cont.find(num) != cont.end()) {
      --i;
      continue;
    }

    ret.push_back(num);
    cont[num] = true;
  }

  return ret;
}

int partition(int left, int right, vector<int> &arrary) {
  int i = left, j = right, pivot = arrary[left];
  while (i != j) {
    while (i < j && arrary[j] <= pivot) {
      --j;
    }
    while (i < j && arrary[i] >= pivot) {
      ++i;
    }
    if (i < j) {
      SWAP(arrary[i], arrary[j]);
    }
  }

  int mid = i;
  arrary[left] = arrary[mid];
  arrary[mid] = pivot;

  return mid;
}
int quick_sort(int low, int high, vector<int> &arrary) {
  int mid = partition(low, high, arrary);
  if (TOP_K == mid) {
    return mid;
  } else if (TOP_K < mid) {
    return quick_sort(low, mid - 1, arrary);
  } else {
    return quick_sort(mid + 1, high, arrary);
  }
}

void heapify(int last_idx, int cur_node_idx, vector<int> &arrary) {
  int min = cur_node_idx;

  int c_1 = cur_node_idx * 2 + 1;
  if (c_1 <= last_idx && arrary[c_1] < arrary[min]) {
    min = c_1;
  }

  int c_2 = cur_node_idx * 2 + 2;
  if (c_2 <= last_idx && arrary[c_2] < arrary[min]) {
    min = c_2;
  }

  if (min != cur_node_idx) {
    SWAP(arrary[min], arrary[cur_node_idx]);
    heapify(last_idx, min, arrary);
  }
}
void built_heap(vector<int> &arrary) {
  int last_idx = TOP_K - 1;
  int parent = (last_idx - 1) / 2;

  for (; parent >= 0; --parent) {
    heapify(last_idx, parent, arrary);
  }
}
void heap_sort(vector<int> &arrary) {
  built_heap(arrary);

  for (int i = TOP_K; i < arrary.size(); ++i) {
    if (arrary[i] > arrary[0]) {
      SWAP(arrary[i], arrary[0]);
      heapify(TOP_K - 1, 0, arrary);
    }
  }
}

int main(void) {
  vector<int> &&arrary = random_nums(); // {3, 6, 7, 9, 5, 4, 1, 2, 8};



  clock_t start, end;
  start = clock();
  
  // step 1
  // 采用快排的思想
  // 因为快排的每一次 partition 都能够将数组的顺序重组为: mid 左边序列都是比 mid 大的，mid 右边序列都是比 pmid小的
  // 由此，我们可以知道，当返回的 mid 下标刚好等于 k 值时，则意味着 mid 左边序列都是比右边大的，自此得到 TOP K
  //
  // 空间复杂度 O(1)，不需要额外空间
  // 由于快速选择只需要递归一边的数组，时间复杂度小于快速排序，期望时间复杂度为 O(n)，最坏情况下的时间复杂度为 O(n^2)
  quick_sort(0, arrary.size() - 1, arrary);
  for (int i = 0; i < TOP_K; ++i) {
    cout << arrary[i] << endl;
  }

  end = clock();
  cout << end - start << endl;



  arrary = random_nums();

  start = clock();
  
  // step 2
  // 采用小顶堆的思想
  // 首先将前 k 个构造为小顶堆，由于小顶堆的堆顶元素在堆中最小，所以我们再从数组的第 K + 1 个元素和堆顶元素进行对比，如果
  // 比他大则替换掉，然后继续依照这个小顶堆做 heapify 来调整堆即可
  // 这里要注意，这里并没有开启额外的空间来构建堆，而是在原来的数组的基础上进行，所以构造堆的过程中，要保证构造堆的元素区
  // 间不会影响到 k + 1 个元素
  //
  // 空间复杂度 O(1)，不需要额外空间
  // heapify 的时间复杂度为 O(logK)，由于可能会存在所有数字都需要进行一次 heapify 的情况，故最坏时间复杂度为 O(nlogK)
  heap_sort(arrary);
  for (int i = 0; i < TOP_K; ++i) {
    cout << arrary[i] << endl;
  }

  end = clock();
  cout << end - start << endl;

  
  // step 3
  // 采用数据分片的大小，将数据再分片，然后分布式的进行运算，比如分成 10 份，每一份再执行一次 topk 运算，最后返回十份的 topk
  // 数据，在这个数据的基础上再进行 topk 即可

  return EXIT_SUCCESS;
}
