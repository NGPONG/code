#include <iostream>
using namespace std;

class MyArrary {
public:
  MyArrary(int length) {
    this->m_arrary = new int[length];
    this->m_length = length;
  }
  ~MyArrary() {
    if (this->m_arrary != nullptr) delete[] this->m_arrary;
  }

public:
  int &operator[](int index) {
    if(index > this->m_length) index = this->m_length;
    return m_arrary[index];
  }

public:
  int m_length;
  int *m_arrary;
};

int main(void) {
  const int length = 0x400;

  MyArrary arrary(length);
  for (size_t i = 0; i < length; i++) {
    arrary[i] = i + 1;
  }
  for (size_t i = 0; i < length; i++) {
    cout << arrary[i] << endl;
  }

  system("pause");
  return EXIT_SUCCESS;
}