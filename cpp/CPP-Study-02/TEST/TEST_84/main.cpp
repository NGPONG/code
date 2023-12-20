#include <vector>
#include <string>

#include <benchmark/benchmark.h>

static void direct_move(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<std::string> oldv = { "hello,world!", "NGPONG!", "wupeng", "wanmeishijie" };
    benchmark::DoNotOptimize(oldv);

    std::vector<std::string> newv = std::move(oldv);
  }
}
BENCHMARK(direct_move);

static void move_iterator_resize(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<std::string> oldv = { "hello,world!", "NGPONG!", "wupeng", "wanmeishijie" };
    benchmark::DoNotOptimize(oldv);
    
    std::vector<std::string> newv; newv.resize(oldv.size());
    std::copy(
        make_move_iterator(oldv.begin()),
        make_move_iterator(oldv.end()),
        newv.begin()
    );
  }
}
BENCHMARK(move_iterator_resize);

static void move_iterator(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<std::string> oldv = { "hello,world!", "NGPONG!", "wupeng", "wanmeishijie" };
    benchmark::DoNotOptimize(oldv);
    
    std::vector<std::string> newv(
      make_move_iterator(oldv.begin()),
      make_move_iterator(oldv.end())
    );
  }
}
BENCHMARK(move_iterator);

static void asign_copy(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<std::string> oldv = { "hello,world!", "NGPONG!", "wupeng", "wanmeishijie" };
    benchmark::DoNotOptimize(oldv);

    std::vector<std::string> newv; newv.resize(oldv.size());
    newv.assign(oldv.begin(), oldv.end());
  }
}
BENCHMARK(asign_copy);

int main(int argc, char **argv) {
  ::benchmark::Initialize(&argc, argv);
  if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
  ::benchmark::RunSpecifiedBenchmarks();
  ::benchmark::Shutdown();
  return 0;
}
int main(int, char **);
