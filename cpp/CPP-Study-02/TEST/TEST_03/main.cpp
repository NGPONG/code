#include <iostream>
#include <list>

void l_print(std::list<int> &l) {
  for (auto i = l.begin(); i != l.end(); ++i) {
    printf("[0x%p] %d\n", &*i, *i);
  }
}

int main() {
  std::list<int> l;

  auto begin = l.begin();
  printf("0x%p\n", &*begin);

  auto end = l.end();
  printf("0x%p\n", &*end);

  for (size_t i = 0; i < 10; ++i) {
    l.push_back(i);
  }
  l_print(l);

  begin = l.begin();
  printf("0x%p\n", &*begin);

  end = l.end();
  printf("0x%p\n", &*end);

  return EXIT_SUCCESS;
}