#include <iostream>
using namespace std;

#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

/** copy
 * 
 * void copy(iterator src_start, iterator src_end, iterator des_start)
 * 
 * 拷贝原始容器中指定范围(迭代器 start 和 end 划分的范围)内的元素并重新赋值给目标容器(迭代器 des_start 所指向的容器)当中
 * 目标容器在拷贝前要保证其内部元素中是含有 [有效元素] 的，否则会调用失败
 * 
*/
void foo_copy(void) {
  vector<int> __v_src;
  for (size_t i = 0; i < 5; ++i) {
    __v_src.push_back(i);
  }

  vector<int> __v_des;
  for (size_t i = 5; i < 10; ++i) {
    __v_des.push_back(i);
  }
  copy(__v_src.begin(), __v_src.end(), __v_des.begin());

  for_each(__v_des.begin(), __v_des.end(), [](int &_val) { cout << _val << endl; });
}

/** replace
 * 
 * void replace(iterator start, iterator end, const T &_old_val, const T &_new_val)
 * 
 * 查找容器中指定范围(迭代器 start 和 end 划分的范围)内值为 _old_val 的元素，并修改其值为 _new_val
 * 
*/
void foo_replace(void) {
  vector<int> __v;
  __v.push_back(1);
  __v.push_back(2);
  __v.push_back(2);
  __v.push_back(3);
  __v.push_back(4);

  replace(__v.begin(), __v.end(), 2, 0x400);

  for_each(__v.begin(), __v.end(), [](int &_val) { cout << _val << endl; });
}

/** replace_if
 * 
 * void replace_if(iterator start, iterator end, function _fn, const T &_new_val)
 * 
 * 遍历容器指定范围(迭代器 start 和 end 划分的范围)内的元素，把它们作为实参逐个输入至所指定的 返回值为 bool 类型，形参类型为容器中的元素的值的类型的一元仿函数或者函数指针 _fn 当中并调用，当该 _fn 返回 true 时，则当前所操作的元素的值替换为 _new_val
 * 
*/
bool m_replace(int &_old_val) {
  return _old_val > 2;
}
void foo_replace_if(void) {
  vector<int> __v;
  for (size_t i = 0; i < 5; ++i) {
    __v.push_back(i);
  }

  replace_if(__v.begin(), __v.end(), m_replace, 0x400);

  copy(__v.begin(), __v.end(), ostream_iterator<int>(cout, "\t"));
}


/** swap
 * 
 * void swap(Container c_src, Container c_des)
 * 
 * 交换两个容器(相同容器类型)的内部用于管控数据空间的指针所指向的地址
*/
void foo_swap(void) {
  vector<int> __v_1;
  for (size_t i = 0; i < 5; ++i) {
    __v_1.push_back(i);
  }

  vector<int> __v_2;
  for (size_t i = 5; i < 10; ++i) {
    __v_2.push_back(i);
  }

  swap(__v_1, __v_2);

  copy(__v_2.begin(), __v_2.end(), ostream_iterator<int>(cout, " "));
}

int main(void) {
  /* foo_copy(); */
  /* foo_replace(); */
  /* foo_replace_if(); */
  /* foo_swap(); */
  system("pause");
  return EXIT_SUCCESS;
}