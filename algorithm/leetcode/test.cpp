#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
  void heapify(std::vector<int>& datas, int n, int i) {
    int child_l = i * 2 + 1;
    int child_r = i * 2 + 2;

    int larger = i;
    if (child_l <= n && datas[larger] < datas[child_l]) {
      larger = child_l;
    }
    if (child_r <= n && datas[larger] < datas[child_r]) {
      larger = child_r;
    }

    if (i != larger) {
      std::swap(datas[larger], datas[i]);
      heapify(datas, n, larger);
    }
  }

  std::vector<int> topKFrequent(std::vector<int>& datas, int k) {
    int max_val = datas[0];
    for (int i = 1; i < datas.size(); ++i) {
      if (datas[i] > max_val) {
        max_val = datas[i];
      }
    }
    max_val += 1;

    int *count_arr = new int[max_val];
    for (int i = 0; i < datas.size(); ++i) {
      count_arr[datas[i]] += 1;
    }
    
    

    return datas;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> datas = { 1,1,1,2,2,3 }; 

  Solution sol;
  auto v = sol.topKFrequent(datas, 2);

  return 0;
}
