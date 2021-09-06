#include <iostream>
#include <set>
#include <map>

int main(void) {
  std::map<int, std::set<int>> m;

  m[0].insert(100);
  m[0].insert(200);
  m[0].insert(300);

  m[1].insert(1000);
  m[1].insert(2000);
  m[1].insert(3000);

  for (const auto& [key, value] : m) {
    for (auto it = value.begin(); it != value.end(); ++it) {
      std::cout << *it << std::endl;
    }
  }

  return 0;
}
