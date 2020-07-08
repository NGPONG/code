#include <iostream>
using namespace std;

#include <string>

/** USERAGE
 * 
 * constructor
 *  pair<T,V>(T _t, V _v)                ָ�� pair ����ά�������������ֵ������ pair ʵ���ĳ�ʼ������
 *  pair<T,V>(const pair<T,V> &__p)      �������캯�����������е� pair ʵ���ڲ���ά���������ɴ��ڲ�ͬ���͵�ֵȥ���쵱ǰ pair ��ʵ��
 * 
 * function
 *  pair<T,V> make_pair<T,V>(T _t, V_v)  �ú������ڽ��������ɴ��ڲ�ͬ���͵�ֵ����������Ӧ���͵� pair
 * 
 * member
 *  first                                ��ȡ pair ��ά���ĵ�һ��ֵ
 *  second                               ��ȡ pair ��ά���ĵڶ���ֵ                                     
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