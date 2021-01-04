#include <iostream>
#include <list>

void l_print(std::list<int> &l) {
  for (auto i = l.begin(); i != l.end(); ++i) {
    printf("[0x%p] %d\n", &*i, *i);
  }
}

int main() {
  std::list<int> l;
  for (int i = 0; i < 10; ++i) {
    l.push_back(i);
  }

  auto begin = l.begin();
  printf("0x%p\n", &*begin);

  l.erase(l.begin()++);

  begin = l.begin();
  printf("0x%p\n", &*begin);

  return EXIT_SUCCESS;
}
