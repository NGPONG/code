#include <iostream>
using namespace std;

#include <algorithm>

void cin_test_01() {
  char _input = 0;
  while (true) {
    _input = cin.get();
    cout << _input << endl;
  }
}

void cin_test_02() {
  char str[5];
  cin.get(str, 5);

  cout << str << endl;
}

void cin_test_03() {
  char str[5];
  cin.getline(str, 5);

  cout << str << endl;
}

void cin_test_04() {
  char ch = getchar();

  cin.ignore(3);

  char str[32] = { 0 };
  cin.getline(str, 32);

  cin.getline(str, 32);
}

void cin_test_05() {
  char ch_01 = cin.get();
  cout << ch_01 << endl;

  char ch_02 = cin.peek();
  cout << ch_02 << endl;
}

void cin_test_06() {
  char ch = cin.get();

  cin.putback(ch);
  cin.putback('O');
  /* cin.putback(ch); */

  char str[64] = { 0 };
  cin.getline(str, 64);
  cout << str << endl;
}

void cin_test_07() {
  int num;
  cin >> num;

  cout << cin.fail() << endl;

  cin.clear();
  cin.sync();

  char ch = cin.get();
  cout << ch << endl;
}

int main(void) {
  /* cin_test_01(); */

  /* cin_test_02(); */

  /* cin_test_03(); */

  /* cin_test_04(); */

  /* cin_test_05(); */

  /* cin_test_06(); */

  cin_test_07();

  system("pause");
  return EXIT_SUCCESS;
}