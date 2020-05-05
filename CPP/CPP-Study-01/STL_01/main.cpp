#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

void print(int _var) {
  cout << _var << endl;
}

int main(void) {
  vector<int> _container;
  for (size_t i = 0; i < 99; i++) {
    _container.push_back(i + 1);
  }

  /* ��һ�ֱ�����ʽ */
  vector<int>::iterator it_begin = _container.begin();
  vector<int>::iterator it_end = _container.end();

  while (it_begin != it_end) { 
    cout << *it_begin << endl;
    it_begin++;
  };

  /* �ڶ��ֱ�����ʽ */
  for (vector<int>::iterator it = _container.begin(); it != _container.end(); it++) {
    cout << *it << endl;
  }

  /* �����ֱ�����ʽ */
  for_each(_container.begin(), _container.end(), print);

  system("pause");
  return EXIT_SUCCESS;
}