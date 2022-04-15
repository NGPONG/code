#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class BASE {
public:
  std::string name;
  int32_t score;
};

int main(void) {
  BASE b1;
  b1.name = "a";
  b1.score = 1;

  BASE b2;
  b2.name = "b";
  b2.score = 2;

  BASE b3;
  b3.name = "c";
  b3.score = 3;

  BASE b4;
  b4.name = "d";
  b4.score = 4;

  BASE b5;
  b5.name = "e";
  b5.score = 5;

  std::vector<BASE> v = { b2, b5, b1, b3, b4 };

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i].name << std::endl;
  }

  std::sort(v.begin(), v.end(), [](const BASE &left, const BASE &right) {
    return left.score < right.score;
  });

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i].name << std::endl;
  }

  return EXIT_SUCCESS;
}
