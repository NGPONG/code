#include <iostream>
using namespace std;

#include <deque>
#include <vector>

/** CONSTRUCTOR
 * deque<T>()                      默认构造，构建一个空的 deque 容器
 * deque<T>(V _begin, V _end)      该构造函数是一个存在虚拟类型为 V 的模板函数，V 的具体化用于接收能够指示一段线性数组 [begin, end) 开闭区间的迭代器(隶属于容器的)亦或者地址，并使用它来完成当前 deque 容器内部所维护的动态数组的初始化工作
 * deque<T>(int n, T _element)     该构造函数使用 n 个 _element 用于 deque 容器内部动态数组的初始化构造工作
 * deque(const vector &_vec)       拷贝构造函数，将已有 deque 容器实例内部所维护的动态数组中的元素拷贝至当前 deque 容器实例内部所维护的动态数组中
*/
void fun_constructor(void) {
  /* deque<T>() */
  deque<int> dq_empty;

  /* deque<T>(V _begin, V _end) */
  deque<int> dq_01(dq_empty.begin(), dq_empty.end());
  int nums[5] = { 1, 2, 3, 4, 5 };
  deque<int> dq_02(nums, nums + (sizeof(nums) / sizeof(int)));

  /* deque<T>(int n, T _element) */
  deque<int> dq_03(10, 23);

  /* deque(const vector &_vec) */
  deque<int> dq_04(dq_02);
}

/** ASSIGNMENT
 * void assign(V _begin, V _end)               该函数是一个存在虚拟类型为 V 的模板函数，V 的具体化用于接收能够指示一段线性数组 [begin, end) 开闭区间的迭代器(隶属于容器的)亦或者地址，并使用它来完成当前 deque 容器实例内部所维护的动态数组的重新赋值的工作
 * void assign(int n, _element)                该函数使用 n 个 _element 用于 deque 容器内部所维护的动态数组的重新赋值的工作
 * deque &operator=(const deque &_deq)         拷贝赋值运算符，依据已有 deque 的实例内部所维护的动态数组中的元素去重新构造当前 deque 容器实例本身内部所维护的动态数组
 * void swap(deque &_deq)                      交换目标 deque 容器与当前 deque 容器内部指向着用于管控分段式内存区域的中控器的指针，并重新更新双方容器内部所维护的动态数组的 size
*/
void fun_assignment(void) {
  int nums_src[5] = { 1, 2, 3, 4, 5 };
  deque<int> dq_src;

  /* void assign(V _begin, V _end) */
  dq_src.assign(nums_src, nums_src + (sizeof(nums_src) / sizeof(int)));

  /* void assign(int n, _element) */
  dq_src.assign(10, 1024);

  deque<int> dq_des;

  /* deque &operator=(const deque &_deq) */
  dq_des = dq_src;

  /* void swap(vector &_vec) */
  dq_des.swap(dq_src);
}

/** SIZE
 * size_t size()                    返回 deque 容器内部动态数组的元素个数
 * bool empty()                     判断是否是一个空容器（无任何有效元素的录入）
 * void resize(int n)               重新指定 deque 容器内部所维护的动态数组的长度为 n，如果 n 较调用前的长度大，则以默认值填充超出的位置，如果 n 较调用前的长度小，则末尾超出数组长度的元素被删除
 * void resize(int n, T _element)   重新指定 deque 容器内部动态数组的长度为 n，如果 n 较调用前的长度大，则以拷贝所指定的 _element 去填充超出的位置，如果 n 较调用前的长度小，则末尾超出数组长度的元素被删除
*/
void fun_size(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  deque<int> _dq(nums, nums + (sizeof(nums) / sizeof(int)));

  /* size_t size() */
  size_t _dq_size = _dq.size();

  /* bool empty() */
  bool is_empty = _dq.empty();

  /* void resize(int n) */
  _dq.resize(10);

  /* void resize(int n, T _element) */
  _dq.resize(7, 0x400);
}

/** GET
 * T &at(int _idx)     返回 deque 容器内部所维护的动态数组的下标为 _idx 的元素的引用，如果 _idx 超出内部数组的有效元素个数，则抛出out_of_range异常
 * T &operator[_idx]   返回 deque 容器内部所维护的动态数组的下标为 _idx 的元素的引用，如果 _idx 超出内部数组的有效元素个数，则程序崩溃
 * T &front()          返回 deque 容器内部所维护的动态数组的首元素的引用
 * T &back()           返回 deque 容器内部所维护的动态数组的尾元素的引用
*/
void fun_get(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  deque<int> _dq(nums, nums + (sizeof(nums) / sizeof(int)));

  int &num_01 = _dq.at(0);
  int &num_02 = _dq[1];
  int &num_03 = _dq.front();
  int &num_04 = _dq.back();
}

/** INSERT
 * void insert(const_iterator pos,T _element)    根据迭代器 pos 所指向的元素的下标往 deque 容器内部所维护的动态数组中插入一个元素 _elemenet，如果迭代器 pos 所指向的元素下标超出了动态数组的真实容量，则程序崩溃
 * void push_back(T _element)                    往 deque 容器内部的动态数组的尾部插入元素 _element
 * void push_front(T _element)                   往 deque 容器内部的动态数组的首部插入元素 _element
*/
void fun_insert(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  deque<int> _dq(nums, nums + (sizeof(nums) / sizeof(int)));

  /* void insert(const_iterator pos,T _element) */
  _dq.insert(_dq.begin() + 2, 0x400);

  /* void push_back(T _element) */
  _dq.push_back(0x200);

  /* void push_front(T _element) */
  _dq.push_front(0x100);
}

/** DELETE
 * void pop_back()                                        删除 deque 容器内部的动态数组中的尾元素
 * void pop_front()                                       删除 deque 容器内部的动态数组中的首元素
 * void erase(const_iterator start, const_iterator end)   deque 容器内部所维护的动态数组中删除迭代器 start 和 迭代器 end 所指向的下标之间的所有的元素
 * void erase(const_iterator pos)                         deque 容器内部所维护的动态数组中删除迭代器 pos 所指向的元素
 * void clear()                                           删除 deque 容器内部的动态数组中的所有的元素
*/
void fun_delete(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  deque<int> _dq(nums, nums + (sizeof(nums) / sizeof(int)));

  /* void pop_back() */
  _dq.pop_back();

  /* void pop_front() */
  _dq.pop_front();

  /* void erase(const_iterator start, const_iterator end) */
  _dq.erase(_dq.begin(), _dq.begin() + 2);

  /* void erase(const_iterator pos) */
  _dq.erase(_dq.begin() + 1);

  /* void clear() */
  _dq.clear();
}

int main(void) {

  system("pause");
  return EXIT_SUCCESS;
}