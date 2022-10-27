#include <iostream>
#include <set>
#include <vector>

int main(void) {
  std::set<std::string> s1 = { "A", "B", "C" };
  std::set<std::string> s2 = { "A", "C", "D", "B", "E" };

  std::set<std::string> s3 = {};

  std::set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), std::inserter(s3, s3.begin()));

  for (const auto &i : s3)
    std::cout << i << std::endl;

  return EXIT_SUCCESS;
}
