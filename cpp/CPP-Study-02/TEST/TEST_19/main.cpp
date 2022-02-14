#include <iostream>
#include <string>
#include <set>

// #include <benchmark/benchmark.h>

class BASE {
public:
  std::string m1;
  int m2;

  bool operator>(const BASE &b) const {
    if (this->m2 != b.m2)
      return this->m2 > b.m2;

    return m1.compare(b.m2);
  }
};

// static void BM_1(benchmark::State& state) {
//   std::set<BASE> s;

//   int idx = 0;

//   for (auto _ : state) {
//     BASE b;
//     b.m1 = gen_random(12);
//     b.m2 = ++idx;

//     s.insert(b);
//   }
// }
// BENCHMARK(BM_1);


// static void BM_2(benchmark::State& state) {
//   std::set<int> s;

//   int idx = 0;

//   for (auto _ : state) {
//     s.insert(++idx);
//   }
// }
// BENCHMARK(BM_2);
// BENCHMARK_MAIN();

int main(void) {
  BASE b1;
  b1.m1 = "a";
  b1.m2 = 4;

  BASE b2;
  b2.m1 = "b";
  b2.m2 = 3;

  BASE b3;
  b3.m1 = "c";
  b3.m2 = 2;

  BASE b4;
  b4.m1 = "d";
  b4.m2 = 1;

  std::set<BASE, std::greater<>> s;
  s.insert(b1);
  s.insert(b2);
  s.insert(b3);
  s.insert(b4);

  for (const auto &e : s) {
    std::cout << e.m1 << std::endl;
  }

  BASE b5;
  b5.m1 = "e";
  b5.m2 = 0;

  s.insert(b5);

  BASE b6;
  b6.m1 = "f";
  b6.m2 = -1;

  s.insert(b6);
  s.insert(b5);

  return EXIT_SUCCESS;
}
