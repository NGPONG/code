#include <iostream>
using namespace std;

#include <map>
#include <set>

template<class _Ty>
struct __DESC {
  constexpr bool operator()(const _Ty &left, const _Ty &right) {
    return left > right;
  }
};

/** CONSTRUCTOR
 * 
 * map 可以指定三种虚拟类型，其中
 *  K 则为节点的 键 的具体类型
 *  V 则为节点的 值 的具体类型
 *  F 则为指定 map 的排序规则并且给予了一个提供了 正序排序 的功能的默认类型 [less<T>]，如有需要，我们可以显示的指定它
 * 
 * map<K, V, F = less<K>>()                   默认构造，构建一个空的 map 容器
 * map(const set &__m)                        拷贝构造函数，将已有 map 容器实例内部所维护的红黑树的节点拷贝至当前 map 容器实例内部所维护的红黑树当中
*/
void fun_constructor(void) {
  /* map<K, V, F = less<K>>() */
  map<string, int, __DESC<string>> __m_nor;

  /* set(const set &__s) */
  map<string, int, __DESC<string>> __m_des(__m_nor);
}

/** ASSIGNMENT
 * map &operator=(const map &__m)     拷贝赋值运算符，依据已有 map 的实例内部所维护的红黑书的节点去重新构造当前 map 容器实例本身内部所维护的红黑树
 * void swap(map &__m)                交换目标 map 容器与当前 map 容器内部指向着存在于堆中的红黑树的指针，并重新更新双方容器内部所维护的红黑树的 size
*/
void fun_assignment(void) {
  map<string, int> __m_src;
  __m_src["C"] = 3;
  __m_src.insert(make_pair("A", 1));
  __m_src.insert(map<string, int>::value_type("B", 2));

  map<string, int> __m_des;

  /* void swap(set &__s) */
  __m_src.swap(__m_des);

  /* set &operator=(const set &__s) */
  __m_src = __m_des;
}

/** SIZE
 * size_t size()                    返回 map 容器内部所维护的红黑树的节点个数
 * bool empty()                     判断是否是一个空容器（无任何节点的链接）
*/
void fun_size(void) {
  map<string, int> __m;

  /* size_t size() */
  int cout = __m.size();

  /* bool empty() */
  bool flag = __m.empty();
}

/** INSERT
 * pair<map<K,V>::iterator, bool> insert(pair<const K,V> __p)    向 map 容器内部所维护的红黑树中新增一个节点，并赋予该节点的键为对组 __p 的第一元素，该节点的值为对组 __p 的第二元素，最后返回能够标识当前所插入的节点在整个数中的位置的迭代器和是否插入成功所结合而成的对组
 * V &operator[](const K &_key)                                  向 map 容器内部所维护的红黑树中依据所指定的 键 _key 搜索是否存在该节点，如不存在，则依据 map 所指定的 值 的类型并调用其默认构造去创建一个默认的 值 并与键 _key 进行绑定，然后往树种新增一个节点，最后返回该 值 的引用
*/
void fun_insert(void) {
  map<string, int> __m;

  pair<map<string, int>::iterator, bool> result_01 = __m.insert(pair<string, int>("C", 3));
  pair<map<string, int>::iterator, bool> result_02 = __m.insert(make_pair("A", 1));
  pair<map<string, int>::iterator, bool> result_03 = __m.insert(map<string, int>::value_type("D", 4));

  __m["B"] = 2;
}

/** DELETE
 * void clear()                                                                 删除 map 容器内部所维护的红黑树的所有的节点
 * map<K,V>::iterator erase(map<K,V>::iterator start, map<K,V>::iterator end)   map 容器内部所维护的红黑树中删除迭代器 start 和 迭代器 end 所指向的下标之间的所有的节点，最后返回指向当前所操作元素的下一个元素的迭代器
 * map<K,V>::iterator erase(map<K,V>::iterator pos)                             map 容器内部所维护的红黑树中删除迭代器 pos 所指向的节点，最后返回指向当前所操作元素的下一个元素的迭代器
 * void erase(K _key)                                                           map 容器内部所维护的红黑树中删除对应键 _key 的节点
 * 
*/
void fun_delete(void) {
  map<string, int> __m;
  __m["C"] = 3;
  __m["A"] = 1;
  __m["D"] = 4;
  __m["B"] = 2;

  /* map<K,V>::iterator erase(map<K,V>::iterator pos) */
  __m.erase(__m.begin(), ++(++__m.begin()));

  /* map<K,V>::iterator erase(map<K,V>::iterator start, map<K,V>::iterator end) */
  __m.erase(__m.begin());

  /* void erase(K _key) */
  __m.erase("C");

  /* void clear() */
  __m.clear();
}

/** FIND
 * map<K,V>::iterator find(K _key)                                              在 map 内部所维护的红黑树中查找相符合键值 _key 的结点并返回该结点所在下标的迭代器，若不存在匹配键值 _key 的节点，则返回指向最后一个元素的后一个位置的迭代器，即 map<K,V>.end() 的调用结果
 * size_t count(K _key)                                                         在 map 内部所维护的红黑树中查找相符合键值 _key 的结点的个数
 * map<K,V>::iterator lower_bound(K _key)                                       在 map 内部所维护的红黑树中查找相符合 目标节点键 >= _key 的结点并返回该结点所在下标的迭代器，若不存在，则返回指向最后一个元素的后一个位置的迭代器，即 map<K,V>.end() 的调用结果
 * map<K,V>::iterator upper_bound(K _key)                                       在 map 内部所维护的红黑树中查找相符合 目标节点键 > _key 的结点并返回该结点所在下标的迭代器，若不存在，则返回指向最后一个元素的后一个位置的迭代器，即 map<K,V>.end() 的调用结果
 * pair<map<K,V>::iterator, map<K,V>::iterator> equal_range(K _key)             依据指定的键值 _key 返回 lower_bound 和 upper_bound 调用所获取到的迭代器对组 pair，其中 first 为 lower_bound 调用结果所获取到的迭代器，second 为 upper_bound 调用结果所获取到的迭代器
*/
void fun_find() {
  map<string, int> __m;
  __m["C"] = 3;
  __m["A"] = 1;
  __m["D"] = 4;
  __m["B"] = 2;

  /* map<K,V>::iterator find(K _key) */
  map<string, int>::iterator it_find = __m.find("B");

  /* size_t count(K _key) */
  size_t count = __m.count("A");

  /* map<K,V>::iterator lower_bound(K _key) */
  map<string, int>::iterator it_lower = __m.lower_bound("C");

  /* map<K,V>::iterator upper_bound(T _key) */
  map<string, int>::iterator it_uppler = __m.upper_bound("C");

  /* pair<map<K,V>::iterator, map<K,V>::iterator> equal_range(K _key) */
  pair<map<string, int>::iterator, map<string, int>::iterator> _res = __m.equal_range("C");
}

int main(void) {
  /* fun_constructor(); */
  /* fun_insert(); */
  /* fun_delete(); */
  /* fun_find(); */
  /* fun_assignment(); */
  /* fun_insert(); */

  system("pause");
  return EXIT_SUCCESS;
}