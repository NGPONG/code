#include <iostream>
#include <vector>
#include <queue>

int main(void) {
  std::priority_queue<int> queue;
  queue.push(18);
  queue.push(4);
  queue.push(7);
  queue.push(2);
  queue.push(13);
  queue.push(1);

  while (!queue.empty()) {
    std::cout << queue.top() << std::endl;
    queue.pop();
  }

  return EXIT_SUCCESS;
}
