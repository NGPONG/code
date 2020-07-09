#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

/** �º���������
 * 
 *  binder2nd bind2nd(const _Function &__f_binary, const _Type &__val)
 *  1. ����
 *    1.1 __f_binary����Ҫ��һ����Ԫ�º���(�����صĺ������ò������ĺ�����Ҫ����Ϊ ����������Ϊ���ջ�ͨ��һ�������������÷º���)���Ҽ̳��� binary_function<T1 arg_01, T2 arg_02, R ret>
 *    1.2 __val����Ҫ�� __f_binary ���а󶨵�ֵ
 *  2. ����ֵ��binder2nd ��һ��һԪ�º���������ʵ�ֵ����غ������ò������ĺ����ķ���ֵͬ������ָ���ķº��� __f_binary���β��б����һ����ָ���Ķ�Ԫ�º��� __f_binary �ĵ�һ���βε����͵��β� __val_src �����룬�������ڲ�ʵ�����ֵ�����������¼��ķº��� __f_binary�����ڵ��� __f_binary ʱ�������������������Ƿֱ��� __val_src �� bind2nd ����ʱ��¼���ʵ�� __val
 *  3. ʹ�ó�������ĳЩ API ��Ҫָ��һ��һԪ�º�����������ֻ�ж�Ԫ�º���ʱ������ʹ�� bind2nd �������乤��
*/
class print_m : public binary_function<int, int, void> {
public:
  void operator()(int _val_01, int _val_02) const {
    cout << _val_01 + _val_02 << endl;
  }
};
void foo_functor(void) {
  int nums[5] = { 1, 2, 3, 4, 5 };
  vector<int> __v(nums, nums + (sizeof(nums) / sizeof(int)));

  for_each(__v.begin(), __v.end(), bind2nd(print_m(), 1000));
}

/** ȡ��������
 * 
 * unary_negate not1(const _Function &__f_unary)
 *  1. ������
 *    1.1 __f_unary����Ҫһ������ֵΪ bool ���͵�һԪ�º������Ҽ̳��� unary_function<T1 arg, R ret>
 *  2. ����ֵ��unary_negate ��һ��һԪ�º��������صĺ������ò������ĺ����ķ���ֵ���β��б�ͬ������ָ���ķº��� __f_unary���������ڲ�ʵ���л���÷�����¼���һԪ�º��� __f_unary ��ȡ�����
 * 
 * binary_negate not1(const _Function &__f_binary)
 *  1. ������
 *    1.1 __f_binary����Ҫһ������ֵΪ bool ���͵Ķ�Ԫ�º������Ҽ̳��� binary_function<T1 arg_01, T2 arg_02, R ret>
 *  2. ����ֵ��binary_negate ��һ����Ԫ�º��������صĺ������ò������ĺ����ķ���ֵ���β��б�ͬ������ָ���ķº��� __f_binary���������ڲ�ʵ���л���÷�����¼��Ķ�Ԫ�º��� __f_binary ��ȡ�����
 * 
 * ʹ�ó��������������ĳ�ַ��� bool ���͵ķº�������ʵȡֵ�����������ʱ�����ǿ���ͨ�� not �����������������ڲ�����ԭ�º�����Դ�����ǰ������ɶ���ȡֵ�����ȡ������
 * 
*/
void foo_NOT(void) {
  int nums[5] = { 3, 2, 4, 1, 5 };
  vector<int> __v(nums, nums + (sizeof(nums) / sizeof(int)));

  sort(__v.begin(), __v.end(), not2(less<int>()));

  vector<int>::iterator _result = find_if(__v.begin(), __v.end(), not1(bind2nd(greater<int>(), 2)));
  cout << *_result << endl;
}

