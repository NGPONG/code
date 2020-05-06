#include <iostream>
using namespace std;

#include <stack>
#include <deque>

/** CONSTRUCTOR
 * stack<T>()               默认构造，构建一个空的 stack 容器
 * stack(const stack &_st)  拷贝构造函数，将已有 stack 容器实例内部所维护的元素拷贝至当前 stack 容器实例内部
*/
void fun_constructor() {
  /* stack<T>() */
  stack<int> __st;

  /* stack(const stack &_st) */
  stack<int> __st_cpy(__st);
}

/** ASSIGNMENT
 * stack &operator=(const stack &_st)   拷贝赋值运算符，依据已有 stack 的实例内部所维护的元素去重新构造当前 stack 实例
*/
void fun_assignment() {
  stack<int> __st_src;
  stack<int> __st_cpy;

  /* stack &operator=(const stack &_st) */
  __st_src = __st_cpy;
}

/** OPERATOR
 * void push(T _element)           向栈顶添加元素 _element
 * void pop()                      从栈顶移除第一个元素
 * T &top()                        返回栈顶元素的引用
*/
void fun_operator(void) {
  stack<int> __st;

  /* void push(T _element) */
  __st.push(0x100);
  __st.push(0x200);
  __st.push(0x300);

  /* T &top() */
  int _val = __st.top();
  cout << _val << endl;

  /* void pop() */
  __st.pop();
}

/** SIZE
 * bool empty()      判断 stack 容器内部是否为空
 * size_t size()     获取 stack 容器内部所维护的元素的个数
*/
void fun_size() {
  stack<int> __st;

  /* bool empty() */
  bool flag = __st.empty();

  /* size_t size() */
  size_t cout = __st.size();
}

int main(void) {
  fun_operator();

  system("pause");
  return EXIT_SUCCESS;
}