#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

int main(void) {
  std::string str = "1234哈哈";

  std::cout << str.find("234") << std::endl;

  std::cout << str.find("哈") << std::endl;
  std::cout << str.find("1") << std::endl;
  std::cout << str.find("asd") << std::endl;
  std::cout << str.find("擦") << std::endl;

  return EXIT_SUCCESS;
}
