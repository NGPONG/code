#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include <chrono>


int main(void) {
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << std::endl;

  return EXIT_SUCCESS;
}
