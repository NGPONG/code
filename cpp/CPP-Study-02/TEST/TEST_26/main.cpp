#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
#include <iterator>

int main(void) {
  std::vector<int> v = {1,2,3};

  if (v.begin() + 3 == v.end()) {
    std::cout << "hello,world" << std::endl;
  }

  std::sort(v.begin() + 3, v.end(), [](int left, int right) { 
      return left > right; 
  });

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i] << std::endl;
  }

  return EXIT_SUCCESS;
}
