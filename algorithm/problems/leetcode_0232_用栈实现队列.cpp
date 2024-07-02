#include <iostream>
#include <stack>

class queue {
  std::stack<int> a, b;

public:
  void push(int val) {
    a.push(val);
  }

  int pop() {
    if (!b.empty()) {
      int ret = b.top();
      b.pop();
      return ret;
    }
    if (a.empty()) {
      return -1;
    }

    while (!a.empty()) {
      b.push(a.top()); a.pop();
    }

    int ret = b.top();
    b.pop();
    return ret;
  }
};

int main(void) {
  queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.push(6);
  q.push(7);

  for (int i = 0; i < 7; ++i) {
    std::cout << q.pop() << std::endl;
  }

  return EXIT_SUCCESS;
}
