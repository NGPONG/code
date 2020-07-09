#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

/** find
 * 
 * iterator_pos find(iterator start, iterator end, T _val)
 * 
 * ������ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ���в���ֵΪ _val ��Ԫ�ز����ص�һ���ҵ���Ԫ�������±�� [Ŀ���������͵ĵ�����]���������ڣ��򷵻�ָ�����һ��Ԫ�صĺ�һ��λ�õĵ�����
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
 * ��������ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ�أ���������Ϊʵ�������������ָ���� ����ֵΪ bool ���͵�һԪ�º������ߺ���ָ�� _fn ���У��� _fn �����صĽ��Ϊ true ʱ����ú������ص�ǰԪ�������±�� [Ŀ���������͵ĵ�����]���������ڣ��򷵻�ָ�����һ��Ԫ�صĺ�һ��λ�õĵ�����
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
 * ��������ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ�أ���Ѱ�Ҽ�����ڵĲ���ֵ�ظ���Ԫ�أ�������ڣ��򷵻����ظ�Ԫ�ص���һ��Ԫ�������±�� [Ŀ���������͵ĵ�����]���������ڣ��򷵻�ָ�����һ��Ԫ�صĺ�һ��λ�õĵ�����
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
 * ʹ�ö��ֲ��ҷ���������ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ�أ����ж��Ƿ����ֵΪ _val ��Ԫ�أ���������򷵻� true������������򷵻�false
 * ���ڸ��㷨ʹ�õ��Ƕ��ֲ��ҷ���Ϊ�˸��㷨�����в���ʧЧ��������Ҫ��ָ֤���������ڲ����洢��Ԫ����һ�� ��������
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
 * ��������ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ�أ���ͳ��ֵΪ _val ��Ԫ�������ֵĴ���������
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
 * ��������ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ�أ���������Ϊʵ�������������ָ���� ����ֵΪ bool ���͵�һԪ�º������ߺ���ָ�� _fn ���У���ͳ�� _fn ����ֵΪ true �Ĵ�������󷵻���ͳ�ƵĽ��
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