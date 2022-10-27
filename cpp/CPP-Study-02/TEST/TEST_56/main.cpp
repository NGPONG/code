#include <iostream>
#include <bitset>
#include <fstream>
#include <functional>
#include <unordered_map>
#include <map>
#include <numbers>
#include <math.h>

double calc(double d, double n) {
  const double exponent = (-n * (n - 1)) / (2 * d);
  return 1 - std::pow(std::numbers::e_v<double>, exponent);
}

int main(void) {
  

  // std::cout << calc(std::pow(10, 19), 100000000);

  // std::unordered_map<std::string, bool> um;
  // for (size_t i = 0; i < 300000; ++i)
  //   um.insert({"1234567890-12345", true});

  // std::cout << typeid(size_t).name() << std::endl;
  // std::cout << std::hash<std::string>{}("123qweqwe") << std::endl;

  std::bitset<12001000002> *bs = new std::bitset<12001000002>;
  for (int32_t i = 0; i < 3000000; ++i)
    bs->set(i);
  bs->set(12001000001);
  std::cout << bs->count() << std::endl;
  

  // std::unordered_map<int32_t, bool> um;
  // for (int32_t i = 0; i < 300000; ++i)
  //   um[i] = true;

  // std::cout << bs->count() << std::endl;

  // std::ofstream out("output.txt");
  // out << bs->to_string();
  // out.close();

  return EXIT_SUCCESS;
}
