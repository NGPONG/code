#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

void foo() {
  size_t i = 0;

  std::int32_t fd = open("./test_file", O_RDWR);
  
  int len = lseek(fd, 0, SEEK_END);
  char *addr = (char *)mmap(nullptr, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

  printf("%p\n", addr);

  close(fd);

  for (; i < len; i++) {
    printf("%c", *(addr + i));
  }
 
  *(addr + i++) = 'h';
  *(addr + i++) = 'h';
  *(addr + i++) = 'z';
  *(addr + i++) = '\n';

  printf("%p\n", addr);

  std::size_t max = i + 10;
  for (std::size_t j = len; j < i; j++) {
    printf("%c", *(addr + j));
  }

  munmap(addr, 4096);
}

extern std::int32_t g_val;
void g_foo();
void g_bar();
void bar() {
  // getchar();

  while (true) {
    g_foo();
    g_bar();
    std::this_thread::sleep_for(2000ms);
  }
}

std::int32_t main (std::int32_t argc, char *argv[]) {
  bar();

  return 0;
}
