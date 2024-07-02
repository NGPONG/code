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
 * vector<T>()                  默认构造，构建一个空的 vector 容器
 * vector<T>(V _begin, V _end)  该构造函数是一个存在虚拟类型为 V 的模板函数，V 的具体化用于接收能够指示一段线性数组 [begin, end) 开闭区间的迭代器(隶属于容器的)亦或者地址，并使用它来完成当前 vector 容器内部所管控的动态数组的初始化工作
 * vector<T>(n, T _element)     该构造函数使用 n 个 _element 用于 vector 容器内部动态数组的初始化构造工作
 * vector(const vector &_vec)   拷贝构造函数，将已有 vector 容器实例内部所管控的动态数组中的 [有效元素] 拷贝至当前 vector 容器实例内部所管控的动态数组中
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
 * void assign(V _begin, V _end)               该函数是一个存在虚拟类型为 V 的模板函数，V 的具体化用于接收能够指示一段线性数组 [begin, end) 开闭区间的迭代器(隶属于容器的)亦或者地址，并使用它来完成当前 vector 容器实例内部所管控的动态数组的重新赋值的工作
 * void assign(n, _element)                    该函数使用 n 个 _element 用于 vector 容器内部动态数组的重新赋值的工作
 * vector &operator=(const vector &_vec)       拷贝赋值运算符，依据已有 vector 的实例内部所管控的动态数组中的 [有效元素] 去重新构造当前 vector 容器实例本身内部所管控的动态数组
 * void swap(vector &_vec)                     交换目标 vector 容器与当前 vector 容器内部用于管控指向堆中线性空间的指针所指向的地址，并重新更新双方容器内部所管控的动态数组的 size 和 capacity
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
 * 正序遍历
 * vector<int>::iterator begin()            获取 vector 容器的正序起始迭代器，正序起始迭代器所指向的是 vector 内部所管控的动态数组中的首元素的位置
 * vector<int>::iterator end()              获取 vector 容器的正序结束迭代器，正序结束迭代器所指向的是 vector 内部所管控的动态数组中的最后一个元素的下一个位置
 * 
 *     +---+---+---+---+---+
 *     | 1 | 2 | 3 | 4 | 5 |
 *     +-+-+---+---+---+---+
 *       ^                    ^
 *       |                    |
 *     begin                 end
 * 
 * 
 * 逆序遍历
 * vector<int>::reverse_iterator rbegin()   获取 vector 容器的逆序起始迭代器，逆序起始迭代器所指向的是 vector 内部所管控的动态数组中的最后一个元素的位置
 * vector<int>::reverse_iterator rend()     获取 vector 容器的逆序结束迭代器，逆序结束迭代器所指向的是 vector 内部所管控的动态数组中的首元素的上一个位置
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
 * size_t size()                    返回 vector 容器内部动态数组的有效元素个数
 * bool empty()                     判断是否是一个空容器（无任何有效元素的录入）
 * size_t capacity()                获取 vector 容器内部动态数组的真实容量
 * void resize(int n)               重新指定 vector 容器内部动态数组的长度为 n，如果 n 较调用前的长度大，则以默认值填充超出的位置，如果 n 较调用前的长度小，则末尾超出数组长度的元素被删除（所删除的仅仅只是真实的元素，并无法缩减内部动态数组的真实容量）
 * void resize(int n, T _element)   重新指定 vector 容器内部动态数组的长度为 n，如果 n 较调用前的长度大，则以拷贝所指定的 _element 去填充超出的位置，如果 n 较调用前的长度小，则末尾超出数组长度的元素被删除（所删除的仅仅只是真实的元素，并无法缩减内部动态数组的真实容量）
 * void reserve(int len)            调整 vector 容器内部动态数组的真实容量至 len，所新增出来的预留位置并未进行过初始化，即不可被访问，也不可执行随机插入操作（仅仅允许插入有效元素至当前动态数组尾元素的下一个元素的位置），简而言之，它们都不是 [有效元素]，当 len 所指定的长度要小于当前 vector 容器内部动态数组的真实容量时，则该函数调用无任何结果
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
 * T &at(int _idx)     返回 vector 容器内部动态数组的下标为 _idx 的元素的引用，如果 _idx 超出内部数组的有效元素个数，则抛出out_of_range异常
 * T &operator[_idx]   返回 vector 容器内部动态数组的下标为 _idx 的元素的引用，如果 _idx 超出内部数组的有效元素个数，则程序崩溃
 * T &front()          返回 vector 容器内部动态数组的首元素的引用
 * T &back()           返回 vector 容器内部动态数组的尾元素的引用
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
 * void insert(const_iterator pos,T _element)    根据迭代器 pos 所指向的元素的下标往 vector 容器内部的动态数组插入一个元素 _elemenet，如果迭代器 pos 所指向的元素下标超出了动态数组的真实容量，则程序崩溃
 * void push_back(T _element)                    往 vector 容器内部的动态数组的即为插入元素 _element
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
 * void pop_back()                                        删除 vector 容器内部的动态数组中的尾元素
 * void erase(const_iterator start, const_iterator end)   vector 容器内部的动态数组中删除迭代器 start 和 迭代器 end 所指向的下标之间的所有的 [真实元素]
 * void erase(const_iterator pos)                         vector 容器内部的动态数组中删除迭代器 pos 所指向的元素
 * void clear()                                           删除 vector 容器内部的动态数组中的所有的 [真实元素]
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
   * resize 函数仅仅只能够缩减 vector 内部动态数组中的真实元素的长度，
   * 但是动态数组的真实容量却并不会缩减，简而言之，我们虽然把它的真实元素的长度缩减至 5 个，
   * 但是动态数组其真实容量还是在进行了 100000 新增操作后的容量，这里就会造成内存空间浪费的问题
  */
  _ve.resize(10);
  cout << _ve.capacity() << endl;

  /** 
   * 通过匿名对象调用 vector 容器的拷贝构造函数，把已有 vector 实例 _ve 内部的动态数组的真实元素（5个）拷贝至
   * 匿名对象内部所构造的动态数组中，由于仅仅指示拷贝的原始动态数组中的 真实元素，故该匿名对象 vector 内部所管控的动态数组的
   * 长度也仅仅是以元素动态数组的真实元素的个数为单位，这时候我们在通过 swap() 函数来交换匿名对象内部所管控的动态数组和元素动态数组之间
   * 在内存堆中的地址，以让原始 vector 内部指向的数组为 匿名对象 所构造出来的动态数组，并且被交换后的、长度更长的动态数组由于匿名对象在调用完毕后
   * 就会进行销毁，故其也进行了销毁，以此来完成了 静态缩减 容量的目的
  */
  vector<int>(_ve).swap(_ve);
  cout << _ve.capacity() << endl;
}

void fun_test_02(void) {
  /* 记录两次不同的处理方式，vector 内部的动态数组的扩容次数 */

  int num_01 = 0;
  vector<int> _ve_01;
  int *p_temp_01 = nullptr;
  for (size_t i = 0; i < 1000000; ++i) {
    _ve_01.push_back(i);

    /**
     * 每一次 vector 内部所管控的动态数组的扩容都会使用一块新的内存地址，
     * 故通过此机制来判断下一次插入数据后的元素首地址是否等于上一次元素的首地址来判断
     * 当前插入操作是否引起了动态数组的扩容操作
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
  _ve_02.reserve(1000000); /* 在可控范围内，预先调整 vector 内部动态数组的长度 */
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