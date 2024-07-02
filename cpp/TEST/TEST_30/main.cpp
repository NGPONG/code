#include <iostream>
#include <string>
#include <vector>

#include <benchmark/benchmark.h>

static int N = 100000;

struct Base {
  std::vector<int> v1 = std::vector<int>(1000);
  std::vector<int> v2 = std::vector<int>(1000);
};

static void BM_1(benchmark::State &state) {
  std::vector<Base> v(N);

  for (auto _ : state) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < 1000; ++j) {
        v[i].v1[j] = j;
      }

      for (int j = 0; j < 1000; ++j) {
        v[i].v2[j] = j;
      }
    }
  }
}
BENCHMARK(BM_1);

static void BM_2(benchmark::State &state) {
  std::vector<Base> v(N);

  for (auto _ : state) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < 1000; ++j) {
        v[i].v1[j] = j;
        v[i].v2[j] = j;
      }
    }
  }
}
BENCHMARK(BM_2);

static void BM_3(benchmark::State &state) {
  std::vector<Base> v(N);

  for (auto _ : state) {
    for (int j = 0; j < 1000; ++j) {
      for (int i = 0; i < N; ++i) {
        v[i].v1[j] = i;
      }
      for (int i = 0; i < N; ++i) {
        v[i].v2[j] = i;
      }
    }
  }
}
BENCHMARK(BM_3);

BENCHMARK_MAIN();
