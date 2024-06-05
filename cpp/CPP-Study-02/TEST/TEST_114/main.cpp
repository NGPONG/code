#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::int32_t val = 100;

  std::int32_t vals[val] = { 0 };

  for (auto &item : vals) {
    std::cout << item << std::endl;
  }

  return 0;
}
