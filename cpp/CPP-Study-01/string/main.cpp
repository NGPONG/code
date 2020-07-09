#include <iostream>
using namespace std;

/** CONSTRUCTOR
 * string()                      ���ַ���
 * string(const string &str)     �������캯��
 * string(const char *str)       ʹ�� char * ���͵��ַ������й���
 * string(int n, char _ch)       ʹ�� n ���ַ� _ch ���й���
*/
void fun_constructor(void) {
  string str_01;
  string str_02("HELLO,WORLD!");
  string str_03 = "HELLO,WORLD!";
  string str_04 = str_03;
  string str_05(str_04);
  string str_06(5, 'A');
}

/** ASSIGNMENT
 * string &operator=(const char *str)                   �����ַ��� str ȥ���¹��� string ʵ���ڲ����ܿص��ַ���
 * string &operator=(const string &str)                 ���� ������ֵ����� ȥ���¹��� string ʵ���ڲ����ܿص��ַ���
 * string &operator=(char _ch)                          �����ַ� _ch ȥ���¹��� string ʵ���ڲ����ܿص��ַ���
 * string &assign(const char *str)                      �����ַ��� str ȥ���¹��� string ʵ���ڲ����ܿص��ַ���
 * string &assign(const char *str, int n)               ��ȡ�ַ��� str ��ǰ n ���ַ�ȥ���¹��� string ʵ���ڲ����ܿص��ַ���
 * string &assign(const string &str)                    �������е� string ʵ���ڲ����ܿص��ַ���ȥ���¹��쵱ǰʵ���ڲ����ܿص��ַ���
 * string &assign(int n, char _ch)                      ʹ�� n ���ַ� _ch ȥ���¹��� string ʵ���ڲ����ܿص��ַ���
 * string &assign(const string &str, int start, int n)  �������е� string ʵ���ڲ����ܿص��ַ����� start �±꿪ʼ�� n ���ַ�ȥ���¹��쵱ǰʵ���ڲ����ܿص��ַ���
*/
void fun_assignment(void) {
  string str_source;
  string str_dest = "HELLO,WORLD";

  str_source = "NGPONG!";
  str_source = str_dest;
  str_source = 'A';
  str_source.assign("HELLO,NGPONG!");
  str_source.assign("HELLO,NGPONG!", 2);
  str_source.assign(str_dest);
  str_source.assign(10, 'A');
  str_source.assign(str_dest, 6, 5);
}

/** ACQUIRE
 * char &operator[](int n)    ��ȡ�ַ����±�Ϊ n ���ַ����� n ������ǰ�ַ�����󳤶�ʱ�������ֱ�ӽ���
 * char &at(int n)            ��ȡ�ַ����±�Ϊ n ���ַ����� n ������ǰ�ַ�����󳤶�ʱ�����׳� out_of_range ���쳣
 * 
 * ���������صĶ��� string ʵ���ڲ����ܿص��ַ�����ĳһ���±��ַ������ã���ô�� string �����ڲ����ܿص��ַ������ڴ汻���·����ԭ�е��������ʧЧ����ʱ���ټ���ʹ����ᷢ������
*/
void fun_acquire(void) {
  string str = "HELLO,WORLD";

  cout << str[5] << endl;
  cout << str.at(0) << endl;

  try {
    str.at(0x400);
  } catch (out_of_range _e) {
    cout << _e.what() << endl;
  }
}

/** APPEND
 * string &operator+=(const string &str)                ���� string ��ʵ�� str �ڲ����ܿص��ַ���׷�ӵ���ǰ string ʵ���ڲ����ܿص��ַ�����ĩβ��
 * string &operator+=(const char *str)                  �ַ��� str ׷�ӵ� string ʵ���ڲ����ܿص��ַ�����ĩβ��
 * string &operator+=(const char _ch)                   �ַ� _ch ׷�ӵ� string ʵ���ڲ����ܿص��ַ�����ĩβ��
 * string &append(const char *str)                      �ַ��� str ׷�ӵ� string ʵ���ڲ����ܿص��ַ�����ĩβ��
 * string &append(const char *str, int n)               �ַ��� str ��ǰ n ���ַ�׷�ӵ� string ʵ���ڲ����ܿص��ַ�����ĩβ��
 * string &append(const string &str)                    ���� string ��ʵ�� str �ڲ����ܿص��ַ���׷�ӵ���ǰ string ʵ���ڲ����ܿص��ַ�����ĩβ��
 * string &append(const string &str, int start, int n)  ���� string ��ʵ�� str �ڲ����ܿص��ַ����� start �±꿪ʼ�� n ���ַ�׷�ӵ���ǰ string ʵ���ڲ����ܿص��ַ�����ĩβ��
 * string &append(int n, char _ch)                      string ʵ���ڲ����ܿص��ַ�����ĩβ��׷�� n ���ַ� _ch
*/
void fun_append(void) {
  string str_src = "HELLO,WORLD";
  string str_dest = "NGPONG";

  str_src += ",";
  str_src += str_dest;
  str_src += '!';

  str_src.append(1, ',');
  str_src.append("hahaha");
  str_src.append(",GET,UP!", 5);
  str_src.append(str_dest);
  str_src.append(str_dest, 0, 2);
}

