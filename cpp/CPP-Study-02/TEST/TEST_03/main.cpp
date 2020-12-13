#include <iostream>
#include <thread>
#include <atomic>
#include <assert.h>
using namespace std;

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x_then_y() {
  x.store(true, std::memory_order_relaxed);  // ¢Ù
  y.store(true, std::memory_order_relaxed);  // ¢Ú
}

void read_y_then_x() {
  while (!y.load(std::memory_order_relaxed))
    ;                                     // ¢Û
  if (x.load(std::memory_order_relaxed))  // ¢Ü
    ++z;                                  // ¢Ý
}

int main() {
  x = false;
  y = false;
  z = 0;
  std::thread a(write_x_then_y);
  std::thread b(read_y_then_x);
  a.join();
  b.join();
  assert(z.load() != 0);  // ¢Þ

  return EXIT_SUCCESS;
}