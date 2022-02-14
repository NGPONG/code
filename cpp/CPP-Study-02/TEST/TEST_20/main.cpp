#include <iostream>

class FOO {
public:
  std::string name;
  int32_t level;
  int32_t members;
  int32_t join_description;
};

class BASE {
  class NG {
  public:
    FOO f;
    int32_t score;

    bool operator>(const NG &b) const;
  };
};

bool BASE::NG::operator>(const NG &b) const {
  std::cout << __func__ << std::endl;

  return score > b.score;
}

int main(void) {

  return EXIT_SUCCESS;
}
