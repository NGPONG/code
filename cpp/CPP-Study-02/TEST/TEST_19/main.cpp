#include <iostream>
#include <string>
#include <set>

// #include <benchmark/benchmark.h>

class FOO {
public:
  std::string name;
  int32_t level;
  int32_t members;
  int32_t join_description;
};

class BASE {
public:
  FOO f;
  int32_t score;

  bool operator>(const BASE &b) const {
    std::cout << __func__ << std::endl;

    return score > b.score;
  }
};

int main(void) {
  BASE b1;
  b1.score = 10;
  b1.f.name = "b1";
  b1.f.level = 1;
  b1.f.members = 1;
  b1.f.join_description = -1;

  BASE b2;
  b2.score = 9;
  b2.f.name = "b2";
  b2.f.level = 2;
  b2.f.members = 2;
  b2.f.join_description = -1;

  BASE b3;
  b3.score = 8;
  b3.f.name = "b3";
  b3.f.level = 3;
  b3.f.members = 3;
  b3.f.join_description = -1;

  BASE b4;
  b4.score = 7;
  b4.f.name = "b4";
  b4.f.level = 4;
  b4.f.members = 4;
  b4.f.join_description = -1;

  BASE b5;
  b5.score = 6;
  b5.f.name = "b5";
  b5.f.level = 5;
  b5.f.members = 5;
  b5.f.join_description = -1;

  std::set<BASE, std::greater<>> s;
  s.insert(b2);
  s.insert(b5);
  s.insert(b1);
  s.insert(b4);
  s.insert(b3);

  for (const auto &e : s) {
    std::cout << e.f.name << std::endl;
  }

  return EXIT_SUCCESS;
}

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
