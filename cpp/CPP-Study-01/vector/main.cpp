#include <iostream>
using namespace std;

#include <vector>

template<typename T>
void print(vector<T> &_ve) {
  for (vector<int>::iterator it = _ve.begin(); it != _ve.end(); ++it) {
    cout << *it << endl;
  }
}

template<typename T>
void get_size(vector<T> &_ve) {
  cout << "size = " << _ve.size() << " capacity = " << _ve.capacity() << endl;
}

/** CONSTRUCTOR
 * vector<T>()                  Ĭ�Ϲ��죬����һ���յ� vector ����
 * vector<T>(V _begin, V _end)  �ù��캯����һ��������������Ϊ V ��ģ�庯����V �ľ��廯���ڽ����ܹ�ָʾһ���������� [begin, end) ��������ĵ�����(������������)����ߵ�ַ����ʹ��������ɵ�ǰ vector �����ڲ����ܿصĶ�̬����ĳ�ʼ������
 * vector<T>(n, T _element)     �ù��캯��ʹ�� n �� _element ���� vector �����ڲ���̬����ĳ�ʼ�����칤��
 * vector(const vector &_vec)   �������캯���������� vector ����ʵ���ڲ����ܿصĶ�̬�����е� [��ЧԪ��] ��������ǰ vector ����ʵ���ڲ����ܿصĶ�̬������
*/
void fun_constructor(void) {
  /* vector<T>() */
  vector<int> ve_empty;

  /* vector<T>(V begin, V end) */
  vector<int> ve_01(ve_empty.begin(), ve_empty.end());
  int nums[5] = { 1, 2, 3, 4, 5 };
  vector<int> ve_02(nums, nums + (sizeof(nums) / sizeof(int)));

  /* vector<T>(n, T _element) */
  vector<int> ve_03(10, 23);

  /* vector(const vector &_vec) */
  vector<int> ve_04(ve_02);
}

/** ASSIGNMENT
 * void assign(V _begin, V _end)               �ú�����һ��������������Ϊ V ��ģ�庯����V �ľ��廯���ڽ����ܹ�ָʾһ���������� [begin, end) ��������ĵ�����(������������)����ߵ�ַ����ʹ��������ɵ�ǰ vector ����ʵ���ڲ����ܿصĶ�̬��������¸�ֵ�Ĺ���
 * void assign(n, _element)                    �ú���ʹ�� n �� _element ���� vector �����ڲ���̬��������¸�ֵ�Ĺ���
 * vector &operator=(const vector &_vec)       ������ֵ��������������� vector ��ʵ���ڲ����ܿصĶ�̬�����е� [��ЧԪ��] ȥ���¹��쵱ǰ vector ����ʵ�������ڲ����ܿصĶ�̬����
 * void swap(vector &_vec)                     ����Ŀ�� vector �����뵱ǰ vector �����ڲ����ڹܿ�ָ��������Կռ��ָ����ָ��ĵ�ַ�������¸���˫�������ڲ����ܿصĶ�̬����� size �� capacity
*/
void fun_assignment(void) {
  int nums_src[5] = { 1, 2, 3, 4, 5 };
  vector<int> ve_src;

  /* void assign(V _begin, V _end) */
  ve_src.assign(nums_src, nums_src + (sizeof(nums_src) / sizeof(int)));

  /* void assign(n, _element) */
  ve_src.assign(10, 1024);

  vector<int> ve_des;

  /* vector& operator=(const vector &_vec) */
  ve_des = ve_src;

  /* void swap(vector &_vec) */
  ve_des.swap(ve_src);
}

/** ITERATOR
 * �������
 * vector<int>::iterator begin()            ��ȡ vector ������������ʼ��������������ʼ��������ָ����� vector �ڲ����ܿصĶ�̬�����е���Ԫ�ص�λ��
 * vector<int>::iterator end()              ��ȡ vector ������������������������������������ָ����� vector �ڲ����ܿصĶ�̬�����е����һ��Ԫ�ص���һ��λ��
 * 
 *     +---+---+---+---+---+
 *     | 1 | 2 | 3 | 4 | 5 |
 *     +-+-+---+---+---+---+
 *       ^                    ^
 *       |                    |
 *     begin                 end
 * 
 * 
 * �������
 * vector<int>::reverse_iterator rbegin()   ��ȡ vector ������������ʼ��������������ʼ��������ָ����� vector �ڲ����ܿصĶ�̬�����е����һ��Ԫ�ص�λ��
 * vector<int>::reverse_iterator rend()     ��ȡ vector ������������������������������������ָ����� vector �ڲ����ܿصĶ�̬�����е���Ԫ�ص���һ��λ��
 * 
 *     +---+---+---+---+---+
 *     | 1 | 2 | 3 | 4 | 5 |
 *     +---+---+---+---+-+-+
 *   ^                   ^
 *   |                   |
 * rend                rbegin
 * 
*/
void fun_iterator(void) {
  /* vector<int> _ve;

  vector<int>::iterator _it_begin = _ve.begin();
  vector<int>::iterator _it_end = _ve.end();

  vector<int>::reverse_iterator _rt_begin = _ve.rbegin();
  vector<int>::reverse_iterator _rt_end = _ve.rend(); */
}

