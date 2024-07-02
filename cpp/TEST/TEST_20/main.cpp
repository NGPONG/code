#include <iostream>
#include <set>
#include <vector>
#include <string>

void foo() {
  constexpr int32_t N = 9;

  std::set<std::string> s;
  for (int i = 0; i < 10; ++i) {
    s.insert(std::to_string(i));
  }

  using T = typename std::decay<decltype(*s.begin())>::type;

  int32_t dis = s.size() > N ? N : s.size();

  std::cout << dis << std::endl;

  std::vector<T> range(s.cbegin(), std::next(s.cbegin(), dis));
  for (const auto &str : range) {
    std::cout << str << std::endl;
  }
}

int main(int argc, char *argv[]) {
  foo();

  return EXIT_SUCCESS;
}
