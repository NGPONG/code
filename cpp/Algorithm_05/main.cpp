#include <iostream>
using namespace std;

#include <vector>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <functional>

/** accumulate
 * 
 * T accumulate(iterator start, iterator end, const T &_init_val)
 * 
 * 以 _init_val 作为初始化数据，在此基础上累加容器指定范围(迭代器 start 和 end 划分的范围)内的元素的值，最后返回累加后的结果
*/
void foo_accumulate(void) {
  vector<int> __v;
  for (size_t i = 0; i < 5; ++i) {
    __v.push_back(i);
  }

  int num = accumulate(__v.begin(), __v.end(), 100);
  cout << num << endl;
}

/** fill
 * 
 * void fill(iterator start, iterator end, const T &_val)
 * 
 * 容器指定范围(迭代器 start 和 end 划分的范围)内的元素的值替换为 _val
*/
void foo_fill(void) {
  vector<int> __v;
  for (size_t i = 0; i < 5; ++i) {
    __v.push_back(i);
  }

  fill(__v.begin(), __v.begin() + 2, 0x400);
}

int main(void) {
  /* foo_accumulate(); */
  foo_fill();

  system("pause");
  return EXIT_SUCCESS;
} 