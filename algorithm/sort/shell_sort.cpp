#include "common.hpp"

void solution_1(Array &datas) {
  for (std::int32_t gs = datas.size() / 2; gs > 0; gs /= 2) {
    for (std::int32_t i = gs; i < datas.size(); i++) {
      std::int32_t key = datas[i];

      std::int32_t j = i;
      for (; j >= gs && key < datas[j - gs]; j -= gs) {
        datas[j] = datas[j - gs];
      }
      datas[j] = key;
    }
  }
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
