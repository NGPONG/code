#include "common.hpp"

// * 题目：
//  给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

// 堆实现
std::vector<std::int32_t> solutions_1(std::vector<std::int32_t> datas, std::int32_t k) {
  // 0x1 统计元素出现的次数至map当中
  std::unordered_map<std::int32_t, std::int32_t> hs;
  for (std::int32_t i = 0; i < datas.size(); ++i) {
    ++hs[datas[i]];
  }

  // 0x2: 初始化优先队列（小顶堆）
  auto cmp = [&](auto& lhs, auto& rhs) {
    return lhs.second > rhs.second;
  };
  std::priority_queue<pair_i_i, std::vector<pair_i_i>, decltype(cmp)> heap(cmp);

  // 0x3: 遍历map
  for (auto& [num, cnt] : hs) {
    if (heap.size() >= k) {
      // 0x5: 如果存在元素比堆顶元素大，则替换堆顶元素并重新执行heapify以将新的最小元素放置在堆顶
      if (cnt > heap.top().second) {
        heap.pop();
        heap.push({ num, cnt });
      }
    } else {
      // 0x4: 使用前K个元素去构建小顶堆；当构建完毕后堆顶为前K个元素最小
      heap.emplace(num, cnt);
    }
  }

  std::vector<std::int32_t> ret;
  while (!heap.empty()) {
    ret.emplace_back(heap.top().first);
    heap.pop();
  }

  return ret;
}

// 计数排序实现
std::vector<std::int32_t> solutions_2(std::vector<std::int32_t>& datas, std::int32_t k) {
  // 0x1: 统计元素出现的次数至map当中
  std::unordered_map<std::int32_t, std::int32_t> hs;
  for (std::int32_t i = 0; i < datas.size(); ++i) {
    ++hs[datas[i]];
  }

  // 0x2: 
  std::map<std::int32_t, std::queue<std::int32_t>> m;
  for (auto& [num, cnt] : hs) {
    m[cnt].push(num);
  }

  std::vector<std::int32_t> ret;

  std::int32_t idx = 0;
  for (auto it = m.rbegin(); it != m.rend(); ++it) {
    while (!it->second.empty()) {
      if (idx++ >= k) {
        return ret;
      }

      ret.emplace_back(it->second.front());
      it->second.pop();
    }
  }

  return ret;
}

std::int32_t main(std::int32_t argc, char* argv[]) {
  std::vector<std::int32_t> datas = { 4, 1, -1, 2, -1, 2, 6, 3, 7, 0, 5, 4 };
  std::int32_t k                  = 4;

  solutions_1(datas, k);
  solutions_2(datas, k);

  return 0;
}
