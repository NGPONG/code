#include <iostream>
using namespace std;

#include <string.h>

class BASE {
  friend ostream &operator<<(ostream &out, BASE _base) {
    for (size_t i = 0; i < _base.m_capacity; i++) {
      cout << _base.m_container[i] << "\t";
    }
    return out;
  };

public:
  BASE(int _capactiy) {
    cout << "BASE CONSTRUCTOR" << endl;

    this->m_container = new int[_capactiy];
    this->m_capacity = _capactiy;

    _init();
  };
  BASE(const BASE &_base) {
    cout << "BASE COPY CONSTRUCTOR" << endl;

    this->m_capacity = _base.m_capacity;

    this->m_container = new int[this->m_capacity];
    memcpy(this->m_container, _base.m_container, sizeof(int) * _base.m_capacity); /* copy data */
  }
  ~BASE() {
    if (this->m_container) {
      delete[] this->m_container;
    }
    cout << "DESTRUCTOR:" << this << endl;
  }

public:
  int &operator[](int _index) {
    return this->m_container[_index];
  };

private:
  void _init(void) {
    if (this->m_container == nullptr) { return; }

    for (size_t i = 0; i < this->m_capacity; i++) {
      this->m_container[i] = i + 1;
    }
  }

private:
  int *m_container;
  size_t m_capacity;
};

void operator+(BASE _base,int _plus) {
  cout << _base << endl;
  cout << "OK!" << endl;
}

int main(void) {
  BASE base(10);
  cout << base << endl;

  cout << base[8] << endl;

  base + 1;

  system("pause");
  return EXIT_SUCCESS;
}