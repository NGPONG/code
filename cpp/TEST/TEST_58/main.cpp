#include <iostream>
#include <map>
#include <string>

int main(void) {
  std::map<std::string, int32_t> m;
  m["A"] = 1024;
  m["B"] = 128;
  m["C"] = 256;

  std::cout << m["D"] << std::endl;
  std::cout << m["E"] << std::endl;
  std::cout << m["F"] << std::endl;
  std::cout << m["A"] << std::endl;
  std::cout << m["C"] << std::endl;
  std::cout << m["G"] << std::endl;

  return EXIT_SUCCESS;
}
