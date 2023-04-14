#include <iostream>
#include <vector>
#include <deque>

#include <benchmark/benchmark.h>

#include "range.hpp"
#include "zip_tuple.hpp"
#include "zip.h"

void foo_01(benchmark::State& state) {
  for (auto _: state) {
    std::array<int32_t, 2> v1 = { 1, 2 };
    std::vector<int32_t> v2 = { 8, 9 };

    for(unsigned i : util::lang::indices(v1)) {
      int a = v1[i] + v2[i];
    }
  }
}
BENCHMARK(foo_01);

void foo_02(benchmark::State& state) {
  for (auto _: state) {
    std::array<int32_t, 2> v1 = { 1, 2 };
    const std::vector<int32_t> v2 = { 8 };

    for (auto&& [x, y] : zip(v1, v2)) {
      int a = x + y;
    }

    // std::array<int32_t, 2> v1 = { 1, 2 };
    // const std::vector<int32_t> v2 = { 8, 9 };

    // const std::vector<int32_t>& v3 = v2;

    // std::array<int32_t, 2>& v4 = v1;

    // std::array<int32_t, 2>&& v5 = std::move(v4);

    // const std::array<int32_t, 2>&& v6 = std::move(v5);

    // for (auto&& [x, y, z, h, i, j] : zip(v1, v2, v3, v4, v5, v6)) {
    //   int a = x + y;
    // }
  }
}
BENCHMARK(foo_02);

// void foo_03(benchmark::State& state) {
//   for (auto _: state) {
//     std::array<int32_t, 2> v1 = { 1, 2 };
//     std::vector<int32_t> v2 = { 8, 9 };
//     std::deque<std::string> v3 = { "abc123", "qwezxc" };

//     for (auto&& [x, y, z] : c9::zip(v1, v2, v3)) {
//       int a = x + y;
//       std::string str = z;
//     }
//   }
// }
// BENCHMARK(foo_03);

void foo_04(benchmark::State& state) {
  for (auto _: state) {
    std::array<int32_t, 2> v1 = { 1, 2 };
    std::vector<int32_t> v2 = { 8, 9 };

    std::size_t size = v1.size();
    for (std::size_t i = 0; i < size; ++i) {
      int a = v1[i] + v2[i];
    }
  }
}
BENCHMARK(foo_04);

BENCHMARK_MAIN();
