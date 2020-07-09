#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
#include <functional>

/** merge
 * 
 * void merge(iterator src_start_1, iterator src_end_1, iterator src_start_2, iterator src_end_2, iterator des_start)
 * 
 * �ϲ�ָ����Χ��(���������Ŀ�ʼ����ʼ������ src_start_1��src_end_1��src_start_2��src_end_2) ������������Ԫ�أ������¸�ֵ��Ŀ������(������ des_start ��ָ�������)����
 * �Ҿ���Ҫ��֤ԭʼ�ϲ�����������Դ���������У�����ϲ���Ľ�������ܻ�������֮ǰ������
 * Ŀ�������ںϲ�ǰҪ��֤���ڲ�Ԫ�����Ǻ��� [��ЧԪ��] �ģ���������ʧ��
 * 
*/
void foo_merge(void) {
  vector<int> __v_src_1;
  __v_src_1.push_back(1);
  __v_src_1.push_back(2);
  __v_src_1.push_back(3);
  __v_src_1.push_back(4);
  __v_src_1.push_back(5);

  vector<int> __v_src_2;
  __v_src_2.push_back(6);
  __v_src_2.push_back(7);

  vector<int> __v_des;
  __v_des.resize(__v_src_1.size() + __v_src_2.size());
  merge(__v_src_1.begin(), __v_src_1.end(), __v_src_2.begin(), __v_src_2.end(), __v_des.begin());
}

/** sort
 * 
 * void sort(iterator start, iterator end, function _fn)
 * 
 * ��������ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ�����շ���ֵΪ bool ���ͣ��β�����Ϊ�����е�Ԫ�ص�ֵ�����͵Ķ�Ԫ�º�������ָ�� ȥ��������
 *  
*/
void foo_sort(void) {
  vector<int> __v;
  __v.push_back(4);
  __v.push_back(1);
  __v.push_back(5);
  __v.push_back(2);
  __v.push_back(3);

  sort(__v.begin(), __v.end(), [](int &_left, int &_right) { return _left > _right; });
}

/** random_shuffle
 * 
 * void random_shuffle(iterator start, iterator end)
 * 
 * �����������ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ�ص�ԭʼ����
 * 
*/
void foo_random_shuffle(void) {
  vector<int> __v;
  for (size_t i = 0; i < 5; ++i) {
    __v.push_back(i);
  }

  random_shuffle(__v.begin(), __v.end());

  for_each(__v.begin(), __v.end(), [](int &_val) { cout << _val << endl; });
}

/** reverse
 * 
 * void reverse(iterator start, iterator end)
 * 
 * ��ת������ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ�صĴ���
 * 
*/
void foo_reverse(void) {
  vector<int> __v;
  for (size_t i = 0; i < 5; ++i) {
    __v.push_back(i);
  }

  reverse(__v.begin(), __v.end());\
}

int main(void) {
  /* foo_merge(); */
  /* foo_sort(); */
  /* foo_random_shuffle(); */
  foo_reverse();

  system("pause");
  return EXIT_SUCCESS;
}