/** ����������
 *
 * pointer_to_unary_function ptr_fun(unary_function invoker)
 *  1. ����
 *    1.1 unary_function������һ������ֵΪ�������ͣ�����ֻ��һ�����������βεĺ���ָ��
 *  2. ����ֵ��pointer_to_unary_function ��һ�� һԪ�º����������صĺ������ò������ĺ�����һ���β��б�ͷ���ֵ����ͬ��������ָ�벢������Ϊ cost �ĳ����������ڲ�ʵ���л���ú���ָ�� invoker
 * 
 * 
 * pointer_to_binary_function ptr_fun(binary_function invoker)
 *  1. ����
 *    1.1 binary_function������һ������ֵΪ�������ͣ��������������������βεĺ���ָ��
 *  2. ����ֵ��pointer_to_binary_function ��һ�� ��Ԫ�º����������صĺ������ò������ĺ�����һ���β��б�ͷ���ֵ����ͬ��������ָ�벢������Ϊ cost �ĳ����������ڲ�ʵ���л���ú���ָ�� invoker
 * 
 * ʹ�ó�������һ����ͨ�ĺ���ת��Ϊ �����صĺ������ò������ĺ�������Ϊ const �ķº���
 * 
*/
bool f_sort(int &_left,int &_right) {
  return _left > _right;
}
void foo_function(void) {
  int nums[5] = { 3, 2, 4, 1, 5 };
  vector<int> __v(nums, nums + (sizeof(nums) / sizeof(int)));

  sort(__v.begin(), __v.end(), ptr_fun(f_sort));
}

/** ��Ա����������
 *
 * mem_fun_ref_t mem_fun_ref(member_function_none invoker)
 *  1. ����
 *    1.1 member_function_none������һ���������ͷ���ֵ�������βε�ĳ����� [��Ա����]
 *  2. ����ֵ��mem_fun_ref_t ��һ�� һԪ�º����������صĺ������ò������ĺ����ķ���ֵͬ������Ա���� invoker���β��б����һ�� ��Ա���� ����������͵��β� _src����ָ���ĳ�Ա���� invoker �����β� _src ��ʵ�����������ò���
 * 
 * 
 *  mem_fun1_ref_t mem_fun_ref(member_function_unary invoker)
 *  1. ����
 *    1.1 member_function_unary������һ���������ͷ���ֵ����ֻ��һ���βε�ĳ����� [��Ա����]
 *  2. ����ֵ��mem_fun1_ref_t ��һ�� ��Ԫ�º����������صĺ������ò������ĺ����ķ���ֵͬ������Ա���� invoker���β��б���� ��Ա���� ����������͵��β� _src �� ��Ա���� ��һ���βε����͵��β� _arg����ָ���ĳ�Ա���� invoker �����β� _src ��ʵ�������ڵ���ʱ¼���β� _arg �������ò���
 * 
 * ʹ�ó��������������ܹ���һ����Ա����һ�ַº����Թ����ã����ڲ�ʵ�������ڳ�Ա�����ͺ���ָ��֮���ת����ϵ����ɣ������֮�ú����ĵ��û���Ҫ�����ڳ�Ա������������ʵ���ı�����ܹ���ɵ���
 * 
*/
class Person {
public:
  Person(int _age)
    : m_age(_age){};
public:
  void speak(string _words) {
    cout << _words << " age = " << this->m_age << endl;
  }
  void Do() {
    cout << "DO! AGE = " << this->m_age << endl;
  }
  
public:
  int m_age;
};
void foo_member_function(void) {
  vector<Person> __v;
  __v.push_back(Person(1));
  __v.push_back(Person(2));
  __v.push_back(Person(3));
  __v.push_back(Person(4));
  __v.push_back(Person(5));

  for_each(__v.begin(), __v.end(), bind2nd(mem_fun_ref(Person::speak), "HELLO,WORLD"));

  for_each(__v.begin(), __v.end(), mem_fun_ref(Person::Do));
}

int main(void) {
  /* foo_functor(); */
  /* foo_NOT(); */
  /* foo_function(); */
  /* foo_member_function(); */


  system("pause");
  return EXIT_SUCCESS;
}