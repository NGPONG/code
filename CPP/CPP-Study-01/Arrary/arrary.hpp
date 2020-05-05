#ifndef __ARRARY_HPP__
#define __ARRARY_HPP__

#include <iostream>
#include <string.h>

template<class T>
class Arrary {
public:
  /* constructor */
  Arrary(int _length)
    : length(_length) {
    m_arrary = new T[this->length];
    memset(this->m_arrary, 0, sizeof(T) * _length);
  };
  /* copy constructor */
  Arrary(const Arrary<T> &arrary) {
    this->length = arrary.length;

    this->capacity = arrary.capacity;

    this->m_arrary = new T[this->length];
    memcpy(this->m_arrary, arrary.m_arrary, sizeof(T) * arrary.length);
  };
  /* move constructor */
  Arrary(Arrary<T> &&arrary) {
    this->length = arrary.length;
    arrary.length = 0x0;

    this->capacity = arrary.capacity;
    arrary.capacity = 0x0;

    this->m_arrary = arrary.m_arrary;
    arrary.m_arrary = nullptr;
  };
  /* destructor */
  ~Arrary() {
    if (this->m_arrary) {
      delete[] this->m_arrary;
    }
  };

public:
  /* copy assignment operator function */
  Arrary<T> &operator=(const Arrary<T> &arrary) {
    this->length = arrary.length;

    this->capacity = arrary.capacity;

    if (this->m_arrary) delete[] this->m_arrary;
    this->m_arrary = new T[this->length];
    memcpy(this->m_arrary, arrary.m_arrary, sizeof(T) * arrary.length);
  }
  /* move assignment operator function */
  Arrary<T> &operator=(Arrary<T> &&arrary) {
    this->length = arrary.length;
    arrary.length = 0x0;

    this->capacity = arrary.capacity;
    arrary.capacity = 0x0;

    if (this->m_arrary) delete[] this->m_arrary;
    this->m_arrary = arrary.m_arrary;
    arrary.m_arrary = nullptr;
  }
  /* index assignment operator function */
  T &operator[](size_t _index) {
    if (_index > this->length) _index = this->length - 1;
    return m_arrary[_index];
  }

public:
  /* push back insert a new element */
  void Add(T _val) {
    if (this->m_arrary == nullptr) return;

    /* The maximum limit has been reached. */
    if (capacity >= this->length) return;

    this->m_arrary[this->capacity] = _val;
    ++this->capacity;
  }

public:
  size_t length = 0;

private:
  T *m_arrary = nullptr;
  size_t capacity = 0;
};


#endif /* end of include guard: __ARRARY_HPP__ */
