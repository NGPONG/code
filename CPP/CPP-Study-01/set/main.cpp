#include <iostream>
using namespace std;

#include <set>

template<class _Ty>
struct __DESC {
  constexpr bool operator()(const _Ty &left, const _Ty &right) {
    return left > right;
  }
};

/** CONSTRUCTOR
 * 
 * set 可以指定两种虚拟类型，其中 T 则为节点键值的具体类型，而 F 则为指定 set 的排序规则并且给予了一个提供了 正序排序 的功能默认类型为 less<T>，如有需要，我们可以显示的指定它
 * 
 * set<T,F = less<T>>()                       默认构造，构建一个空的 set 容器
 * set<T,F = less<T>>((V _begin, V _end)      该构造函数是一个存在虚拟类型为 V 的模板函数，V 的具体化用于接收能够指示一段线性数组 [begin, end) 开闭区间的迭代器(隶属于容器的)亦或者地址，并使用它来完成当前 set 容器内部所维护的红黑树的初始化工作)
 * set(const set &__s)                        拷贝构造函数，将已有 set 容器实例内部所维护的红黑树的节点拷贝至当前 set 容器实例内部所维护的红黑树当中
*/
void fun_constructor(void) {
  /* set<T,F = less<T>>() */
  set<int> __s_nor;

  /* set<T,F = less<T>>((V _begin, V _end) */
  int nums[5] = { 3, 1, 5, 2, 4 };
  set<int, __DESC<int>> __s(nums, nums + sizeof(nums) / sizeof(int));

  /* set(const set &__s) */
  set<int, __DESC<int>> __s_des(__s);
}

/** ASSIGNMENT
 * set &operator=(const set &__s)     拷贝赋值运算符，依据已有 set 的实例内部所维护的红黑书的节点去重新构造当前 set 容器实例本身内部所维护的红黑树
 * void swap(set &__s)                交换目标 set 容器与当前 set 容器内部指向着存在于堆中的红黑树的指针，并重新更新双方容器内部所维护的红黑树的 size
*/
void fun_assignment(void) {
  int nums_01[5] = { 3, 1, 5, 2, 4 };
  set<int> __s_01(nums_01, nums_01 + sizeof(nums_01) / sizeof(int));

  int nums_02[5] = { 9, 6, 10, 8, 7 };
  set<int> __s_02(nums_02, nums_02 + sizeof(nums_02) / sizeof(int));

  /* void swap(set &__s) */
  __s_01.swap(__s_02);

  /* set &operator=(const set &__s) */
  __s_01 = __s_02;
}

/** SIZE
 * size_t size()                    返回 set 容器内部所维护的红黑树的节点个数
 * bool empty()                     判断是否是一个空容器（无任何节点的链接）
*/
void fun_size(void) {
  int nums[5] = { 3, 1, 5, 2, 4 };
  set<int> __s(nums, nums + sizeof(nums) / sizeof(int));

  /* size_t size() */
  int cout = __s.size();

  /* bool empty() */
  bool flag = __s.empty();
}

/** INSERT
 * pair<set<T>::iterator, bool> insert(T _key)    向 set 容器内部所维护的红黑树中新增一个节点，并赋予该节点的键值为 _key，最后返回能够标识当前所插入的节点在整个数中的位置的迭代器和是否插入成功所结合而成的 pair
*/
void fun_insert(void) {
  int nums[5] = { 3, 1, 5, 2, 4 };
  set<int> __s(nums, nums + sizeof(nums) / sizeof(int));

  /* pair<set<T>::iterator, bool> insert(T _key) */
  pair<set<int>::iterator, bool> result = __s.insert(0x400);

  for (; result.first != __s.end(); ++result.first) {
    cout << *(result.first) << endl;
  }
}

/** DELETE
 * void clear()                                                                             删除 set 容器内部所维护的红黑树的所有的节点
 * set<T>::const_iterator erase(set<T>::const_iterator start, set<T>::const_iterator end)   set 容器内部所维护的红黑树中删除迭代器 start 和 迭代器 end 所指向的下标之间的所有的节点，最后返回只想当前所操作元素的下一个元素的迭代器
 * set<T>::const_iterator erase(set<T>::const_iterator pos)                                 set 容器内部所维护的双向循环链表中删除迭代器 pos 所指向的节点，最后返回只想当前所操作元素的下一个元素的迭代器
 * void erase(T _key)                                                                       set 容器内部所维护的红黑树中删除对应键值 _key 的节点
 * 
*/
void fun_delete(void) {
  int nums[5] = { 3, 1, 5, 2, 4 };
  set<int> __s(nums, nums + sizeof(nums) / sizeof(int));

  /* void erase(set<T>::const_iterator pos) */
  __s.erase(__s.begin(), ++__s.begin());

  /* void erase(set<T>::const_iterator start, set<T>::const_iterator end) */
  __s.erase(__s.begin());

  /* void erase(T _key) */
  __s.erase(5);

  /* void clear() */
  __s.clear();
}

/** FIND
 * set<T>::const_iterator find(T _key)                                              在 set 内部所维护的红黑树中查找相符合键值 _key 的结点并返回该结点所在下标的迭代器，若不存在匹配键值 _key 的节点，则返回指向最后一个元素的后一个位置的迭代器，即 set<int>.end() 的调用结果
 * size_t count(T _key)                                                             在 set 内部所维护的红黑树中查找相符合键值 _key 的结点的个数
 * set<T>::const_iterator lower_bound(T _key)                                       在 set 内部所维护的红黑树中查找相符合 目标节点键值 >= _key 的结点并返回该结点所在下标的迭代器，若不存在，则返回指向最后一个元素的后一个位置的迭代器，即 set<int>.end() 的调用结果
 * set<T>::const_iterator upper_bound(T _key)                                       在 set 内部所维护的红黑树中查找相符合 目标节点键值 > _key 的结点并返回该结点所在下标的迭代器，若不存在，则返回指向最后一个元素的后一个位置的迭代器，即 set<int>.end() 的调用结果
 * pair<set<int>::const_iterator, set<int>::const_iterator> equal_range(T _key)     依据指定的键值 _key 返回 lower_bound 和 upper_bound 调用所获取到的 迭代器 的组合值 pair，其中 first 为 lower_bound 调用结果所获取到的迭代器，second 为 upper_bound 调用结果所获取到的迭代器
*/
void fun_find() {
  int nums[5] = { 3, 1, 5, 2, 4 };
  set<int> __s(nums, nums + sizeof(nums) / sizeof(int));

  /* set<T>::const_iterator find(T _key) */
  set<int>::const_iterator it_find = __s.find(2);

  /* size_t count(T _key) */
  size_t count = __s.count(3);

  /* set<T>::const_iterator lower_bound(T _key) */
  set<int>::const_iterator it_lower = __s.lower_bound(3);

  /* set<T>::const_iterator upper_bound(T _key) */
  set<int>::const_iterator it_uppler = __s.upper_bound(3);

  /* pair<set<int>::const_iterator, set<int>::const_iterator> equal_range(T _key) */
  pair<set<int>::const_iterator, set<int>::const_iterator> _res = __s.equal_range(3);
}

int main(void) {
  /* fun_constructor(); */
  /* fun_insert(); */
  /* fun_delete(); */

  fun_find();

  system("pause");
  return EXIT_SUCCESS;
}