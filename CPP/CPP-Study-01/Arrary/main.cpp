#include "arrary.hpp"

int main(void) {
  Arrary<int> arrary(10);
  for (size_t i = 0; i < 10; i++) {
    arrary.Add(i + 1);
  }

  for (size_t i = 0; i < 10; i++) {
    std::cout << arrary[i] << std::endl;
  }

  Arrary<int> arrary2 = arrary;
  for (size_t i = 0; i < 10; i++) {
    std::cout << arrary2[i] << std::endl;
  }

  Arrary<int> arrary3 = std::move(arrary);
  for (size_t i = 0; i < 10; i++) {
    std::cout << arrary3[i] << std::endl;
  }

  system("pause");
  return EXIT_SUCCESS;
}