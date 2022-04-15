#include <iostream>
#include <random>
#include <iterator>

int32_t get_random(int32_t min, int32_t max) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);

  return dist6(rng);
}

int32_t foo() {
  int32_t nums[] = { 1, 2, 3, 4, 5, 6 };
  int32_t weig[] = { 10, 13, 20, 17, 15, 99 };

  int32_t sum = 0;
  for (int32_t *i = std::begin(weig); i < std::end(weig); ++i)
    sum += *i;

  int32_t rnd = get_random(0, sum);
  for (int i = 0; i < std::extent<decltype(weig)>::value; ++i) {
    if (rnd < weig[i]) {
      return i + 1;
    }

    rnd -= weig[i];
  }

  return 0;
}

void foo2() {
  std::vector<double> weights{25,25,25,15,10};
  std::discrete_distribution<int> dist(std::begin(weights), std::end(weights));
  std::mt19937 gen;
  gen.seed(time(0));//if you want different results from different runs

  int N = 1000000;
  std::vector<double> samples(6);
  for (int i = 0; i < N; ++i) {
    samples[dist(gen)]++;
  }
}

int main() {
  foo2();

  // int32_t N = 100000;

  // std::vector<double> v(6);

  // for (int i = 0; i < N; ++i) {
  //   v[foo()]++;
  // }

  // for (auto &item : v)
  //   item /= N;

  // for (int i = 0; i < v.size(); ++i) {
  //   std::cout << "[" << i + 1 << "]: " << v[i] << std::endl;
  // }
}
