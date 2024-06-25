#include <iostream>
#include <vector>

void solutions_1(std::vector<std::int32_t> v) {
  std::int32_t low = 0, high = v.size() - 1;

  std::int32_t mid = (low + high) / 2;

  if (v[mid] < v[low]) {
    std::swap(v[mid], v[low]);
  }

  if (v[high] < v[low]) {
    std::swap(v[high], v[low]);
  }

  if (v[mid] < v[high]) {
    std::swap(v[mid], v[high]);
  }

  std::cout << v[low] << "\t" << v[mid] << "\t" << v[high] << std::endl;
}

void solutions_2(std::vector<std::int32_t> v) {
  std::int32_t low = 0, high = v.size() - 1;

  std::int32_t mid = (low + high) / 2;

  if (v[high] < v[low]) {
    std::swap(v[high], v[low]);
  }

  if (v[high] < v[mid]) {
    std::swap(v[high], v[mid]);
  }

  if (v[high] < v[mid]) {
    std::swap(v[mid], v[high]);
  }

  // if (v[mid] < v[high]) {
  //   std::swap(v[mid], v[high]);
  // }
  //
  // if (v[low] < v[high]) {
  //   std::swap(v[high], v[low]);
  // }
  //
  // if (v[mid] < v[low]) {
  //   std::swap(v[mid], v[low]);
  // }

  std::cout << v[low] << "\t" << v[mid] << "\t" << v[high] << std::endl;
}

std::int32_t main (std::int32_t argc, char *argv[]) {
  std::vector<std::int32_t> v1 = { 7, 2, 5, 1, 3, 4 };
  std::vector<std::int32_t> v2 = { 1, 2, 3, 4, 5, 6 };
  std::vector<std::int32_t> v3 = { 6, 5, 4, 3, 2, 1 };
  std::vector<std::int32_t> v4 = { 2, 2, 9, 5, 7, 4 };

  solutions_1(v1);
  solutions_1(v2);
  solutions_1(v3);
  solutions_1(v4);

  std::cout << "---------------------------" << std::endl;

  solutions_2(v1);
  solutions_2(v2);
  solutions_2(v3);
  solutions_2(v4);

  return 0;
}
