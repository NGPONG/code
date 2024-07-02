#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

/** find
 * 
 * iterator_pos find(iterator start, iterator end, T _val)
 * 
 * 在容器指定范围(迭代器 start 和 end 划分的范围)内的元素中查找值为 _val 的元素并返回第一次找到该元素所在下标的 [目标容器类型的迭代器]，若不存在，则返回指向最后一个元素的后一个位置的迭代器
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
 * 遍历容器指定范围(迭代器 start 和 end 划分的范围)内的元素，把它们作为实参逐个输入至所指定的 返回值为 bool 类型的一元仿函数或者函数指针 _fn 当中，当 _fn 所返回的结果为 true 时，则该函数返回当前元素所在下标的 [目标容器类型的迭代器]，若不存在，则返回指向最后一个元素的后一个位置的迭代器
 * 
*/
void foo_find_if(void) {
  vector<int> __v;
  for (size_t i = 0; i < 10; ++i) {
    __v.push_back(i);
  }

  vector<int>::iterator _result = find_if(__v.begin(), __v.end(), [](int &_val) { return _val > 3; });
  if (_result != __v.end()) cout << *_result << endl;
}

/** adjacent_find
 * 
 * iterator_pos adjacent_find(iterator start, iterator end)
 * 
 * 遍历容器指定范围(迭代器 start 和 end 划分的范围)内的元素，并寻找间隔相邻的并且值重复的元素，如果存在，则返回所重复元素的上一个元素所在下标的 [目标容器类型的迭代器]，若不存在，则返回指向最后一个元素的后一个位置的迭代器
 * 
*/
void foo_adjacent_find(void) {
  vector<int> __v;
  __v.push_back(1);
  __v.push_back(2);
  __v.push_back(3);
  __v.push_back(3);
  __v.push_back(4);

  vector<int>::iterator _result = adjacent_find(__v.begin(), __v.end());
  if (_result != __v.end()) cout << *_result << endl;
}

/** binary_search
 * 
 * bool binary_search(iterator start, iterator end, const T &_val)
 * 
 * 使用二分查找法查找容器指定范围(迭代器 start 和 end 划分的范围)内的元素，并判断是否存在值为 _val 的元素，如果存在则返回 true，如果不存在则返回false
 * 由于该算法使用的是二分查找法，为了该算法的运行不会失效，我们需要保证指定的容器内部所存储的元素是一个 有序序列
 * 
*/
void foo_binary_search(void) {
  vector<int> __v;
  for (size_t i = 0; i < 10; ++i) {
    __v.push_back(i);
  }

  bool _result = binary_search(__v.begin(), __v.end(), 3);
  cout << _result << endl;
}

/** count
 * 
 * int binary_search(iterator start, iterator end, const T &_val)
 * 
 * 遍历容器指定范围(迭代器 start 和 end 划分的范围)内的元素，并统计值为 _val 的元素所出现的次数并返回
 * 
*/
void foo_count(void) {
  vector<int> __v;
  __v.push_back(1);
  __v.push_back(2);
  __v.push_back(3);
  __v.push_back(3);
  __v.push_back(4);
  
  int _count = count(__v.begin(), __v.end(), 3);
}

/** count_if
 * 
 * int count_if(iterator start, iterator end, function _fn)
 * 
 * 遍历容器指定范围(迭代器 start 和 end 划分的范围)内的元素，把它们作为实参逐个输入至所指定的 返回值为 bool 类型的一元仿函数或者函数指针 _fn 当中，并统计 _fn 返回值为 true 的次数，最后返回所统计的结果
 * 
*/
void foo_count_if(void) {
  vector<int> __v;
  for (size_t i = 0; i < 10; ++i) {
    __v.push_back(i);
  }

  int _count = count_if(__v.begin(), __v.end(), [](int &_val) { 
    return _val > 5; 
  });
  cout << _count << endl;
}

int main(void) {
  /* foo_find(); */
  /* foo_find_if(); */
  /* foo_adjacent_find(); */
  /* foo_binary_search(); */
  /* foo_count(); */
  /* foo_count_if(); */

  system("pause");
  return EXIT_SUCCESS;
}
