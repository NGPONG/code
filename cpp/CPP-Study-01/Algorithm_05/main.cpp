#include <iostream>
using namespace std;

#include <vector>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <functional>

/** accumulate
 * 
 * T accumulate(iterator start, iterator end, const T &_init_val)
 * 
 * �� _init_val ��Ϊ��ʼ�����ݣ��ڴ˻������ۼ�����ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ�ص�ֵ����󷵻��ۼӺ�Ľ��
*/
void foo_accumulate(void) {
  vector<int> __v;
  for (size_t i = 0; i < 5; ++i) {
    __v.push_back(i);
  }

  int num = accumulate(__v.begin(), __v.end(), 100);
  cout << num << endl;
}

/** fill
 * 
 * void fill(iterator start, iterator end, const T &_val)
 * 
 * ����ָ����Χ(������ start �� end ���ֵķ�Χ)�ڵ�Ԫ�ص�ֵ�滻Ϊ _val
*/
void foo_fill(void) {
  vector<int> __v;
  for (size_t i = 0; i < 5; ++i) {
    __v.push_back(i);
  }

  fill(__v.begin(), __v.begin() + 2, 0x400);
}

int main(void) {
  /* foo_accumulate(); */
  foo_fill();

  system("pause");
  return EXIT_SUCCESS;
} 