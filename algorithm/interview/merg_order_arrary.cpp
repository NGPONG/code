#include <iostream>
#include <vector>

using namespace std;

// 题目: 合并两个有序的数组
//
// 该算法参考归并排序在合并 left 和 right 时的操作即可

vector<int> merge_sort_arrary(vector<int> a, vector<int> b) {
  vector<int> ret;
  int i = 0;
  int j = 0;
  while (i < a.size() && j < b.size()) {
    if (a[i] < b[j]) {
      ret.push_back(a[i++]);
    } else {
      ret.push_back(b[j++]);
    }
  }

  while (i < a.size()) ret.push_back(a[i++]);
  while (j < b.size()) ret.push_back(b[j++]);

  return ret;
}

int main(void) {
  vector<int> a = { 1, 3, 5, 6, 7, 8 };
  vector<int> b = { 2, 4, 6 };

  vector<int> c = merge_sort_arrary(a, b);
  for (auto i = c.begin(); i < c.end(); ++i) {
    cout << *i << endl;
  }

  return EXIT_SUCCESS;
}
