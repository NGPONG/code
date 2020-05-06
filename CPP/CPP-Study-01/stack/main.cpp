#include <iostream>
using namespace std;

#include <stack>
#include <deque>

/** CONSTRUCTOR
 * stack<T>()               Ĭ�Ϲ��죬����һ���յ� stack ����
 * stack(const stack &_st)  �������캯���������� stack ����ʵ���ڲ���ά����Ԫ�ؿ�������ǰ stack ����ʵ���ڲ�
*/
void fun_constructor() {
  /* stack<T>() */
  stack<int> __st;

  /* stack(const stack &_st) */
  stack<int> __st_cpy(__st);
}

/** ASSIGNMENT
 * stack &operator=(const stack &_st)   ������ֵ��������������� stack ��ʵ���ڲ���ά����Ԫ��ȥ���¹��쵱ǰ stack ʵ��
*/
void fun_assignment() {
  stack<int> __st_src;
  stack<int> __st_cpy;

  /* stack &operator=(const stack &_st) */
  __st_src = __st_cpy;
}

/** OPERATOR
 * void push(T _element)           ��ջ�����Ԫ�� _element
 * void pop()                      ��ջ���Ƴ���һ��Ԫ��
 * T &top()                        ����ջ��Ԫ�ص�����
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
 * bool empty()      �ж� stack �����ڲ��Ƿ�Ϊ��
 * size_t size()     ��ȡ stack �����ڲ���ά����Ԫ�صĸ���
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