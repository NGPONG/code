#include <iostream>
#include <map>
#include <string>


int main(void) {
  std::map<std::string, int> __m;

  /* pair<map<K,V>::iterator, bool> insert(pair<const K,V> __p) */
  std::pair<std::map<std::string, int>::iterator, bool> result_01 = __m.insert(std::pair<std::string, int>("C", 3));
  std::pair<std::map<std::string, int>::iterator, bool> result_02 = __m.insert(std::make_pair("A", 1));
  std::pair<std::map<std::string, int>::iterator, bool> result_03 = __m.insert(std::map<std::string, int>::value_type("D", 4));

  auto i = ++__m.begin();

  return EXIT_SUCCESS;
}