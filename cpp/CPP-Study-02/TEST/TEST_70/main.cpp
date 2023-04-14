#include <iostream>
#include <vector>

int main(void) {
  std::vector<int32_t> v = {1,2,3,4,5,6,7,8};

  for (auto&& i : v)
    i += 1;

  for (auto& i : v)
    std::cout << i << std::endl;

  return EXIT_SUCCESS;
}
