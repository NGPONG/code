#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

/** find
 * 
 * iterator_pos find(iterator start, iterator end, T _val)
 * 
 * ����ָ�������ĵ����� start �� ������ end �������ڲ��в���ֵΪ _val ��Ԫ�ز����ص�һ���ҵ���Ԫ�������±�� [Ŀ���������͵ĵ�����]���������ڣ��򷵻�ָ�����һ��Ԫ�صĺ�һ��λ�õĵ�����
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
 * ����ָ�������ĵ����� start �� ������ end ȥ���������е�Ԫ�أ���������Ϊʵ�������������ָ���� ����ֵΪ bool ���͵Ķ�Ԫ�º������ߺ���ָ�� _fn ���У��� _fn �����صĽ��Ϊ true ʱ����ú������ص�ǰԪ�������±��  ���᷵����ָ���� һԪ�º������ߺ���ָ��
*/
void foo_find_if(void) {
  
}

int main(void) {
  /* foo_find(); */

  system("pause");
  return EXIT_SUCCESS;
}