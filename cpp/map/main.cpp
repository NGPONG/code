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
 * map ����ָ�������������ͣ�����
 *  K ��Ϊ�ڵ�� �� �ľ�������
 *  V ��Ϊ�ڵ�� ֵ �ľ�������
 *  F ��Ϊָ�� map ����������Ҹ�����һ���ṩ�� �������� �Ĺ��ܵ�Ĭ������ [less<T>]��������Ҫ�����ǿ�����ʾ��ָ����
 * 
 * map<K, V, F = less<K>>()                   Ĭ�Ϲ��죬����һ���յ� map ����
 * map(const set &__m)                        �������캯���������� map ����ʵ���ڲ���ά���ĺ�����Ľڵ㿽������ǰ map ����ʵ���ڲ���ά���ĺ��������
*/
void fun_constructor(void) {
  /* map<K, V, F = less<K>>() */
  map<string, int, __DESC<string>> __m_nor;

  /* set(const set &__s) */
  map<string, int, __DESC<string>> __m_des(__m_nor);
}

/** ASSIGNMENT
 * map &operator=(const map &__m)     ������ֵ��������������� map ��ʵ���ڲ���ά���ĺ����Ľڵ�ȥ���¹��쵱ǰ map ����ʵ�������ڲ���ά���ĺ����
 * void swap(map &__m)                ����Ŀ�� map �����뵱ǰ map �����ڲ�ָ���Ŵ����ڶ��еĺ������ָ�룬�����¸���˫�������ڲ���ά���ĺ������ size
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
 * size_t size()                    ���� map �����ڲ���ά���ĺ�����Ľڵ����
 * bool empty()                     �ж��Ƿ���һ�������������κνڵ�����ӣ�
*/
void fun_size(void) {
  map<string, int> __m;

  /* size_t size() */
  int cout = __m.size();

  /* bool empty() */
  bool flag = __m.empty();
}

/** INSERT
 * pair<map<K,V>::iterator, bool> insert(pair<const K,V> __p)    �� map �����ڲ���ά���ĺ����������һ���ڵ㣬������ýڵ�ļ�Ϊ���� __p �ĵ�һԪ�أ��ýڵ��ֵΪ���� __p �ĵڶ�Ԫ�أ���󷵻��ܹ���ʶ��ǰ������Ľڵ����������е�λ�õĵ��������Ƿ����ɹ�����϶��ɵĶ���
 * V &operator[](const K &_key)                                  �� map �����ڲ���ά���ĺ������������ָ���� �� _key �����Ƿ���ڸýڵ㣬�粻���ڣ������� map ��ָ���� ֵ �����Ͳ�������Ĭ�Ϲ���ȥ����һ��Ĭ�ϵ� ֵ ����� _key ���а󶨣�Ȼ������������һ���ڵ㣬��󷵻ظ� ֵ ������
*/
void fun_insert(void) {
  map<string, int> __m;

  pair<map<string, int>::iterator, bool> result_01 = __m.insert(pair<string, int>("C", 3));
  pair<map<string, int>::iterator, bool> result_02 = __m.insert(make_pair("A", 1));
  pair<map<string, int>::iterator, bool> result_03 = __m.insert(map<string, int>::value_type("D", 4));

  __m["B"] = 2;
}

/** DELETE
 * void clear()                                                                 ɾ�� map �����ڲ���ά���ĺ���������еĽڵ�
 * map<K,V>::iterator erase(map<K,V>::iterator start, map<K,V>::iterator end)   map �����ڲ���ά���ĺ������ɾ�������� start �� ������ end ��ָ����±�֮������еĽڵ㣬��󷵻�ָ��ǰ������Ԫ�ص���һ��Ԫ�صĵ�����
 * map<K,V>::iterator erase(map<K,V>::iterator pos)                             map �����ڲ���ά���ĺ������ɾ�������� pos ��ָ��Ľڵ㣬��󷵻�ָ��ǰ������Ԫ�ص���һ��Ԫ�صĵ�����
 * void erase(K _key)                                                           map �����ڲ���ά���ĺ������ɾ����Ӧ�� _key �Ľڵ�
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
 * map<K,V>::iterator find(K _key)                                              �� map �ڲ���ά���ĺ�����в�������ϼ�ֵ _key �Ľ�㲢���ظý�������±�ĵ���������������ƥ���ֵ _key �Ľڵ㣬�򷵻�ָ�����һ��Ԫ�صĺ�һ��λ�õĵ��������� map<K,V>.end() �ĵ��ý��
 * size_t count(K _key)                                                         �� map �ڲ���ά���ĺ�����в�������ϼ�ֵ _key �Ľ��ĸ���
 * map<K,V>::iterator lower_bound(K _key)                                       �� map �ڲ���ά���ĺ�����в�������� Ŀ��ڵ�� >= _key �Ľ�㲢���ظý�������±�ĵ��������������ڣ��򷵻�ָ�����һ��Ԫ�صĺ�һ��λ�õĵ��������� map<K,V>.end() �ĵ��ý��
 * map<K,V>::iterator upper_bound(K _key)                                       �� map �ڲ���ά���ĺ�����в�������� Ŀ��ڵ�� > _key �Ľ�㲢���ظý�������±�ĵ��������������ڣ��򷵻�ָ�����һ��Ԫ�صĺ�һ��λ�õĵ��������� map<K,V>.end() �ĵ��ý��
 * pair<map<K,V>::iterator, map<K,V>::iterator> equal_range(K _key)             ����ָ���ļ�ֵ _key ���� lower_bound �� upper_bound ��������ȡ���ĵ��������� pair������ first Ϊ lower_bound ���ý������ȡ���ĵ�������second Ϊ upper_bound ���ý������ȡ���ĵ�����
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