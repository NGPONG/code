#include <iostream>
using namespace std;

#include <string>

/** USERAGE
 * 
 * constructor
 *  pair<T,V>(T _t, V _v)                指定 pair 所需维护的两个具体的值来进行 pair 实例的初始化构造
 *  pair<T,V>(const pair<T,V> &__p)      拷贝构造函数，依据已有的 pair 实例内部所维护的两个可存在不同类型的值去构造当前 pair 的实例
 * 
 * function
 *  pair<T,V> make_pair<T,V>(T _t, V_v)  该函数用于接受两个可存在不同类型的值，并返回相应类型的 pair
 * 
 * member
 *  first                                获取 pair 所维护的第一个值
 *  second                               获取 pair 所维护的第二个值                                     
*/
void foo(void) {
  /* pair<T,V>(T _t, V _v) */
  pair<string, int> __p_1("HELLO,WORLD", 0x400);

  /* pair<T,V> make_pair<T,V>(T _t, V_v) */
  pair<char, string> __p_2 = make_pair('A', "NGPONG!");

  /* pair<T,V>(const pair<T,V> &__p) */
  pair<string, int> __p_3 = __p_1;

  /* first  */
  cout << __p_1.first << endl;

  /* second */
  cout << __p_1.second << endl;
}

int main(void) {
  foo();

  system("pause");
  return EXIT_SUCCESS;
}