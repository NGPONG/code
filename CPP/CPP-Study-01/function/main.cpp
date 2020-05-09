#include <iostream>
using namespace std;

#include <set>
#include <vector>
#include <algorithm>
#include <functional>

template<class T>
class set_printer {
public:
  void operator()(const T &_val) {
    cout << _val << endl;
  }
};

void foo(void) {
  set<int, greater<int>> __s;
  __s.insert(4);
  __s.insert(2);
  __s.insert(5);
  __s.insert(1);
  __s.insert(3);

  vector<int> __v;
  __v.push_back(3);
  __v.push_back(5);
  __v.push_back(1);
  __v.push_back(4);
  __v.push_back(2);
  sort(__v.begin(), __v.end(), less<int>());

  for_each(__s.begin(), __s.end(), set_printer<int>());
  for_each(__v.begin(), __v.end(), set_printer<int>());
}

int main(void) {
  foo();

  system("pause");
  return EXIT_SUCCESS;
}