/** SIZE
 * size_t size()                    ���� vector �����ڲ���̬�������ЧԪ�ظ���
 * bool empty()                     �ж��Ƿ���һ�������������κ���ЧԪ�ص�¼�룩
 * size_t capacity()                ��ȡ vector �����ڲ���̬�������ʵ����
 * void resize(int n)               ����ָ�� vector �����ڲ���̬����ĳ���Ϊ n����� n �ϵ���ǰ�ĳ��ȴ�����Ĭ��ֵ��䳬����λ�ã���� n �ϵ���ǰ�ĳ���С����ĩβ�������鳤�ȵ�Ԫ�ر�ɾ������ɾ���Ľ���ֻ����ʵ��Ԫ�أ����޷������ڲ���̬�������ʵ������
 * void resize(int n, T _element)   ����ָ�� vector �����ڲ���̬����ĳ���Ϊ n����� n �ϵ���ǰ�ĳ��ȴ����Կ�����ָ���� _element ȥ��䳬����λ�ã���� n �ϵ���ǰ�ĳ���С����ĩβ�������鳤�ȵ�Ԫ�ر�ɾ������ɾ���Ľ���ֻ����ʵ��Ԫ�أ����޷������ڲ���̬�������ʵ������
 * void reserve(int len)            ���� vector �����ڲ���̬�������ʵ������ len��������������Ԥ��λ�ò�δ���й���ʼ���������ɱ����ʣ�Ҳ����ִ���������������������������ЧԪ������ǰ��̬����βԪ�ص���һ��Ԫ�ص�λ�ã��������֮�����Ƕ����� [��ЧԪ��]���� len ��ָ���ĳ���ҪС�ڵ�ǰ vector �����ڲ���̬�������ʵ����ʱ����ú����������κν��
*/
void fun_size(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };

  vector<int> _ve(nums, nums + (sizeof(nums) / sizeof(int)));

  /* size_t size() */
  size_t _ve_size = _ve.size();

  /* size_t capacity() */
  size_t _ve_capacity = _ve.capacity();

  /* bool empty() */
  bool is_empty = _ve.empty();

  /* void resize(int n) */
  _ve.resize(10);

  /* void resize(int n, T _element) */
  _ve.resize(7, 0x400);

  /* void reserve(int len) */
  _ve.reserve(0x400);
}

/** GET
 * T &at(int _idx)     ���� vector �����ڲ���̬������±�Ϊ _idx ��Ԫ�ص����ã���� _idx �����ڲ��������ЧԪ�ظ��������׳�out_of_range�쳣
 * T &operator[_idx]   ���� vector �����ڲ���̬������±�Ϊ _idx ��Ԫ�ص����ã���� _idx �����ڲ��������ЧԪ�ظ�������������
 * T &front()          ���� vector �����ڲ���̬�������Ԫ�ص�����
 * T &back()           ���� vector �����ڲ���̬�����βԪ�ص�����
*/
void fun_get() {
  int nums[5] = { 1, 2, 3, 4, 5 };
  vector<int> _ve(nums, nums + (sizeof(nums) / sizeof(int)));

  int &num_01 = _ve.at(0);
  int &num_02 = _ve[1];
  int &num_03 = _ve.front();
  int &num_04 = _ve.back();
}

/** INSERT
 * void insert(const_iterator pos,T _element)    ���ݵ����� pos ��ָ���Ԫ�ص��±��� vector �����ڲ��Ķ�̬�������һ��Ԫ�� _elemenet����������� pos ��ָ���Ԫ���±곬���˶�̬�������ʵ��������������
 * void push_back(T _element)                    �� vector �����ڲ��Ķ�̬����ļ�Ϊ����Ԫ�� _element
*/
void fun_insert() {
  int nums[5] = { 1, 2, 3, 4, 5 };
  vector<int> _ve(nums, nums + (sizeof(nums) / sizeof(int)));

  /* void insert(const_iterator pos,T _element) */
  _ve.insert(_ve.begin() + 2, 0x400);

  /* void push_back(T _element) */
  _ve.push_back(0x200);
}

