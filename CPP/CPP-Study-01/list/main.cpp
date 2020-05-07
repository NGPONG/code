#include <iostream>
using namespace std;

#include <list>

/** CONSTRUCTOR
 * list<T>()                      默认构造，构建一个空的 list 容器
 * list<T>(V _begin, V _end)      该构造函数是一个存在虚拟类型为 V 的模板函数，V 的具体化用于接收能够指示一段线性数组 [begin, end) 开闭区间的迭代器(隶属于容器的)亦或者地址，并使用它来完成当前 list 容器内部所维护的双向循环链表的初始化工作
 * list(int n, T _element)        该构造函数使用 n 个 _element 用于 list 容器内部双向循环链表的初始化构造工作
 * list(const list &_li)          拷贝构造函数，将已有 list 容器实例内部所维护的双向循环链表中的节点拷贝至当前 list 容器实例内部所维护的双向循环链表中
*/
void fun_constructor(void) {
  /* list<T>() */
  list<int> li_empty;

  /* list<T>(V _begin, V _end) */
  list<int> li_01(li_empty.begin(), li_empty.end());
  int nums[5] = { 1, 2, 3, 4, 5 };
  list<int> li_02(nums, nums + (sizeof(nums) / sizeof(int)));

  /* deque<T>(int n, T _element) */
  list<int> li_03(10, 23);

  /* deque(const vector &_vec) */
  list<int> li_04(li_02);
}

/** ASSIGNMENT
 * void assign(V _begin, V _end)      该函数是一个存在虚拟类型为 V 的模板函数，V 的具体化用于接收能够指示一段线性数组 [begin, end) 开闭区间的迭代器(隶属于容器的)亦或者地址，并使用它来完成当前 list 容器实例内部所维护的双向循环链表的重新赋值的工作
 * assign(int n, _element)            该函数使用 n 个 _element 用于 list 容器内部所维护的双向循环链表的重新赋值的工作
 * list &operator=(const list &_li)   拷贝赋值运算符，依据已有 list 的实例内部所维护的双向循环链表中的节点去重新构造当前 list 容器实例本身内部所维护的双向循环链表
 * void swap(list &_li)               交换目标 list 容器与当前 list 容器内部指向着存在于堆中的双向循环链表的指针，并重新更新双方容器内部所维护的双向循环链表的 size
*/
void fun_assignment(void) {
  int nums_src[5] = { 1, 2, 3, 4, 5 };
  list<int> li_src;

  /* void assign(V _begin, V _end) */
  li_src.assign(nums_src, nums_src + (sizeof(nums_src) / sizeof(int)));

  /* void assign(int n, _element) */
  li_src.assign(10, 1024);

  list<int> li_des;

  /* list &operator=(const list &_li) */
  li_des = li_src;

  /* void swap(list &_li) */
  li_des.swap(li_src);
}


/** SIZE
 * size_t size()                    返回 list 容器内部双向循环链表的节点个数
 * bool empty()                     判断是否是一个空容器（无任何节点的链接）
 * void resize(int n)               重新指定 list 容器内部所维护的双向循环链表的节点链接长度为 n，如果 n 较调用前的长度大，则以默认值填充超出的位置，如果 n 较调用前的长度小，则删除超出链表长度 n 的节点
 * void resize(int n, T _element)   重新指定 list 容器内部所维护的双向循环链表的节点链接长度为 n，如果 n 较调用前的长度大，则拷贝所指定的 _element 去填充超出的位置，如果 n 较调用的长度小，则删除超出链表长度 n 的节点
*/
void fun_size(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  list<int> _li(nums, nums + (sizeof(nums) / sizeof(int)));

  /* size_t size() */
  size_t _li_size = _li.size();

  /* bool empty() */
  bool is_empty = _li.empty();

  /* void resize(int n) */
  _li.resize(10);

  /* void resize(int n, T _element) */
  _li.resize(7, 0x400);
}

/** INSERT
 * void push_back(T _element)                    从 list 容器内部的双向循环链表的尾处新增数据域为 _element 的节点
 * void push_front(T _element)                   从 list 容器内部的双向循环链表的首处新增数据域为 _element 的节点
 * void insert(const_iterator pos,T _element)    根据迭代器 pos 所指向的节点的下标往 list 容器内部所维护的双向循环链表中插入一个数据域为 _elemenet 的节点，如果迭代器 pos 所指向的元素下标超出了双向循环链表的长度，则程序崩溃
*/
void fun_insert(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  list<int> _li(nums, nums + (sizeof(nums) / sizeof(int)));

  /* void insert(const_iterator pos,T _element) */
  _li.insert(++_li.begin(), 0x400);

  /* void push_back(T _element) */
  _li.push_back(0x200);

  /* void push_front(T _element) */
  _li.push_front(0x100);
}

/** DELETE
 * void pop_back()                                                          删除 list 容器内部的双向循环链表中的尾节点
 * void pop_front()                                                         删除 list 容器内部的双向循环链表中的首节点
 * void clear()                                                             删除 list 容器内部的双向循环链表中的所有的节点
 * void erase(list<T>::const_iterator start, list<T>::const_iterator end)   list 容器内部所维护的双向循环链表中删除迭代器 start 和 迭代器 end 所指向的下标之间的所有的节点
 * void erase(list<T>::const_iterator pos)                                  list 容器内部所维护的双向循环链表中删除迭代器 pos 所指向的节点
*/
void fun_delete(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  list<int> _li(nums, nums + (sizeof(nums) / sizeof(int)));

  /* void pop_back() */
  _li.pop_back();

  /* void pop_front() */
  _li.pop_front();

  /* void erase(const_iterator start, const_iterator end) */
  _li.erase(_li.begin(), ++_li.begin());

  /* void erase(const_iterator pos) */
  _li.erase(++_li.begin());

  /* void clear() */
  _li.clear();
}

/** GET
 * T &front()      返回 list 容器内部所维护的双向链表的首节点数据域的引用
 * T &back()       返回 list 容器内部所维护的双向链表的尾节点数据域的引用
*/
void fun_get(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  list<int> _li(nums, nums + (sizeof(nums) / sizeof(int)));
  int &num_03 = _li.front();
  int &num_04 = _li.back();
}

bool __sort(int &num_01, int &num_02) {
  return num_01 < num_02;
}
/** COMMON
 * reverse()          链表反转
 * sort(T __fu)       依据所指定的返回值为 bool 并拥有两个链表节点数据域形参的函数（仿函数）去进行链表的排序
*/
void fun_common(void) {
  int nums[5] = { 3, 2, 4, 1, 5 };
  list<int> _li(nums, nums + (sizeof(nums) / sizeof(int)));

  /* sort(T __fu) */
  _li.sort(__sort);

  /* reverse() */
  _li.reverse();
}


int main(void) {
  fun_common();


  system("pause");
  return EXIT_SUCCESS;
}