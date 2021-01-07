#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool f_sort(int &_left,int &_right) {
  return _left > _right;
}
void foo(void) {
  int nums[5] = { 3, 2, 4, 1, 5 };
  vector<int> v(nums, nums + (sizeof(nums) / sizeof(int)));

  sort(v.begin(), v.end(), ptr_fun(::f_sort));
}
int main(void) {
  foo()

  return EXIT_SUCCESS;
}