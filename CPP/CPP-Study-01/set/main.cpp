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
 * set ����ָ�������������ͣ����� T ��Ϊ�ڵ��ֵ�ľ������ͣ��� F ��Ϊָ�� set ����������Ҹ�����һ���ṩ�� �������� �Ĺ���Ĭ������Ϊ less<T>��������Ҫ�����ǿ�����ʾ��ָ����
 * 
 * set<T,F = less<T>>()                       Ĭ�Ϲ��죬����һ���յ� set ����
 * set<T,F = less<T>>((V _begin, V _end)      �ù��캯����һ��������������Ϊ V ��ģ�庯����V �ľ��廯���ڽ����ܹ�ָʾһ���������� [begin, end) ��������ĵ�����(������������)����ߵ�ַ����ʹ��������ɵ�ǰ set �����ڲ���ά���ĺ�����ĳ�ʼ������)
 * set(const set &__s)                        �������캯���������� set ����ʵ���ڲ���ά���ĺ�����Ľڵ㿽������ǰ set ����ʵ���ڲ���ά���ĺ��������
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
 * set &operator=(const set &__s)     ������ֵ��������������� set ��ʵ���ڲ���ά���ĺ����Ľڵ�ȥ���¹��쵱ǰ set ����ʵ�������ڲ���ά���ĺ����
 * void swap(set &__s)                ����Ŀ�� set �����뵱ǰ set �����ڲ�ָ���Ŵ����ڶ��еĺ������ָ�룬�����¸���˫�������ڲ���ά���ĺ������ size
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
 * size_t size()                    ���� set �����ڲ���ά���ĺ�����Ľڵ����
 * bool empty()                     �ж��Ƿ���һ�������������κνڵ�����ӣ�
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
 * pair<set<T>::iterator, bool> insert(T _key)    �� set �����ڲ���ά���ĺ����������һ���ڵ㣬������ýڵ�ļ�ֵΪ _key����󷵻��ܹ���ʶ��ǰ������Ľڵ����������е�λ�õĵ��������Ƿ����ɹ�����϶��ɵ� pair
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
 * void clear()                                                                             ɾ�� set �����ڲ���ά���ĺ���������еĽڵ�
 * set<T>::const_iterator erase(set<T>::const_iterator start, set<T>::const_iterator end)   set �����ڲ���ά���ĺ������ɾ�������� start �� ������ end ��ָ����±�֮������еĽڵ㣬��󷵻�ֻ�뵱ǰ������Ԫ�ص���һ��Ԫ�صĵ�����
 * set<T>::const_iterator erase(set<T>::const_iterator pos)                                 set �����ڲ���ά����˫��ѭ��������ɾ�������� pos ��ָ��Ľڵ㣬��󷵻�ֻ�뵱ǰ������Ԫ�ص���һ��Ԫ�صĵ�����
 * void erase(T _key)                                                                       set �����ڲ���ά���ĺ������ɾ����Ӧ��ֵ _key �Ľڵ�
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
 * set<T>::const_iterator find(T _key)                                              �� set �ڲ���ά���ĺ�����в�������ϼ�ֵ _key �Ľ�㲢���ظý�������±�ĵ���������������ƥ���ֵ _key �Ľڵ㣬�򷵻�ָ�����һ��Ԫ�صĺ�һ��λ�õĵ��������� set<int>.end() �ĵ��ý��
 * size_t count(T _key)                                                             �� set �ڲ���ά���ĺ�����в�������ϼ�ֵ _key �Ľ��ĸ���
 * set<T>::const_iterator lower_bound(T _key)                                       �� set �ڲ���ά���ĺ�����в�������� Ŀ��ڵ��ֵ >= _key �Ľ�㲢���ظý�������±�ĵ��������������ڣ��򷵻�ָ�����һ��Ԫ�صĺ�һ��λ�õĵ��������� set<int>.end() �ĵ��ý��
 * set<T>::const_iterator upper_bound(T _key)                                       �� set �ڲ���ά���ĺ�����в�������� Ŀ��ڵ��ֵ > _key �Ľ�㲢���ظý�������±�ĵ��������������ڣ��򷵻�ָ�����һ��Ԫ�صĺ�һ��λ�õĵ��������� set<int>.end() �ĵ��ý��
 * pair<set<int>::const_iterator, set<int>::const_iterator> equal_range(T _key)     ����ָ���ļ�ֵ _key ���� lower_bound �� upper_bound ��������ȡ���� ������ �����ֵ pair������ first Ϊ lower_bound ���ý������ȡ���ĵ�������second Ϊ upper_bound ���ý������ȡ���ĵ�����
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