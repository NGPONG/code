#include <iostream>

void _start() {
  std::cout << "hello,world!" << std::endl;
}

int main (int argc, char *argv[]) {
  const char* str = "hello,world!";

  std::cout << str << std::endl;

  return 0;
}
