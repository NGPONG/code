#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
#include <functional>

/** merge
 * 
 * void merge(iterator src_start_1, iterator src_end_1, iterator src_start_2, iterator src_end_2, iterator des_start)
 * 
 * 合并指定范围内(两个容器的开始和起始迭代器 src_start_1、src_end_1、src_start_2、src_end_2) 的两个容器的元素，并重新赋值给目标容器(迭代器 des_start 所指向的容器)当中
 * 我尽量要保证原始合并的两个数据源是有序序列，否则合并后的结果将可能会出现相较之前的乱序
 * 目标容器在合并前要保证其内部元素中是含有 [有效元素] 的，否则会调用失败
 * 
*/
void foo_merge(void) {
  vector<int> __v_src_1;
  __v_src_1.push_back(1);
  __v_src_1.push_back(2);
  __v_src_1.push_back(3);
  __v_src_1.push_back(4);
  __v_src_1.push_back(5);

  vector<int> __v_src_2;
  __v_src_2.push_back(6);
  __v_src_2.push_back(7);

  vector<int> __v_des;
  __v_des.resize(__v_src_1.size() + __v_src_2.size());
  merge(__v_src_1.begin(), __v_src_1.end(), __v_src_2.begin(), __v_src_2.end(), __v_des.begin());
}

/** sort
 * 
 * void sort(iterator start, iterator end, function _fn)
 * 
 * 对容器内指定范围(迭代器 start 和 end 划分的范围)内的元素依照返回值为 bool 类型，形参类型为容器中的元素的值的类型的二元仿函数或函数指针 去进行排序
 *  
*/
void foo_sort(void) {
  vector<int> __v;
  __v.push_back(4);
  __v.push_back(1);
  __v.push_back(5);
  __v.push_back(2);
  __v.push_back(3);

  sort(__v.begin(), __v.end(), [](int &_left, int &_right) { return _left > _right; });
}

/** random_shuffle
 * 
 * void random_shuffle(iterator start, iterator end)
 * 
 * 随机置乱容器指定范围(迭代器 start 和 end 划分的范围)内的元素的原始次序
 * 
*/
void foo_random_shuffle(void) {
  vector<int> __v;
  for (size_t i = 0; i < 5; ++i) {
    __v.push_back(i);
  }

  random_shuffle(__v.begin(), __v.end());

  for_each(__v.begin(), __v.end(), [](int &_val) { cout << _val << endl; });
}

/** reverse
 * 
 * void reverse(iterator start, iterator end)
 * 
 * 反转容器中指定范围(迭代器 start 和 end 划分的范围)内的元素的次序
 * 
*/
void foo_reverse(void) {
  vector<int> __v;
  for (size_t i = 0; i < 5; ++i) {
    __v.push_back(i);
  }

  reverse(__v.begin(), __v.end());\
}

int main(void) {
  /* foo_merge(); */
  /* foo_sort(); */
  /* foo_random_shuffle(); */
  foo_reverse();

  system("pause");
  return EXIT_SUCCESS;
}