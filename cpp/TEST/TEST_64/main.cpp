#include <iostream>
#include <numeric>
#include <benchmark/benchmark.h>

struct BASE {
void reset() {
  a = -1;
  b = -1;
  c = -1;
  d = -1;
  e = -1;
  f = -1;
  g = -1;
  h = -1;
  i = -1;
  j = -1;
  k = -1;
  l = -1;
  m = -1;
  n = -1;
  o = -1;
  p = -1;
  q = -1;
  r = -1;
  s = -1;
  t = -1;
  u = -1;
  v = -1;
  w = -1;
  x = -1;
  y = -1;
  z = -1;
}

int64_t a = 0;
int64_t b = 0;
int64_t c = 0;
int64_t d = 0;
int64_t e = 0;
int64_t f = 0;
int64_t g = 0;
int64_t h = 0;
int64_t i = 0;
int64_t j = 0;
int64_t k = 0;
int64_t l = 0;
int64_t m = 0;
int64_t n = 0;
int64_t o = 0;
int64_t p = 0;
int64_t q = 0;
int64_t r = 0;
int64_t s = 0;
int64_t t = 0;
int64_t u = 0;
int64_t v = 0;
int64_t w = 0;
int64_t x = 0;
int64_t y = 0;
int64_t z = 0;
};

void foo_01(benchmark::State& state) {
  for (auto _: state) {
    std::vector<BASE> ivec;
    ivec.reserve(50);
    for (int i = 0; i < 50; ++i)
      ivec.push_back(BASE());
    
    // for (int i = 0; i < 10; ++i)
    //   (*(ivec.begin() + i)) = -1;
  }
}
BENCHMARK(foo_01);

void foo_2(benchmark::State& state) {
  for (auto _: state) {
    std::vector<int32_t> ivec;
    for (int i = 0; i < 50; ++i)
      ivec.push_back(i);
    
    for (int i = 0; i < 10; ++i) {
      std::iter_swap(ivec.begin() + i, ivec.rbegin());
      ivec.erase(std::next(ivec.rbegin()).base());
    }

    std::sort(ivec.begin(), ivec.end());
  }
}
BENCHMARK(foo_2);

void foo_03(benchmark::State& state) {
  for (auto _: state) {
    std::vector<int32_t> ivec;
    for (int i = 0; i < 50; ++i)
      ivec.push_back(i);

    for (int i = 0; i < 20; ++i) {
      ivec.erase(ivec.begin() + i);
    }
  }
}
BENCHMARK(foo_03);

BENCHMARK_MAIN();
