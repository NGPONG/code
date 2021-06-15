#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
  map<string, int> m;
  auto p = m.insert(pair("a", 1));
  
  return EXIT_SUCCESS;
}
