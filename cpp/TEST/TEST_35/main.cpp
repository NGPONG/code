#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ranges>

#include <google/protobuf/text_format.h>
#include <benchmark/benchmark.h>

std::map<int, int> init_data() {
  std::map<int, int> m;

  for (int i = 0; i < 100000; ++i) {
    m[i] = i;
  }

  return m;
}

static void BM_1(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    auto m = init_data();
    state.ResumeTiming();

    std::vector<int> keys;
    keys.reserve(m.size());

    for (const auto& [key, _] : m) {
      keys.push_back(key);
    }
  }
}
BENCHMARK(BM_1);

static void BM_2(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    auto m = init_data();
    state.ResumeTiming();

    std::vector<int> keys;
    keys.reserve(m.size());

    std::transform(m.begin(), m.end(), back_inserter(keys), [](std::pair<int, int> p) { return p.first;} );
  }
}
BENCHMARK(BM_2);

static void BM_3(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    std::map<int, int> m = init_data();
    state.ResumeTiming();

    std::vector<int> keys;
    std::ranges::copy(m | std::views::keys, std::back_inserter(keys));
  }
}
BENCHMARK(BM_3);

BENCHMARK_MAIN();
