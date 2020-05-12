#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
#include <functional>

/** set_intersection
 * 
 * iterator set_intersection(iterator src_start_1, iterator src_end_1, iterator src_start_2, iterator src_end_2, iterator des_start)
 * 
 * 该算法提供查找并集的功能
 * 查找指定范围内(两个容器的开始和起始迭代器 src_start_1、src_end_1、src_start_2、src_end_2) 的两个容器的元素中元素的值相同的元素，并把它重新赋值给目标容器(迭代器 des_start 所指向的容器)当中，最后会返回目标容器的 结束迭代器(end())
 * 我尽量要保证原始的两个容器的数据源是有序序列，否则目标容器所获取到的结果将可能会出现乱序
 * 目标容器在赋值前要保证其内部元素中是含有 [有效元素] 的，否则会调用失败
 * 
*/
void foo_set_intersection(void) {
  vector<int> __v_src_1;
  vector<int> __v_src_2;
  for (size_t i = 0; i < 10; ++i) {
    __v_src_1.push_back(i);
    __v_src_2.push_back(i + 5);
  }

  vector<int> __v_des;
  __v_des.resize(__v_src_1.size(), __v_src_2.size());

  vector<int>::iterator i_end = set_intersection(__v_src_1.begin(), __v_src_1.end(), __v_src_2.begin(), __v_src_2.end(), __v_des.begin());

  for_each(__v_des.begin(), i_end, [](int val) { cout << val << " "; });
  cout << endl;
}

/** set_union
 * 
 * iterator set_union(iterator src_start_1, iterator src_end_1, iterator src_start_2, iterator src_end_2, iterator des_start)
 * 
 * 该算法提供查找交集的功能
 * 去除掉，指定范围内(两个容器的开始和起始迭代器 src_start_1、src_end_1、src_start_2、src_end_2) 的两个容器中，值重复的元素并进行合并，并把合并后的结果重新赋值给目标容器(迭代器 des_start 所指向的容器)当中，最后会返回目标容器的 结束迭代器(end())
 * 我尽量要保证原始的两个容器的数据源是有序序列，否则目标容器所获取到的结果将可能会出现乱序
 * 目标容器在合并前要保证其内部元素中是含有 [有效元素] 的，否则会调用失败
 * 
*/
void foo_set_union(void) {
  vector<int> __v_src_1;
  vector<int> __v_src_2;
  for (int i = 0; i < 10; i++) {
    __v_src_1.push_back(i);
    __v_src_2.push_back(i + 5);
  }

  vector<int> __v_des;
  __v_des.resize(__v_src_1.size() + __v_src_2.size());

  vector<int>::iterator i_end = set_union(__v_src_1.begin(), __v_src_1.end(), __v_src_2.begin(), __v_src_2.end(), __v_des.begin());

  for_each(__v_des.begin(), i_end, [](int _val) { cout << _val << " "; });
  cout << endl;
}

/** set_difference
 * 
 * iterator set_difference(iterator src_start_1, iterator src_end_1, iterator src_start_2, iterator src_end_2, iterator des_start)
 * 
 * 查找容器指定范围(迭代器 src_start_1 和 src_end_1 划分的范围)内 [相较于] 容器指定范围(迭代器 src_start_2 和 src_end_2 划分的范围)内，元素的值不同的元素，并把结果重新赋值给目标容器(迭代器 des_start 所指向的容器)当中，最后会返回目标容器的 结束迭代器(end())
 * 我尽量要保证原始的两个容器的数据源是有序序列，否则目标容器所获取到的结果将可能会出现乱序
 * 目标容器在赋值前要保证其内部元素中是含有 [有效元素] 的，否则会调用失败
*/
void foo_set_difference(void) {
  vector<int> __v_src_1;
  vector<int> __v_src_2;

  for (int i = 0; i < 10; i++) {
    __v_src_1.push_back(i);
    __v_src_2.push_back(i + 5);
  }

  vector<int> __v_des;
  __v_des.resize(max(__v_src_1.size(), __v_src_2.size()));

  vector<int>::iterator i_end = set_difference(__v_src_1.begin(), __v_src_1.end(), __v_src_2.begin(), __v_src_2.end(), __v_des.begin());

  /* vector<int>::iterator i_end = set_difference(__v_src_2.begin(), __v_src_2.end(), __v_src_1.begin(), __v_src_1.end(), __v_des.begin()); */

  for_each(__v_des.begin(), i_end, [](int &_val) { cout << _val << " "; });
  cout << endl;
}

int main(void) {
  /* foo_set_intersection(); */
  /* foo_set_union(); */
  /* foo_set_difference(); */

  system("pause");
  return EXIT_SUCCESS;
}