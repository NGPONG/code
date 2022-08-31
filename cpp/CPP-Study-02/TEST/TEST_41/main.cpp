#include <algorithm>
#include <cstdint>
#include <forward_list>
#include <array>
#include <chrono>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <memory>

using namespace std;
using namespace std::chrono;

template<bool is_array>
struct timer {
  high_resolution_clock::time_point beg;
  timer()
    : beg(high_resolution_clock::now()) {
  }
  ~timer() {
    if constexpr (is_array) {
      std::cout << "Array: ";
    } else {
      std::cout << "List: ";
    }
    std::cout << (high_resolution_clock::now() - beg) / 1us << "us" << std::endl;
  }
};

template<size_t test_size>
void prepare_data(std::forward_list<int> &list, std::array<int, test_size> &ar) {
  for (int i = test_size - 1; i >= 0; --i) {
    int value = rand();
    ar[i] = value;
    list.emplace_front(value);
  }
}

template<size_t test_size>
void do_nothing() {
  std::forward_list<int> list;
  auto ar = make_unique<std::array<int, test_size>>();
  prepare_data(list, *ar);
  std::cout << "Do nothing.\n";
  {
    timer<true> clk;
    int i = 0;
    for (auto &e : *ar) {
      i += 1;
    }
    std::cout << i << std::endl;
  }
  {
    timer<false> clk;
    int i = 0;
    for (auto &e : list) {
      i += 1;
    }
    std::cout << i << std::endl;
  }
}


template<size_t test_size>
void sum() {
  std::forward_list<int> list;
  auto ar = make_unique<std::array<int, test_size>>();
  prepare_data(list, *ar);
  std::cout << "Calculate sum.\n";
  {
    int64_t sum = 0;
    timer<true> clk;
    for (auto &e : *ar) {
      sum += e;
    };
    std::cout << "sum: " << sum << std::endl;
  }
  {
    int64_t sum = 0;
    timer<false> clk;
    for (auto &e : list) {
      sum += e;
    };
    std::cout << "sum: " << sum << std::endl;
  }
}
template<size_t test_size>
void copy() {
  std::forward_list<int> list, list2;
  auto ar = make_unique<std::array<int, test_size>>(), ar2 = make_unique<std::array<int, test_size>>();
  std::cout << "Copy.\n";

  prepare_data(list, *ar);
  prepare_data(list2, *ar2);

  {
    timer<true> clk;
    std::copy(ar->begin(), ar->end(), ar2->begin());
    cout << (*ar2)[rand() % ar2->size()] << std::endl;
  }
  {
    timer<false> clk;
    std::copy(list.begin(), list.end(), list2.begin());
    cout << "hello,world" << std::endl;
  }
}

int main() {
  copy<1'000'000>();
  sum<1'000'000>();
  do_nothing<1'000'000>();
  return 0;
}