/** FIND
 * int find(const string &str, int pos = 0) const           ��ǰ string ʵ���ڲ����ܿص��ַ����е� pos �±꿪ʼ�������Ҳ������� string ʵ�� str �ڲ����ܿص��ַ�����һ�γ����±�
 * int find(const char *str, int pos = 0) const             ��ǰ string ʵ���ڲ����ܿص��ַ����е� pos �±꿪ʼ�������Ҳ����ַ��� str ��һ�γ��ֵ��±�
 * int find(const char *str, int pos, int n) const          ��ǰ string ʵ���ڲ����ܿص��ַ����е� pos �±꿪ʼ�������Ҳ����ַ��� str ǰ n ���ַ���һ�γ��ֵ��±�
 * int find(const char _ch, int pos = 0) const              ��ǰ string ʵ���ڲ����ܿص��ַ����е� pos �±꿪ʼ�������Ҳ����ַ� _ch ��һ�γ��ֵ��±�
 * 
 * int rfind(const string &str, int pos = str_size) const   ��ǰ string ʵ���ڲ����ܿص��ַ����е� pos �±꿪ʼ�����ҵ���������� string ʵ�� str �ڲ����ܿص��ַ�����һ�γ����±�
 * int rfind(const char *str, int pos = str_size) const     ��ǰ string ʵ���ڲ����ܿص��ַ����е� pos �±꿪ʼ�����ҵ�������ַ��� str ��һ�γ��ֵ��±�
 * int rfind(const char *str, int pos, int n) const         ��ǰ string ʵ���ڲ����ܿص��ַ����е� pos �±꿪ʼ�����ҵ�������ַ��� str ǰ n ���ַ���һ�γ��ֵ��±�
 * int rfind(const char _ch, int pos = str_size) const      ��ǰ string ʵ���ڲ����ܿص��ַ����е� pos �±꿪ʼ�����ҵ�������ַ� _ch ��һ�γ��ֵ��±�
 * 
 * �����κ��޷�ƥ��Ľ�������� -1
*/
void fun_find(void) {
  string str_src = "HELLO,WORLOD";
  string str_fi = "WOR";

  cout << str_src.find(str_fi, 0) << endl;
  cout << str_src.find("LO", 0) << endl;
  cout << str_src.find("LO", 5, 2) << endl;
  cout << str_src.find('E', 0) << endl;

  cout << str_src.rfind(str_fi, str_src.size()) << endl;
  cout << str_src.rfind("LK", str_src.size()) << endl;
  cout << str_src.rfind("LO", 5, 2) << endl;
  cout << str_src.rfind('E', str_src.size()) << endl;
}

/** REPLACE
 * string &replace(int pos, int n, const string &str)   ��ǰ string ʵ���ڲ����ܿص��ַ����е� pos �±꿪ʼ��ǰ n ���ַ����滻Ϊ���� string ʵ�� str �ڲ����ܿص��ַ���
 * string &replace(int pos, int n, const char* str)     ��ǰ string ʵ���ڲ����ܿص��ַ����е� pos �±꿪ʼ��ǰ n ���ַ����滻Ϊ�ַ��� str
*/
void fun_replace() {
  string str_src = "HELLO,WORLD";
  string str_rep = "NGPONG!";

  str_src.replace(str_src.find(',') + 1, str_src.size() - (str_src.find(',') + 1), str_rep);
  str_src.replace(6, 7, "wupeng!");
}

/** COMPARE
 * int compare(const string &str) const   ��ǰ string ʵ���ڲ����ܿص��ַ��������� string ʵ�� str �ڲ����ܿص��ַ��������бȽ�
 * int compare(const char *str) const     ��ǰ string ʵ���ڲ����ܿص��ַ������ַ��� str�����бȽ�
 * 
 * ���ڱȽϽ����
 * ԭʼ >  Ŀ��  = 1
 * ԭʼ <  Ŀ��  = -1
 * ԭʼ == Ŀ��  = 0
*/
void fun_compare(void) {
  string str_cp_01 = "BCDEFG";
  string str_cp_02 = "AWERT";

  cout << str_cp_01.compare(str_cp_02) << endl;
}

/** SUBSTRING
 * string substr(int pos = 0, int n = str_size) const  ��ȡ��ǰ string ʵ���ڲ����ܿص��ַ����� pos �±꿪ʼ��ǰ n ���ַ��������عܿ��Ž�ȡ����� string ������ʵ��
*/
void fun_substring(void) {
  string str = "HELLO,WORLD";

  string str_sub = str.substr(0, str.find(','));
  cout << str_sub << endl;
}

/** INSERT
 * string &insert(int pos, const char *str)     �ӵ�ǰ string ʵ���ڲ����ܿص��ַ������±� pos �±��в����ַ��� str
 * string &insert(int pos, const string &str)   �ӵ�ǰ string ʵ���ڲ����ܿص��ַ������±� pos �±��в������� string ʵ�� str �ڲ����ܿص��ַ���
 * string &insert(int pos, int n, char _ch)     �ӵ�ǰ string ʵ���ڲ����ܿص��ַ������±� pos �±��в��� n ���ַ� _ch
*/
void fun_insert(void) {
  string str_src = "HELLO,WORLD";
  string str_des = "NGPONG,";

  str_src.insert(str_src.find(',') + 1, str_des);
  str_src.insert(2, "OO");
  str_src.insert(0, 3, 'A');

  /* AAAHEOOLLO,NGPONG,WORLD */
  cout << str_src << endl;
}

/** DELETE
 * string &erase(int pos, int n = str_size)     ɾ����ǰ string ʵ���ڲ����ܿص��ַ������±� pos ��ʼ�� n ���ַ�
*/
void fun_delete(void) {
  string str = "HELLO,WORLD";
  str.erase(0, 6);
  cout << str << endl;
}

int main(void) {
  /* fun_constructor(); */
  /* fun_assignment(); */
  /* fun_acquire(); */
  /* fun_append(); */
  /* fun_find(); */
  /* fun_replace(); */
  /* fun_compare(); */
  /* fun_substring(); */
  /* fun_insert(); */
  /* fun_delete(); */


  system("pause");
  return EXIT_SUCCESS;
}