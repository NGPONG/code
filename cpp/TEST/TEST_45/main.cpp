#include <iostream>
#include <string>
#include <numeric>
#include <random>
#include <bitset>
#include <algorithm>
#include <bits/stdc++.h>

#include <google/protobuf/text_format.h>
#include <benchmark/benchmark.h>

// static void BM_1(benchmark::State& state) {
//   for (auto _ : state) {
//     std::vector<int> ivec(999999999);
//     std::iota(ivec.begin(), ivec.end(), 0);
//   }
// }
// BENCHMARK(BM_1);

// static void BM_3(benchmark::State& state) {
//   for (auto _ : state) {
//     std::vector<int> ivec(999999999);
//     std::iota(ivec.begin(), ivec.end(), 0);

//     std::vector<int> dest;
//     dest.reserve(999999999);

//     std::ranges::copy(ivec, std::back_inserter(dest));
//   }
// }
// BENCHMARK(BM_3);

// static void BM_4(benchmark::State& state) {
//   for (auto _ : state) {
//     std::vector<int> ivec(999999999);
//     std::iota(ivec.begin(), ivec.end(), 0);

//     std::vector<int> dest;

//     std::ranges::copy(ivec, std::back_inserter(dest));
//   }
// }
// BENCHMARK(BM_4);

// static void BM_5(benchmark::State& state) {
//   for (auto _ : state) {
//     std::vector<int> ivec(999999999);
//     std::iota(ivec.begin(), ivec.end(), 0);

//     std::vector<int> dest;

//     std::ranges::move(ivec, std::back_inserter(dest));
//   }
// }
// BENCHMARK(BM_5);

static void BM_6(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<int> ivec(999999);
    std::iota(ivec.begin(), ivec.end(), 0);

    std::vector<int> dest;
    dest.reserve(999999);

    std::ranges::move(ivec, std::back_inserter(dest));
  }
}
BENCHMARK(BM_6);

static void BM_1(benchmark::State& state) {
  for (auto _ : state) {

    std::vector<int> ivec(999999);
    std::iota(ivec.begin(), ivec.end(), 0);

    std::vector<int> dest;
    dest.insert(dest.end(), std::make_move_iterator(ivec.begin()),
                            std::make_move_iterator(ivec.end()));
  }
}
BENCHMARK(BM_1);

static void BM_2(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<int> ivec(999999);
    std::iota(ivec.begin(), ivec.end(), 0);

    std::vector<int> dest;
    dest.insert(dest.end(), ivec.begin(),
                            ivec.end());
  }
}
BENCHMARK(BM_2);

BENCHMARK_MAIN();

// template< size_t size>
// typename std::bitset<size> random_bitset( double p = 0.5) {

//     typename std::bitset<size> bits;
//     std::random_device rd;
//     std::mt19937 gen( rd());
//     std::bernoulli_distribution d( p);

//     for( int n = 0; n < size; ++n) {
//         bits[ n] = d( gen);
//     }

//     return bits;
// }

// template<class T>
// T uniform_bits(std::mt19937& g){
//   std::uniform_int_distribution<T> dist(std::numeric_limits<T>::lowest(),std::numeric_limits<T>::max());
//   return dist( g );
// }

// int main(void) {
//   std::bitset<10> bs = 992;

//   std::cout << bs << std::endl;

//   // std::vector<int32_t> v(10, 0);
//   // std::iota(v.begin(), v.begin() + 5, 1);

//   // for (auto& i : v)
//   //   std::cout << i << std::endl;

//   // std::bitset<20> bs = 240;
//   // std::cout << bs << std::endl;

//   // // for (int i = 0; i < 20; ++i)
//   // //   std::cout << random_bitset<20>(0.1) << std::endl;

//   // std::mt19937 engine;

//   // //You'll see a lot of people write `engine.seed(std::random_device{}())`. This
//   // //is bad. The Mersenne Twister has an internal state of 624 bytes. A single
//   // //call to std::random_device() will give us 4 bytes: woefully inadequate. The
//   // //following method should be slightly better, though, sadly,
//   // //std::random_device may still return deterministic, poorly distributed
//   // //numbers.
//   // std::uint_fast32_t seed_data[std::mt19937::state_size];
//   // std::random_device r;
//   // std::generate_n(seed_data, std::mt19937::state_size, std::ref(r));
//   // std::seed_seq q(std::begin(seed_data), std::end(seed_data));
//   // engine.seed(q);

//   // //Use bitset to print the numbers for analysis
//   // for(int i=0;i<10;i++)
//   //   std::cout<<std::bitset<20>(uniform_bits<uint64_t>(engine))<<std::endl;

//   return EXIT_SUCCESS;
// }
