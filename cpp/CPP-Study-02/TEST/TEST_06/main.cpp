#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <chrono>
#include <time.h>

int main(void) {
  std::vector<int> v;
  for (int i = 0; i < 10000000; ++i) {
    v.push_back(i);
  }

  std::list<int> l;
  for (int i = 0; i < 10000000; ++i) {
    l.push_back(i);
  }

  auto start = std::chrono::system_clock::now();
  for (auto &item : v) {
    int val = item;
    ++val;
    item = val;
  }
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start).count() << std::endl;

  start = std::chrono::system_clock::now();
  for (int i = 0; i < 10000000; ++i) {
    int val = v[i];
    ++val;
    v[i] = val;
  }
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start).count() << std::endl;

  start = std::chrono::system_clock::now();
  for (auto it = v.begin(); it != v.end(); ++it) {
    int val = *it;
    ++val;
    *it = val;
  }
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start).count() << std::endl;

  start = std::chrono::system_clock::now();
  for (auto &item : l) {
    int val = item;
    ++val;
    item = val;
  }
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start).count() << std::endl;
}
