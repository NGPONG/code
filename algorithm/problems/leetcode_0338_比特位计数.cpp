#include <iostream>

void count_bit_01(unsigned int n) {
  unsigned int count = 0;
  for (; n; ++count) {
    n &= (n - 1);
  }

  std::cout << count << std::endl;
}

int main(void) {
  int n = 0B1011;
  count_bit_01(n);
  
  return EXIT_SUCCESS;
}
