#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <thread>
#include <chrono>
#include <ranges>
#include <iomanip>

template<typename T>
std::string Join(const T& v, const std::string& delimiter)
{
    std::stringstream ss;
    for (const auto& element : v)
    {
        if (ss.rdbuf()->in_avail() != 0)
            ss << delimiter;
        ss << element;
    }
    return ss.str();
}

int main(void) {
  // auto __f = []() {
  //   struct ff {
  //     ff() {
  //       std::cout << "ff constructor" << std::endl;
  //     }

  //     ~ff() {
  //       std::cout << "ff destructor" << std::endl;
  //     }
  //   };

  //   return ff();
  // }();

  // std::cout << "hello,world!" << std::endl;

  std::vector<int32_t> v_1 = {1,2,3,4,5,6,7,8,9};
  std::cout << Join(v_1, ";") << std::endl;

  std::vector<std::string> v_2 = {"A,1","B,2", "C,3", "D,4"};
  std::cout << Join(v_2, ";") << std::endl;

  return EXIT_SUCCESS;
}
