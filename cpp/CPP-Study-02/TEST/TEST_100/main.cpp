#include <iostream>

constexpr std::string str = "hello,world";

static struct Initializer {
  Initializer() {
    std::cout << "constructor" << std::endl;
  } 
  ~Initializer() {
    std::cout << "destructor" << std::endl;
  }
} initializer;

int main (int argc, char *argv[]) {
  std::cout << "hello,world" << std::endl;

  return 0;
}
