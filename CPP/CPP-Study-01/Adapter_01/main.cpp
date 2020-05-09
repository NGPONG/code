#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

class print_m : public binary_function<int, int, void> {
public:
  void operator()(int _val_01, int _val_02) const {
    cout << "_val_01 + _val_02 = " << _val_01 + _val_02 << endl;
  }
};
void foo_01(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  vector<int> __v(nums, nums + (sizeof(nums) / sizeof(int)));

  for_each(__v.begin(), __v.end(), bind2nd(print_m(), 1000));
}

int main(void) {
  foo_01();

  system("pause");
  return EXIT_SUCCESS;
}