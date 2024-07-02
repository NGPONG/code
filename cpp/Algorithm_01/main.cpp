#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

/** for_each
 * _Function for_each(_InputIterator start, _InputIterator end, _Function _fn)
 * 
 * 遍历容器指定范围(迭代器 start 和 end 划分的范围)内的元素，把它们作为实参逐个输入至所指定的 一元仿函数或者函数指针 当中，最后会返回所指定的 一元仿函数或者函数指针
*/
void printer_for_each(const int &_val) {
  cout << _val << endl;
}
void foo_for_each(void) {
  vector<int> __v;
  for (size_t i = 0; i < 10; ++i) {
    __v.push_back(i + 1);
  }

  void (*invoker)(const int &) = for_each(__v.begin(), __v.end(), printer_for_each);
}

/** transform
 * void transform(_InputIterator start, _InputIterator end, _OutputIterator start_des, _UnaryOperation unary_op)
 * 
 * 遍历容器指定范围(迭代器 start 和 end 划分的范围)内的元素，把它们作为实参逐个输入至所指定的 返回值和形参类型为容器中的元素类型的一元仿函数或者函数指针 unary_op 当中，并依照它的返回结果 [重新赋值] 给迭代器 start_des 所指向的目标容器中
 * 该函数的调用必须要保证目标迭代器 __result 所指向的容器中是含有 [有效元素] 的，否则会调用失败
*/
int f_transform(int &_val) {
  return _val + 1;
}
void foo_transform(void) {
  vector<int> __v_src;
  for (size_t i = 0; i < 10; ++i) {
    __v_src.push_back(i + 1);
  }

  vector<int> __v_des;
  __v_des.resize(__v_src.size());
  transform(__v_src.begin(), __v_src.end(), __v_des.begin(), f_transform);
}

int main(void) {
  /* foo_for_each(); */
  foo_transform();

  system("pause");
  return EXIT_SUCCESS;
}