#include "common.hpp"

// 桶排序
//  * avg  ：O(n+k)
//  * worst: O(n^2 * k) 
//  * best : 
//
//

void solution_1(Array &array) {
  std::int32_t max_val = array[0];
  for (std::size_t i = 0; i < array.size(); ++i) {
    if (array[i] > max_val) {
      max_val = array[i];
    }
  }
  max_val += 1;

  std::vector<std::int32_t> counted_arr(max_val, 0x0);
  for (std::size_t i = 0; i < array.size(); ++i) {
    counted_arr[array[i]] += 1;
  }

  std::size_t idx = 0;
  for (std::size_t i = 0; i < counted_arr.size(); ++i) {
    for (std::size_t j = 0; j < counted_arr[i]; ++j) {
      array[idx++] = i;
    }
  }
}

std::int32_t main (std::int32_t argc, char *argv[]) {
  solution_test({
    { solution_1, "solution_1" },
  });

  solution_benchmark({
    { solution_1, "solution_1" },
  });

  return 0;
}
