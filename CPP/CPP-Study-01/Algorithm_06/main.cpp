#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
#include <functional>

/** set_intersection
 * 
 * iterator set_intersection(iterator src_start_1, iterator src_end_1, iterator src_start_2, iterator src_end_2, iterator des_start)
 * 
 * ���㷨�ṩ���Ҳ����Ĺ���
 * ����ָ����Χ��(���������Ŀ�ʼ����ʼ������ src_start_1��src_end_1��src_start_2��src_end_2) ������������Ԫ����Ԫ�ص�ֵ��ͬ��Ԫ�أ����������¸�ֵ��Ŀ������(������ des_start ��ָ�������)���У����᷵��Ŀ�������� ����������(end())
 * �Ҿ���Ҫ��֤ԭʼ����������������Դ���������У�����Ŀ����������ȡ���Ľ�������ܻ��������
 * Ŀ�������ڸ�ֵǰҪ��֤���ڲ�Ԫ�����Ǻ��� [��ЧԪ��] �ģ���������ʧ��
 * 
*/
void foo_set_intersection(void) {
  vector<int> __v_src_1;
  vector<int> __v_src_2;
  for (size_t i = 0; i < 10; ++i) {
    __v_src_1.push_back(i);
    __v_src_2.push_back(i + 5);
  }

  vector<int> __v_des;
  __v_des.resize(__v_src_1.size(), __v_src_2.size());

  vector<int>::iterator i_end = set_intersection(__v_src_1.begin(), __v_src_1.end(), __v_src_2.begin(), __v_src_2.end(), __v_des.begin());

  for_each(__v_des.begin(), i_end, [](int val) { cout << val << " "; });
  cout << endl;
}

/** set_union
 * 
 * iterator set_union(iterator src_start_1, iterator src_end_1, iterator src_start_2, iterator src_end_2, iterator des_start)
 * 
 * ���㷨�ṩ���ҽ����Ĺ���
 * ȥ������ָ����Χ��(���������Ŀ�ʼ����ʼ������ src_start_1��src_end_1��src_start_2��src_end_2) �����������У�ֵ�ظ���Ԫ�ز����кϲ������Ѻϲ���Ľ�����¸�ֵ��Ŀ������(������ des_start ��ָ�������)���У����᷵��Ŀ�������� ����������(end())
 * �Ҿ���Ҫ��֤ԭʼ����������������Դ���������У�����Ŀ����������ȡ���Ľ�������ܻ��������
 * Ŀ�������ںϲ�ǰҪ��֤���ڲ�Ԫ�����Ǻ��� [��ЧԪ��] �ģ���������ʧ��
 * 
*/
void foo_set_union(void) {
  vector<int> __v_src_1;
  vector<int> __v_src_2;
  for (int i = 0; i < 10; i++) {
    __v_src_1.push_back(i);
    __v_src_2.push_back(i + 5);
  }

  vector<int> __v_des;
  __v_des.resize(__v_src_1.size() + __v_src_2.size());

  vector<int>::iterator i_end = set_union(__v_src_1.begin(), __v_src_1.end(), __v_src_2.begin(), __v_src_2.end(), __v_des.begin());

  for_each(__v_des.begin(), i_end, [](int _val) { cout << _val << " "; });
  cout << endl;
}

/** set_difference
 * 
 * iterator set_difference(iterator src_start_1, iterator src_end_1, iterator src_start_2, iterator src_end_2, iterator des_start)
 * 
 * ��������ָ����Χ(������ src_start_1 �� src_end_1 ���ֵķ�Χ)�� [�����] ����ָ����Χ(������ src_start_2 �� src_end_2 ���ֵķ�Χ)�ڣ�Ԫ�ص�ֵ��ͬ��Ԫ�أ����ѽ�����¸�ֵ��Ŀ������(������ des_start ��ָ�������)���У����᷵��Ŀ�������� ����������(end())
 * �Ҿ���Ҫ��֤ԭʼ����������������Դ���������У�����Ŀ����������ȡ���Ľ�������ܻ��������
 * Ŀ�������ڸ�ֵǰҪ��֤���ڲ�Ԫ�����Ǻ��� [��ЧԪ��] �ģ���������ʧ��
*/
void foo_set_difference(void) {
  vector<int> __v_src_1;
  vector<int> __v_src_2;

  for (int i = 0; i < 10; i++) {
    __v_src_1.push_back(i);
    __v_src_2.push_back(i + 5);
  }

  vector<int> __v_des;
  __v_des.resize(max(__v_src_1.size(), __v_src_2.size()));

  vector<int>::iterator i_end = set_difference(__v_src_1.begin(), __v_src_1.end(), __v_src_2.begin(), __v_src_2.end(), __v_des.begin());

  /* vector<int>::iterator i_end = set_difference(__v_src_2.begin(), __v_src_2.end(), __v_src_1.begin(), __v_src_1.end(), __v_des.begin()); */

  for_each(__v_des.begin(), i_end, [](int &_val) { cout << _val << " "; });
  cout << endl;
}

int main(void) {
  /* foo_set_intersection(); */
  /* foo_set_union(); */
  /* foo_set_difference(); */

  system("pause");
  return EXIT_SUCCESS;
}