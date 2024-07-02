#include <iostream>
#include <stack>

using namespace std;

// 题目: 设计一个能够返回当前栈中所有元素最小值的栈，要求时间复杂度和空间复杂度都为 O(1)

class min_stack {
  stack<int> data;

  int get_min(int val) {
    return val & 0xFFFF0000 >> 16;
  }

  int get_real(int val) {
    return val & 0xFFFF;
  }

  int set_num(int val, int min_val) {
    return val | min_val << 16;
  }

public:
  void push(int val) {
    if (data.empty()) {
      data.push(set_num(val, val));
      data.push(val);
    }

    int min_val = get_min(data.top());
    if (val < min_val) {
      min_val = val;
    }

    data.push(set_num(val, min_val));
  }

  int pop() {
    int ret = data.top();
    data.pop();
    return ret;
  }

  int min() {
    return data.top() >> 16;
  }
};

int main(void) {

  return EXIT_SUCCESS;
}
