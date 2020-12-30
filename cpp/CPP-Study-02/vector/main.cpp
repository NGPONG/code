#include <iostream>
#include <vector>

std::vector<int> __v;

void foo_01() {
  for (auto i = __v.begin(); i != __v.end(); ++i) {
    printf("[%p] %d\n", &*i, *i);
  }

  std::cout << "---------------------------" << std::endl;

  for (auto i = __v.begin(); i != __v.end(); ++i) {
    printf("[%p] %d\n", &*i, *i);
    if (*i == 2) {
      __v.erase(i);
      printf("[%p] %d\n", &*i, *i);
    }
  }

  std::cout << "---------------------------" << std::endl;

  for (auto i = __v.begin(); i != __v.end(); ++i) {
    printf("[%p] %d\n", &*i, *i);
  }
}



int main(void) {
  for (int i = 0; i < 10; ++i) {
    __v.push_back(i);
  }
  
  /* ?: 当插入(push_back)一个元素后，end操作返回的迭代器肯定失效 */
  // auto end = __v.end();
  // printf("[%p] %d\n", &*end, *end);
  // __v.push_back(0x400);
  // printf("[%p] %d\n", &*end, *end);

  for (auto i = __v.begin(); i != __v.end(); ++i) {
    printf("[%p] %d\n", &*i, *i);
    i = __v.erase(i);
    printf("[%p] %d\n", &*i, *i);
  }

  for (auto i = __v.begin(); i != __v.end(); ++i) {
    printf("[%p] %d\n", &*i, *i);
  }

  return EXIT_SUCCESS;
}
