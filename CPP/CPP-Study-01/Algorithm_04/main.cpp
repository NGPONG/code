#include <iostream>
using namespace std;

#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

/** copy
 * 
 * void copy(iterator src_start, iterator src_end, iterator des_start)
 * 
 * ����ԭʼ������ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ�ز����¸�ֵ��Ŀ������(������ des_start ��ָ�������)����
 * Ŀ�������ڿ���ǰҪ��֤���ڲ�Ԫ�����Ǻ��� [��ЧԪ��] �ģ���������ʧ��
 * 
*/
void foo_copy(void) {
  vector<int> __v_src;
  for (size_t i = 0; i < 5; ++i) {
    __v_src.push_back(i);
  }

  vector<int> __v_des;
  for (size_t i = 5; i < 10; ++i) {
    __v_des.push_back(i);
  }
  copy(__v_src.begin(), __v_src.end(), __v_des.begin());

  for_each(__v_des.begin(), __v_des.end(), [](int &_val) { cout << _val << endl; });
}

/** replace
 * 
 * void replace(iterator start, iterator end, const T &_old_val, const T &_new_val)
 * 
 * ����������ָ����Χ(������ start �� end ���ֵķ�Χ)��ֵΪ _old_val ��Ԫ�أ����޸���ֵΪ _new_val
 * 
*/
void foo_replace(void) {
  vector<int> __v;
  __v.push_back(1);
  __v.push_back(2);
  __v.push_back(2);
  __v.push_back(3);
  __v.push_back(4);

  replace(__v.begin(), __v.end(), 2, 0x400);

  for_each(__v.begin(), __v.end(), [](int &_val) { cout << _val << endl; });
}

/** replace_if
 * 
 * void replace_if(iterator start, iterator end, function _fn, const T &_new_val)
 * 
 * ��������ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ�أ���������Ϊʵ�������������ָ���� ����ֵΪ bool ���ͣ��β�����Ϊ�����е�Ԫ�ص�ֵ�����͵�һԪ�º������ߺ���ָ�� _fn ���в����ã����� _fn ���� true ʱ����ǰ��������Ԫ�ص�ֵ�滻Ϊ _new_val
 * 
*/
bool m_replace(int &_old_val) {
  return _old_val > 2;
}
void foo_replace_if(void) {
  vector<int> __v;
  for (size_t i = 0; i < 5; ++i) {
    __v.push_back(i);
  }

  replace_if(__v.begin(), __v.end(), m_replace, 0x400);

  copy(__v.begin(), __v.end(), ostream_iterator<int>(cout, "\t"));
}


/** swap
 * 
 * void swap(Container c_src, Container c_des)
 * 
 * ������������(��ͬ��������)���ڲ����ڹܿ����ݿռ��ָ����ָ��ĵ�ַ
*/
void foo_swap(void) {
  vector<int> __v_1;
  for (size_t i = 0; i < 5; ++i) {
    __v_1.push_back(i);
  }

  vector<int> __v_2;
  for (size_t i = 5; i < 10; ++i) {
    __v_2.push_back(i);
  }

  swap(__v_1, __v_2);

  copy(__v_2.begin(), __v_2.end(), ostream_iterator<int>(cout, " "));
}

int main(void) {
  /* foo_copy(); */
  /* foo_replace(); */
  /* foo_replace_if(); */
  /* foo_swap(); */
  system("pause");
  return EXIT_SUCCESS;
}