#include <iostream>
#include <deque>
#include <chrono>
#include <vector>
#include <queue>

std::queue<char *> gq;

class BASE 
{
public:
  BASE() {
    eles = new char[1024 * 1024 * 10];
    gq.push(new char[1024 * 1024 * 10]);

    std::cout << eles << std::endl;
  }

  BASE(const BASE &b) {
    std::cout << "copy" << std::endl;

    eles = gq.front();
    gq.pop();
    *eles = *b.eles;
  }

  BASE(BASE &&b) {
    std::cout << "move" << std::endl;

    eles = b.eles;
    b.eles = nullptr;
  }

  char *eles;
};

int main(void) {
  std::deque<BASE> q;

  for (int i = 0; i < 1000; ++i) {
    q.push_back(BASE());
  }

  auto start = std::chrono::system_clock::now();
  while (q.size()) {
    // auto b = std::move(q.front());
    BASE b = q.front();
    q.pop_front();
  }
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start).count() * std::chrono::microseconds::period::num << "(µs)." << std::endl;

  return EXIT_SUCCESS;
}
