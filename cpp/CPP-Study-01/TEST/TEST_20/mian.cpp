#include <iostream>
using namespace std;

#include <vector>

int main(void) {
  vector<int> *_v = new vector<int>();
  _v->push_back(1);
  _v->push_back(2);
  _v->push_back(3);
  _v->push_back(4);
  _v->push_back(5);

  for (vector<int>::iterator i = _v->begin(); i != _v->end(); ++i) {
    cout << *i << endl;
  }

  return EXIT_SUCCESS;
}
