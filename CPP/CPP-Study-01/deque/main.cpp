#include <iostream>
using namespace std;

#include <deque>
#include <vector>

/** CONSTRUCTOR
 * deque<T>()                      Ĭ�Ϲ��죬����һ���յ� deque ����
 * deque<T>(V _begin, V _end)      �ù��캯����һ��������������Ϊ V ��ģ�庯����V �ľ��廯���ڽ����ܹ�ָʾһ���������� [begin, end) ��������ĵ�����(������������)����ߵ�ַ����ʹ��������ɵ�ǰ deque �����ڲ���ά���Ķ�̬����ĳ�ʼ������
 * deque<T>(int n, T _element)     �ù��캯��ʹ�� n �� _element ���� deque �����ڲ���̬����ĳ�ʼ�����칤��
 * deque(const vector &_vec)       �������캯���������� deque ����ʵ���ڲ���ά���Ķ�̬�����е�Ԫ�ؿ�������ǰ deque ����ʵ���ڲ���ά���Ķ�̬������
*/
void fun_constructor(void) {
  /* deque<T>() */
  deque<int> dq_empty;

  /* deque<T>(V _begin, V _end) */
  deque<int> dq_01(dq_empty.begin(), dq_empty.end());
  int nums[5] = { 1, 2, 3, 4, 5 };
  deque<int> dq_02(nums, nums + (sizeof(nums) / sizeof(int)));

  /* deque<T>(int n, T _element) */
  deque<int> dq_03(10, 23);

  /* deque(const vector &_vec) */
  deque<int> dq_04(dq_02);
}

/** ASSIGNMENT
 * void assign(V _begin, V _end)               �ú�����һ��������������Ϊ V ��ģ�庯����V �ľ��廯���ڽ����ܹ�ָʾһ���������� [begin, end) ��������ĵ�����(������������)����ߵ�ַ����ʹ��������ɵ�ǰ deque ����ʵ���ڲ���ά���Ķ�̬��������¸�ֵ�Ĺ���
 * void assign(int n, _element)                �ú���ʹ�� n �� _element ���� deque �����ڲ���ά���Ķ�̬��������¸�ֵ�Ĺ���
 * deque &operator=(const deque &_deq)         ������ֵ��������������� deque ��ʵ���ڲ���ά���Ķ�̬�����е�Ԫ��ȥ���¹��쵱ǰ deque ����ʵ�������ڲ���ά���Ķ�̬����
 * void swap(deque &_deq)                      ����Ŀ�� deque �����뵱ǰ deque �����ڲ�ָ�������ڹܿطֶ�ʽ�ڴ�������п�����ָ�룬�����¸���˫�������ڲ���ά���Ķ�̬����� size
*/
void fun_assignment(void) {
  int nums_src[5] = { 1, 2, 3, 4, 5 };
  deque<int> dq_src;

  /* void assign(V _begin, V _end) */
  dq_src.assign(nums_src, nums_src + (sizeof(nums_src) / sizeof(int)));

  /* void assign(int n, _element) */
  dq_src.assign(10, 1024);

  deque<int> dq_des;

  /* deque &operator=(const deque &_deq) */
  dq_des = dq_src;

  /* void swap(vector &_vec) */
  dq_des.swap(dq_src);
}

/** SIZE
 * size_t size()                    ���� deque �����ڲ���̬�����Ԫ�ظ���
 * bool empty()                     �ж��Ƿ���һ�������������κ���ЧԪ�ص�¼�룩
 * void resize(int n)               ����ָ�� deque �����ڲ���ά���Ķ�̬����ĳ���Ϊ n����� n �ϵ���ǰ�ĳ��ȴ�����Ĭ��ֵ��䳬����λ�ã���� n �ϵ���ǰ�ĳ���С����ĩβ�������鳤�ȵ�Ԫ�ر�ɾ��
 * void resize(int n, T _element)   ����ָ�� deque �����ڲ���̬����ĳ���Ϊ n����� n �ϵ���ǰ�ĳ��ȴ����Կ�����ָ���� _element ȥ��䳬����λ�ã���� n �ϵ���ǰ�ĳ���С����ĩβ�������鳤�ȵ�Ԫ�ر�ɾ��
*/
void fun_size(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  deque<int> _dq(nums, nums + (sizeof(nums) / sizeof(int)));

  /* size_t size() */
  size_t _dq_size = _dq.size();

  /* bool empty() */
  bool is_empty = _dq.empty();

  /* void resize(int n) */
  _dq.resize(10);

  /* void resize(int n, T _element) */
  _dq.resize(7, 0x400);
}

/** GET
 * T &at(int _idx)     ���� deque �����ڲ���ά���Ķ�̬������±�Ϊ _idx ��Ԫ�ص����ã���� _idx �����ڲ��������ЧԪ�ظ��������׳�out_of_range�쳣
 * T &operator[_idx]   ���� deque �����ڲ���ά���Ķ�̬������±�Ϊ _idx ��Ԫ�ص����ã���� _idx �����ڲ��������ЧԪ�ظ�������������
 * T &front()          ���� deque �����ڲ���ά���Ķ�̬�������Ԫ�ص�����
 * T &back()           ���� deque �����ڲ���ά���Ķ�̬�����βԪ�ص�����
*/
void fun_get(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  deque<int> _dq(nums, nums + (sizeof(nums) / sizeof(int)));

  int &num_01 = _dq.at(0);
  int &num_02 = _dq[1];
  int &num_03 = _dq.front();
  int &num_04 = _dq.back();
}

/** INSERT
 * void insert(const_iterator pos,T _element)    ���ݵ����� pos ��ָ���Ԫ�ص��±��� deque �����ڲ���ά���Ķ�̬�����в���һ��Ԫ�� _elemenet����������� pos ��ָ���Ԫ���±곬���˶�̬�������ʵ��������������
 * void push_back(T _element)                    �� deque �����ڲ��Ķ�̬�����β������Ԫ�� _element
 * void push_front(T _element)                   �� deque �����ڲ��Ķ�̬������ײ�����Ԫ�� _element
*/
void fun_insert(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  deque<int> _dq(nums, nums + (sizeof(nums) / sizeof(int)));

  /* void insert(const_iterator pos,T _element) */
  _dq.insert(_dq.begin() + 2, 0x400);

  /* void push_back(T _element) */
  _dq.push_back(0x200);

  /* void push_front(T _element) */
  _dq.push_front(0x100);
}

/** DELETE
 * void pop_back()                                        ɾ�� deque �����ڲ��Ķ�̬�����е�βԪ��
 * void pop_front()                                       ɾ�� deque �����ڲ��Ķ�̬�����е���Ԫ��
 * void erase(const_iterator start, const_iterator end)   deque �����ڲ���ά���Ķ�̬������ɾ�������� start �� ������ end ��ָ����±�֮������е�Ԫ��
 * void erase(const_iterator pos)                         deque �����ڲ���ά���Ķ�̬������ɾ�������� pos ��ָ���Ԫ��
 * void clear()                                           ɾ�� deque �����ڲ��Ķ�̬�����е����е�Ԫ��
*/
void fun_delete(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  deque<int> _dq(nums, nums + (sizeof(nums) / sizeof(int)));

  /* void pop_back() */
  _dq.pop_back();

  /* void pop_front() */
  _dq.pop_front();

  /* void erase(const_iterator start, const_iterator end) */
  _dq.erase(_dq.begin(), _dq.begin() + 2);

  /* void erase(const_iterator pos) */
  _dq.erase(_dq.begin() + 1);

  /* void clear() */
  _dq.clear();
}

int main(void) {

  system("pause");
  return EXIT_SUCCESS;
}