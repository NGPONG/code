#include <iostream>
#include <atomic>
#include <unistd.h>

#define DEF_MEMORY_ORDER std::memory_order::memory_order_relaxed

class BASE {
public:
  std::atomic<int> val;

  BASE(): val(0) {}

  void TokenAtomicINC() {
    val.fetch_add(1, std::memory_order::memory_order_relaxed);
  }
};

BASE B;

void *thread_start(void *_arg) {
  for (int i = 0; i < 50000; ++i) {
    B.TokenAtomicINC();
  }
  return nullptr;
}

int main(void) {
  pthread_t t1;
  pthread_create(&t1, NULL, thread_start, NULL);

  pthread_t t2;
  pthread_create(&t2, NULL, thread_start, NULL);

  pthread_join(t1, nullptr);
  pthread_join(t2, nullptr);

  std::cout << B.val << std::endl;

  return EXIT_SUCCESS;
}
