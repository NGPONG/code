#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <chrono>
#include <cstring>
#include <ctime>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <stack>
#include <thread>
#include <vector>
#include <benchmark/benchmark.h>

#define MAX_TEST_CASE 100000

using Array = std::vector<std::int32_t>;

using pair_i_i = std::pair<std::int32_t, std::int32_t>;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  void Foreach() {
    auto it = this;
    while (it) {
      std::cout << it->val << " ";

      if (!it->next) {
        std::cout << std::endl;
      }

      it = it->next;
    }
  }
  void Dump() {
    auto it = this;
    while (it) {
      std::cout << it << " ";

      if (!it->next) {
        std::cout << std::endl;
      }

      it = it->next;
    }
  }
};

template <class F>
struct y_combinator {
  F f;

  template <class... Args>
  decltype(auto) operator()(Args &&...args) const {
    return f(*this, std::forward<Args>(args)...);
  }
};

template <class F>
y_combinator<std::decay_t<F>> make_y_combinator(F &&f) {
  return { std::forward<F>(f) };
}

std::ostream &operator<<(std::ostream &os, const std::vector<std::int32_t> &datas) {
  for (const auto &data : datas) {
    std::cout << data << " ";
  }

  return os;
}

Array get_partially_array() {
  static Array ret;

  if (ret.empty()) {
    ret = std::vector<std::int32_t>(MAX_TEST_CASE, 0x0);

    std::mt19937 rng(std::random_device{}());

    // 前70%部分有序
    int orderedPartSize = MAX_TEST_CASE * 0.7;
    for (int i = 0; i < orderedPartSize; ++i) {
      ret[i] = i;
    }

    // 剩余30%部分随机
    std::uniform_int_distribution<int> dist(0, MAX_TEST_CASE * 2);
    for (int i = orderedPartSize; i < MAX_TEST_CASE; ++i) {
      ret[i] = dist(rng);
    }

    // 在有序部分中随机交换少量元素（10%）
    int swapCount = orderedPartSize * 0.1;
    for (int i = 0; i < swapCount; ++i) {
      int idx1 = rng() % orderedPartSize;
      int idx2 = rng() % orderedPartSize;
      std::swap(ret[idx1], ret[idx2]);
    }
  }

  return ret;
}

Array &get_total_random_array() {
  static Array ret;

  if (ret.empty()) {
    ret = std::vector<std::int32_t>(MAX_TEST_CASE, 0x0);

    for (int i = 0; i < MAX_TEST_CASE; ++i) {
      ret[i] = i;
    }

    std::mt19937 rng(std::random_device{}());
    std::shuffle(ret.begin(), ret.end(), rng);
  }

  return ret;
}

ListNode *get_desc_list(std::int32_t size = 10, std::int32_t idx = 0) {
  if (!size) {
    return nullptr; 
  } else {
    ListNode *node = new ListNode(size);
    node->next = get_desc_list(--size);

    return node;
  }
}