#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

/** for_each
 * _Function for_each(_InputIterator start, _InputIterator end, _Function _fn)
 * 
 * ��������ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ�أ���������Ϊʵ�������������ָ���� һԪ�º������ߺ���ָ�� ���У����᷵����ָ���� һԪ�º������ߺ���ָ��
*/
void printer_for_each(const int &_val) {
  cout << _val << endl;
}
void foo_for_each(void) {
  vector<int> __v;
  for (size_t i = 0; i < 10; ++i) {
    __v.push_back(i + 1);
  }

  void (*invoker)(const int &) = for_each(__v.begin(), __v.end(), printer_for_each);
}

/** transform
 * void transform(_InputIterator start, _InputIterator end, _OutputIterator start_des, _UnaryOperation unary_op)
 * 
 * ��������ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ�أ���������Ϊʵ�������������ָ���� ����ֵ���β�����Ϊ�����е�Ԫ�����͵�һԪ�º������ߺ���ָ�� unary_op ���У����������ķ��ؽ�� [���¸�ֵ] �������� start_des ��ָ���Ŀ��������
 * �ú����ĵ��ñ���Ҫ��֤Ŀ������� __result ��ָ����������Ǻ��� [��ЧԪ��] �ģ���������ʧ��
*/
int f_transform(int &_val) {
  return _val + 1;
}
void foo_transform(void) {
  vector<int> __v_src;
  for (size_t i = 0; i < 10; ++i) {
    __v_src.push_back(i + 1);
  }

  vector<int> __v_des;
  __v_des.resize(__v_src.size());
  transform(__v_src.begin(), __v_src.end(), __v_des.begin(), f_transform);
}

int main(void) {
  /* foo_for_each(); */
  foo_transform();

  system("pause");
  return EXIT_SUCCESS;
}