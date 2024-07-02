#include <iostream>

int main(void) {
  int32_t val = 6;
  int32_t low = 0;
  int32_t hig = 5;

  if (val == std::clamp(val, low, hig))
    std::cout << "hello,world!" << std::endl;
  else
    std::cout << "ops" << std::endl;

  return EXIT_SUCCESS;
}
