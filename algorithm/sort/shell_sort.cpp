#include "common.hpp"



void solution_1(Array &datas) {
  for (std::int32_t inc = datas.size() / 2; inc > 0; inc /= 2) {
    for (std::int32_t i = inc; i < datas.size(); i++) {
      std::int32_t key = datas[i];

      std::int32_t j = i;
      for (; j >= inc && key < datas[j - inc]; j -= inc) {
        datas[j] = datas[j - inc];
      }
      datas[j] = key;
    }
  }

  // for (std::int32_t inc = datas.size() / 2; inc > 0; inc /= 2) {
  //   for (std::int32_t i = inc; i < datas.size(); ++i) {
  //     std::int32_t key = datas[i];
  //
  //     std::int32_t j = i;
  //     for (; j >= inc && key < datas[j - inc]; j -= inc) {
  //       datas[j] = datas[j - inc];
  //     }
  //     datas[j] = key;
  //   }
  // }
}

int main(int argc, char *argv[]) {
  solution_test({
    { solution_1, "solution_1" },
  });

  solution_benchmark({
    { solution_1, "solution_1" },
  });

  return EXIT_SUCCESS;
}
