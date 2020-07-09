#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

/** 仿函数适配器
 * 
 *  binder2nd bind2nd(const _Function &__f_binary, const _Type &__val)
 *  1. 参数
 *    1.1 __f_binary：需要是一个二元仿函数(所重载的函数调用操作符的函数需要声明为 常函数，因为最终会通过一个常函数来调用仿函数)并且继承自 binary_function<T1 arg_01, T2 arg_02, R ret>
 *    1.2 __val：需要和 __f_binary 进行绑定的值
 *  2. 返回值：binder2nd 是一个一元仿函数，其所实现的重载函数调用操作符的函数的返回值同步至所指定的仿函数 __f_binary，形参列表接收一个所指定的二元仿函数 __f_binary 的第一个形参的类型的形参 __val_src 的输入，并在其内部实现中又调用了我们所录入的仿函数 __f_binary，并在调用 __f_binary 时会输入两个参数，它们分别是 __val_src 和 bind2nd 构造时所录入的实参 __val
 *  3. 使用场景：在某些 API 需要指定一个一元仿函数但是现有只有二元仿函数时，可以使用 bind2nd 进行适配工作
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

/** 取反适配器
 * 
 * unary_negate not1(const _Function &__f_unary)
 *  1. 参数：
 *    1.1 __f_unary：需要一个返回值为 bool 类型的一元仿函数并且继承自 unary_function<T1 arg, R ret>
 *  2. 返回值：unary_negate 是一个一元仿函数，重载的函数调用操作符的函数的返回值和形参列表同步至所指定的仿函数 __f_unary，并且其内部实现中会调用返回所录入的一元仿函数 __f_unary 的取反结果
 * 
 * binary_negate not1(const _Function &__f_binary)
 *  1. 参数：
 *    1.1 __f_binary：需要一个返回值为 bool 类型的二元仿函数并且继承自 binary_function<T1 arg_01, T2 arg_02, R ret>
 *  2. 返回值：binary_negate 是一个二元仿函数，重载的函数调用操作符的函数的返回值和形参列表同步至所指定的仿函数 __f_binary，并且其内部实现中会调用返回所录入的二元仿函数 __f_binary 的取反结果
 * 
 * 使用场景：当我们针对某种返回 bool 类型的仿函数的真实取值结果并不满意时，我们可以通过 not 适配器的适配作用在不更改原仿函数的源代码的前提下完成对其取值结果的取反工作
 * 
*/
void foo_NOT(void) {
  int nums[5] = { 3, 2, 4, 1, 5 };
  vector<int> __v(nums, nums + (sizeof(nums) / sizeof(int)));

  sort(__v.begin(), __v.end(), not2(less<int>()));

  vector<int>::iterator _result = find_if(__v.begin(), __v.end(), not1(bind2nd(greater<int>(), 2)));
  cout << *_result << endl;
}

/** 函数适配器
 *
 * pointer_to_unary_function ptr_fun(unary_function invoker)
 *  1. 参数
 *    1.1 unary_function：接收一个返回值为任意类型，但是只有一个任意类型形参的函数指针
 *  2. 返回值：pointer_to_unary_function 是一个 一元仿函数，所重载的函数调用操作符的函数是一个形参列表和返回值类型同步至函数指针并且声明为 cost 的常函数，其内部实现中会调用函数指针 invoker
 * 
 * 
 * pointer_to_binary_function ptr_fun(binary_function invoker)
 *  1. 参数
 *    1.1 binary_function：接收一个返回值为任意类型，但是有两个任意类型形参的函数指针
 *  2. 返回值：pointer_to_binary_function 是一个 二元仿函数，所重载的函数调用操作符的函数是一个形参列表和返回值类型同步至函数指针并且声明为 cost 的常函数，其内部实现中会调用函数指针 invoker
 * 
 * 使用场景：将一个普通的函数转换为 所重载的函数调用操作符的函数声明为 const 的仿函数
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

/** 成员函数适配器
 *
 * mem_fun_ref_t mem_fun_ref(member_function_none invoker)
 *  1. 参数
 *    1.1 member_function_none：接受一个任意类型返回值但是无形参的某个类的 [成员函数]
 *  2. 返回值：mem_fun_ref_t 是一个 一元仿函数，所重载的函数调用操作符的函数的返回值同步至成员函数 invoker，形参列表接收一个 成员函数 所在类的类型的形参 _src，所指定的成员函数 invoker 依赖形参 _src 的实例化完成其调用操作
 * 
 * 
 *  mem_fun1_ref_t mem_fun_ref(member_function_unary invoker)
 *  1. 参数
 *    1.1 member_function_unary：接受一个任意类型返回值但是只有一个形参的某个类的 [成员函数]
 *  2. 返回值：mem_fun1_ref_t 是一个 二元仿函数，所重载的函数调用操作符的函数的返回值同步至成员函数 invoker，形参列表接收 成员函数 所在类的类型的形参 _src 和 成员函数 第一个形参的类型的形参 _arg，所指定的成员函数 invoker 依赖形参 _src 的实例化并在调用时录入形参 _arg 完成其调用操作
 * 
 * 使用场景：该适配器能够将一个成员函数一种仿函数以供调用，其内部实现依赖于成员函数和函数指针之间的转换关系来完成，简而言之该函数的调用还是要依赖于成员函数所在类型实例的本身才能够完成调用
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