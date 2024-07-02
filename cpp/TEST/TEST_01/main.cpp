#include <exception>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <chrono>
#include <unistd.h>

#define MAX_BUFF_BLOCK_COUNT 9
#define MIN_NULTI_BUFF_SIZE  (1 * 1024 * 1024)
#define MAX_NULTI_BUFF_SIZE  (32 * 1024 * 1024)

class Buffer {
public:
  Buffer(int bufferBlockCount, const int initBufferSize) {
    std::cout << "======================" << std::endl;
    
    for (int i = 0; i < bufferBlockCount; i++) {
      unsigned char *bu = new unsigned char[MAX_NULTI_BUFF_SIZE]; // MIN_NULTI_BUFF_SIZE
      printf("%p\n", bu);
      v.push_back(bu);
    }

    std::cout << "======================" << std::endl;
  }

  ~Buffer() {
    for (auto it = v.begin(); it != v.end(); ++it) {
      unsigned char *buff = *it;
      delete []buff;
    }
  }

private:
  std::vector<unsigned char *> v;
};

// qwddq
void foo() {
  auto buffer = Buffer(MAX_BUFF_BLOCK_COUNT, MIN_NULTI_BUFF_SIZE);

  auto b2 = Buffer(MAX_BUFF_BLOCK_COUNT, MIN_NULTI_BUFF_SIZE);
}

void bar(const std::string& str, const std::size_t idx) {
  
}

namespace alias {
template <typename T, typename U> struct S;
template <typename T>
template <typename U>
using SS = S<T, U>;
}

int main(void) {
  // for (int i = 0; i < 5; ++i) {
  //   foo();
  // }
  //
  // for (;;) {
  //   sleep(1);
  // }
  //
  // sleep(1024);
  //
  //     sleep(0x400);
  //
  // const std::string& str = "hello,world!";
  //
  // str.size();

  std::cout << 1;

  return EXIT_SUCCESS;
}
