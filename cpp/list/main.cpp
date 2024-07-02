#include <iostream>
using namespace std;

#include <list>

/** CONSTRUCTOR
 * list<T>()                      Ĭ�Ϲ��죬����һ���յ� list ����
 * list<T>(V _begin, V _end)      �ù��캯����һ��������������Ϊ V ��ģ�庯����V �ľ��廯���ڽ����ܹ�ָʾһ���������� [begin, end) ��������ĵ�����(������������)����ߵ�ַ����ʹ��������ɵ�ǰ list �����ڲ���ά����˫��ѭ������ĳ�ʼ������
 * list(int n, T _element)        �ù��캯��ʹ�� n �� _element ���� list �����ڲ�˫��ѭ������ĳ�ʼ�����칤��
 * list(const list &_li)          �������캯���������� list ����ʵ���ڲ���ά����˫��ѭ�������еĽڵ㿽������ǰ list ����ʵ���ڲ���ά����˫��ѭ��������
*/
void fun_constructor(void) {
  /* list<T>() */
  list<int> li_empty;

  /* list<T>(V _begin, V _end) */
  list<int> li_01(li_empty.begin(), li_empty.end());
  int nums[5] = { 1, 2, 3, 4, 5 };
  list<int> li_02(nums, nums + (sizeof(nums) / sizeof(int)));

  /* deque<T>(int n, T _element) */
  list<int> li_03(10, 23);

  /* deque(const vector &_vec) */
  list<int> li_04(li_02);
}

/** ASSIGNMENT
 * void assign(V _begin, V _end)      �ú�����һ��������������Ϊ V ��ģ�庯����V �ľ��廯���ڽ����ܹ�ָʾһ���������� [begin, end) ��������ĵ�����(������������)����ߵ�ַ����ʹ��������ɵ�ǰ list ����ʵ���ڲ���ά����˫��ѭ����������¸�ֵ�Ĺ���
 * assign(int n, _element)            �ú���ʹ�� n �� _element ���� list �����ڲ���ά����˫��ѭ����������¸�ֵ�Ĺ���
 * list &operator=(const list &_li)   ������ֵ��������������� list ��ʵ���ڲ���ά����˫��ѭ�������еĽڵ�ȥ���¹��쵱ǰ list ����ʵ�������ڲ���ά����˫��ѭ������
 * void swap(list &_li)               ����Ŀ�� list �����뵱ǰ list �����ڲ�ָ���Ŵ����ڶ��е�˫��ѭ�������ָ�룬�����¸���˫�������ڲ���ά����˫��ѭ������� size
*/
void fun_assignment(void) {
  int nums_src[5] = { 1, 2, 3, 4, 5 };
  list<int> li_src;

  /* void assign(V _begin, V _end) */
  li_src.assign(nums_src, nums_src + (sizeof(nums_src) / sizeof(int)));

  /* void assign(int n, _element) */
  li_src.assign(10, 1024);

  list<int> li_des;

  /* list &operator=(const list &_li) */
  li_des = li_src;

  /* void swap(list &_li) */
  li_des.swap(li_src);
}


/** SIZE
 * size_t size()                    ���� list �����ڲ�˫��ѭ������Ľڵ����
 * bool empty()                     �ж��Ƿ���һ�������������κνڵ�����ӣ�
 * void resize(int n)               ����ָ�� list �����ڲ���ά����˫��ѭ������Ľڵ����ӳ���Ϊ n����� n �ϵ���ǰ�ĳ��ȴ�����Ĭ��ֵ��䳬����λ�ã���� n �ϵ���ǰ�ĳ���С����ɾ������������ n �Ľڵ�
 * void resize(int n, T _element)   ����ָ�� list �����ڲ���ά����˫��ѭ������Ľڵ����ӳ���Ϊ n����� n �ϵ���ǰ�ĳ��ȴ��򿽱���ָ���� _element ȥ��䳬����λ�ã���� n �ϵ��õĳ���С����ɾ������������ n �Ľڵ�
*/
void fun_size(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  list<int> _li(nums, nums + (sizeof(nums) / sizeof(int)));

  /* size_t size() */
  size_t _li_size = _li.size();

  /* bool empty() */
  bool is_empty = _li.empty();

  /* void resize(int n) */
  _li.resize(10);

  /* void resize(int n, T _element) */
  _li.resize(7, 0x400);
}

/** INSERT
 * void push_back(T _element)                    �� list �����ڲ���˫��ѭ�������β������������Ϊ _element �Ľڵ�
 * void push_front(T _element)                   �� list �����ڲ���˫��ѭ��������״�����������Ϊ _element �Ľڵ�
 * void insert(const_iterator pos,T _element)    ���ݵ����� pos ��ָ��Ľڵ���±��� list �����ڲ���ά����˫��ѭ�������в���һ��������Ϊ _elemenet �Ľڵ㣬��������� pos ��ָ���Ԫ���±곬����˫��ѭ������ĳ��ȣ���������
*/
void fun_insert(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  list<int> _li(nums, nums + (sizeof(nums) / sizeof(int)));

  /* void insert(const_iterator pos,T _element) */
  _li.insert(++_li.begin(), 0x400);

  /* void push_back(T _element) */
  _li.push_back(0x200);

  /* void push_front(T _element) */
  _li.push_front(0x100);
}

/** DELETE
 * void pop_back()                                                          ɾ�� list �����ڲ���˫��ѭ�������е�β�ڵ�
 * void pop_front()                                                         ɾ�� list �����ڲ���˫��ѭ�������е��׽ڵ�
 * void clear()                                                             ɾ�� list �����ڲ���˫��ѭ�������е����еĽڵ�
 * void erase(list<T>::const_iterator start, list<T>::const_iterator end)   list �����ڲ���ά����˫��ѭ��������ɾ�������� start �� ������ end ��ָ����±�֮������еĽڵ�
 * void erase(list<T>::const_iterator pos)                                  list �����ڲ���ά����˫��ѭ��������ɾ�������� pos ��ָ��Ľڵ�
*/
void fun_delete(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  list<int> _li(nums, nums + (sizeof(nums) / sizeof(int)));

  /* void pop_back() */
  _li.pop_back();

  /* void pop_front() */
  _li.pop_front();

  /* void erase(const_iterator start, const_iterator end) */
  _li.erase(_li.begin(), ++_li.begin());

  /* void erase(const_iterator pos) */
  _li.erase(++_li.begin());

  /* void clear() */
  _li.clear();
}

/** GET
 * T &front()      ���� list �����ڲ���ά����˫��������׽ڵ������������
 * T &back()       ���� list �����ڲ���ά����˫�������β�ڵ������������
*/
void fun_get(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  list<int> _li(nums, nums + (sizeof(nums) / sizeof(int)));
  int &num_03 = _li.front();
  int &num_04 = _li.back();
}

bool __sort(int &num_01, int &num_02) {
  return num_01 < num_02;
}
/** COMMON
 * reverse()          ����ת
 * sort(T __fu)       ������ָ���ķ���ֵΪ bool ��ӵ����������ڵ��������βεĺ������º�����ȥ�������������
*/
void fun_common(void) {
  int nums[5] = { 3, 2, 4, 1, 5 };
  list<int> _li(nums, nums + (sizeof(nums) / sizeof(int)));

  /* sort(T __fu) */
  _li.sort(__sort);

  /* reverse() */
  _li.reverse();
}


int main(void) {
  fun_common();


  system("pause");
  return EXIT_SUCCESS;
}