/** DELETE
 * void pop_back()                                        ɾ�� vector �����ڲ��Ķ�̬�����е�βԪ��
 * void erase(const_iterator start, const_iterator end)   vector �����ڲ��Ķ�̬������ɾ�������� start �� ������ end ��ָ����±�֮������е� [��ʵԪ��]
 * void erase(const_iterator pos)                         vector �����ڲ��Ķ�̬������ɾ�������� pos ��ָ���Ԫ��
 * void clear()                                           ɾ�� vector �����ڲ��Ķ�̬�����е����е� [��ʵԪ��]
*/
void fun_delete(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  vector<int> _ve(nums, nums + (sizeof(nums) / sizeof(int)));

  /* void pop_back() */
  _ve.pop_back();

  /* void erase(const_iterator start, const_iterator end) */
  _ve.erase(_ve.begin(), _ve.begin() + 2);

  /* void erase(const_iterator pos) */
  _ve.erase(_ve.begin() + 1);

  /* void clear() */
  _ve.clear();
}

void fun_test() {
  vector<int> _ve;
  for (size_t i = 0; i < 100000; ++i) {
    _ve.push_back(i);
  }

  /** 
   * resize ��������ֻ�ܹ����� vector �ڲ���̬�����е���ʵԪ�صĳ��ȣ�
   * ���Ƕ�̬�������ʵ����ȴ�����������������֮��������Ȼ��������ʵԪ�صĳ��������� 5 ����
   * ���Ƕ�̬��������ʵ���������ڽ����� 100000 ���������������������ͻ�����ڴ�ռ��˷ѵ�����
  */
  _ve.resize(10);
  cout << _ve.capacity() << endl;

  /** 
   * ͨ������������� vector �����Ŀ������캯���������� vector ʵ�� _ve �ڲ��Ķ�̬�������ʵԪ�أ�5����������
   * ���������ڲ�������Ķ�̬�����У����ڽ���ָʾ������ԭʼ��̬�����е� ��ʵԪ�أ��ʸ��������� vector �ڲ����ܿصĶ�̬�����
   * ����Ҳ��������Ԫ�ض�̬�������ʵԪ�صĸ���Ϊ��λ����ʱ��������ͨ�� swap() �������������������ڲ����ܿصĶ�̬�����Ԫ�ض�̬����֮��
   * ���ڴ���еĵ�ַ������ԭʼ vector �ڲ�ָ�������Ϊ �������� ����������Ķ�̬���飬���ұ�������ġ����ȸ����Ķ�̬�����������������ڵ�����Ϻ�
   * �ͻ�������٣�����Ҳ���������٣��Դ�������� ��̬���� ������Ŀ��
  */
  vector<int>(_ve).swap(_ve);
  cout << _ve.capacity() << endl;
}

void fun_test_02(void) {
  /* ��¼���β�ͬ�Ĵ���ʽ��vector �ڲ��Ķ�̬��������ݴ��� */

  int num_01 = 0;
  vector<int> _ve_01;
  int *p_temp_01 = nullptr;
  for (size_t i = 0; i < 1000000; ++i) {
    _ve_01.push_back(i);

    /**
     * ÿһ�� vector �ڲ����ܿصĶ�̬��������ݶ���ʹ��һ���µ��ڴ��ַ��
     * ��ͨ���˻������ж���һ�β������ݺ��Ԫ���׵�ַ�Ƿ������һ��Ԫ�ص��׵�ַ���ж�
     * ��ǰ��������Ƿ������˶�̬��������ݲ���
    */
    if (p_temp_01 != &_ve_01.at(0)) {
      p_temp_01 = &_ve_01.at(0);
      ++num_01;
    }
  }
  cout << num_01 << endl;

  int num_02 = 0;
  vector<int> _ve_02;
  int *p_temp_02 = nullptr;
  _ve_02.reserve(1000000); /* �ڿɿط�Χ�ڣ�Ԥ�ȵ��� vector �ڲ���̬����ĳ��� */
  for (size_t i = 0; i < 1000000; ++i) {
    _ve_02.push_back(i);
    if (p_temp_02 != &_ve_02.at(0)) {
      p_temp_02 = &_ve_02.at(0);
      ++num_02;
    }
  }
  cout << num_02 << endl;
}

int main(void) {
  /* fun_constructor(); */
  /* fun_assignment(); */
  /* fun_iterator(); */
  /* fun_size(); */
  /* fun_get(); */
  /* fun_insert(); */
  /* fun_delete(); */

  /* fun_test(); */

  fun_test_02();

  system("pause");
  return EXIT_SUCCESS;
}