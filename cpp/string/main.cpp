#include <iostream>
using namespace std;

/** CONSTRUCTOR
 * string()                      空字符串
 * string(const string &str)     拷贝构造函数
 * string(const char *str)       使用 char * 类型的字符串进行构造
 * string(int n, char _ch)       使用 n 个字符 _ch 进行构造
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
 * string &operator=(const char *str)                   根据字符串 str 去重新构造 string 实例内部所管控的字符串
 * string &operator=(const string &str)                 根据 拷贝赋值运算符 去重新构造 string 实例内部所管控的字符串
 * string &operator=(char _ch)                          根据字符 _ch 去重新构造 string 实例内部所管控的字符串
 * string &assign(const char *str)                      根据字符串 str 去重新构造 string 实例内部所管控的字符串
 * string &assign(const char *str, int n)               截取字符串 str 的前 n 个字符去重新构造 string 实例内部所管控的字符串
 * string &assign(const string &str)                    根据已有的 string 实例内部所管控的字符串去重新构造当前实例内部所管控的字符串
 * string &assign(int n, char _ch)                      使用 n 个字符 _ch 去重新构造 string 实例内部所管控的字符串
 * string &assign(const string &str, int start, int n)  根据已有的 string 实例内部所管控的字符串从 start 下标开始的 n 个字符去重新构造当前实例内部所管控的字符串
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
 * char &operator[](int n)    获取字符串下标为 n 的字符，当 n 超出当前字符串最大长度时，程序会直接结束
 * char &at(int n)            获取字符串下标为 n 的字符，当 n 超出当前字符串最大长度时，则抛出 out_of_range 的异常
 * 
 * 由于所返回的都是 string 实例内部所管控的字符串的某一个下标字符的引用，那么当 string 容器内部所管控的字符串的内存被重新分配后，原有的引用则会失效，这时候再继续使用则会发生错误
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
 * string &operator+=(const string &str)                已有 string 的实例 str 内部所管控的字符串追加到当前 string 实例内部所管控的字符串的末尾处
 * string &operator+=(const char *str)                  字符串 str 追加到 string 实例内部所管控的字符串的末尾处
 * string &operator+=(const char _ch)                   字符 _ch 追加到 string 实例内部所管控的字符串的末尾处
 * string &append(const char *str)                      字符串 str 追加到 string 实例内部所管控的字符串的末尾处
 * string &append(const char *str, int n)               字符串 str 的前 n 个字符追加到 string 实例内部所管控的字符串的末尾处
 * string &append(const string &str)                    已有 string 的实例 str 内部所管控的字符串追加到当前 string 实例内部所管控的字符串的末尾处
 * string &append(const string &str, int start, int n)  已有 string 的实例 str 内部所管控的字符串从 start 下标开始的 n 个字符追加到当前 string 实例内部所管控的字符串的末尾处
 * string &append(int n, char _ch)                      string 实例内部所管控的字符串的末尾处追加 n 个字符 _ch
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
 * int find(const string &str, int pos = 0) const           当前 string 实例内部所管控的字符串中的 pos 下标开始，从左到右查找已有 string 实例 str 内部所管控的字符串第一次出现下标
 * int find(const char *str, int pos = 0) const             当前 string 实例内部所管控的字符串中的 pos 下标开始，从左到右查找字符串 str 第一次出现的下标
 * int find(const char *str, int pos, int n) const          当前 string 实例内部所管控的字符串中的 pos 下标开始，从左到右查找字符串 str 前 n 个字符第一次出现的下标
 * int find(const char _ch, int pos = 0) const              当前 string 实例内部所管控的字符串中的 pos 下标开始，从左到右查找字符 _ch 第一次出现的下标
 * 
 * int rfind(const string &str, int pos = str_size) const   当前 string 实例内部所管控的字符串中的 pos 下标开始，从右到左查找已有 string 实例 str 内部所管控的字符串第一次出现下标
 * int rfind(const char *str, int pos = str_size) const     当前 string 实例内部所管控的字符串中的 pos 下标开始，从右到左查找字符串 str 第一次出现的下标
 * int rfind(const char *str, int pos, int n) const         当前 string 实例内部所管控的字符串中的 pos 下标开始，从右到左查找字符串 str 前 n 个字符第一次出现的下标
 * int rfind(const char _ch, int pos = str_size) const      当前 string 实例内部所管控的字符串中的 pos 下标开始，从右到左查找字符 _ch 第一次出现的下标
 * 
 * 对于任何无法匹配的结果都返回 -1
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
 * string &replace(int pos, int n, const string &str)   当前 string 实例内部所管控的字符串中的 pos 下标开始的前 n 个字符，替换为已有 string 实例 str 内部所管控的字符串
 * string &replace(int pos, int n, const char* str)     当前 string 实例内部所管控的字符串中的 pos 下标开始的前 n 个字符，替换为字符串 str
*/
void fun_replace() {
  string str_src = "HELLO,WORLD";
  string str_rep = "NGPONG!";

  str_src.replace(str_src.find(',') + 1, str_src.size() - (str_src.find(',') + 1), str_rep);
  str_src.replace(6, 7, "wupeng!");
}

/** COMPARE
 * int compare(const string &str) const   当前 string 实例内部所管控的字符串与已有 string 实例 str 内部所管控的字符串，进行比较
 * int compare(const char *str) const     当前 string 实例内部所管控的字符串与字符串 str，进行比较
 * 
 * 对于比较结果：
 * 原始 >  目标  = 1
 * 原始 <  目标  = -1
 * 原始 == 目标  = 0
*/
void fun_compare(void) {
  string str_cp_01 = "BCDEFG";
  string str_cp_02 = "AWERT";

  cout << str_cp_01.compare(str_cp_02) << endl;
}

/** SUBSTRING
 * string substr(int pos = 0, int n = str_size) const  截取当前 string 实例内部所管控的字符串的 pos 下标开始的前 n 个字符，并返回管控着截取结果的 string 容器的实例
*/
void fun_substring(void) {
  string str = "HELLO,WORLD";

  string str_sub = str.substr(0, str.find(','));
  cout << str_sub << endl;
}

/** INSERT
 * string &insert(int pos, const char *str)     从当前 string 实例内部所管控的字符串的下标 pos 下标中插入字符串 str
 * string &insert(int pos, const string &str)   从当前 string 实例内部所管控的字符串的下标 pos 下标中插入已有 string 实例 str 内部所管控的字符串
 * string &insert(int pos, int n, char _ch)     从当前 string 实例内部所管控的字符串的下标 pos 下标中插入 n 个字符 _ch
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
 * string &erase(int pos, int n = str_size)     删除当前 string 实例内部所管控的字符串从下标 pos 开始的 n 个字符
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