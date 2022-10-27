#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>

#include <google/protobuf/text_format.h>
#include <benchmark/benchmark.h>

#define DEBUG(msg) #msg
#define LOG_SCOPE(log, ident)                                                              \
    auto __main_log_grade = [&log, &ident, this] () {                                      \
        struct s                                                                           \
        {                                                                                  \
            s(std::ostringstream& log, KWGUID& ident) : ss(std::move(log)), id(ident) {}   \
            ~s() { std::cout << ss.str() << std::endl; }                \
        private:                                                                           \
            std::ostringstream ss;                                                         \
            KWGUID id;                                                                     \
        };                                                                                 \
        return s(log, ident);                                                              \
    }();                                                                                   \

static void BM_1(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> v(1000000);
    std::iota(std::begin(v), std::end(v), 0);

    std::vector<int> v2;
    v2 = v;
  }
}
BENCHMARK(BM_1);

static void BM_3(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> v(1000000);
    std::iota(std::begin(v), std::end(v), 0);

    std::vector<int> v3;

    v3.swap(v);
  }
}
BENCHMARK(BM_3);

int main(int argc, char **argv) {
  ::benchmark::Initialize(&argc, argv);
  if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
  ::benchmark::RunSpecifiedBenchmarks();
  ::benchmark::Shutdown();
  return 0;
}
int main(int, char **);
