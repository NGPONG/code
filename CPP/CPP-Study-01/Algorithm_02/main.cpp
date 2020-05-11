#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

/** find
 * 
 * iterator_pos find(iterator start, iterator end, T _val)
 * 
 * 根据指定容器的迭代器 start 和 迭代器 end 在容器内部中查找值为 _val 的元素并返回第一次找到该元素所在下标的 [目标容器类型的迭代器]，若不存在，则返回指向最后一个元素的后一个位置的迭代器
*/
void foo_find(void) {
  vector<int> __v;
  for (size_t i = 0; i < 10; ++i) {
    __v.push_back(i);
  }

  vector<int>::iterator _pos = find(__v.begin(), __v.end(), 4);
  if (_pos != __v.end()) cout << *_pos << endl;
}

/** find_if
 * 
 * iterator_pos find_if(iterator start, iterator end, function _fn)
 * 
 * 依据指定容器的迭代器 start 和 迭代器 end 去遍历容器中的元素，把它们作为实参逐个输入至所指定的 返回值为 bool 类型的二元仿函数或者函数指针 _fn 当中，当 _fn 所返回的结果为 true 时，则该函数返回当前元素所在下标的  最后会返回所指定的 一元仿函数或者函数指针
*/
void foo_find_if(void) {
  
}

int main(void) {
  /* foo_find(); */

  system("pause");
  return EXIT_SUCCESS;
}