#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

int main(void) {
  while (true) {
    std::string exp;
    getline(std::cin, exp);

    int32_t num = std::stoi(exp);
    std::cout << int32_t(std::pow(10, int32_t(std::log10(num)))) << std::endl;
  }

    // //DATA
    // std::vector<int> v1{2,4,6,8};
    // std::vector<int> v2{1,14,16,18};

    // //MERGE
    // std::vector<int> dst;
    // std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(dst));

    // //PRINT
    // for(auto item:dst)
    //     std::cout<<item<<" ";

  return EXIT_SUCCESS;
}
