#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <string>
#include <string.h>

class Person {
public:
  Person();
  Person(std::string _name, int _id, int _score);
  Person(const Person &per);
public:
  std::string m_name;
  int m_score[3]; /* Three rounds of scoring */
  int m_id;
};

template<class T, class V>
class person_sort {
public:
  person_sort(T _val)
    : m_val(_val) {}
public:
  bool operator()(V &_left, V &_right) {
    return _left.m_score[this->m_val - 1] > _right.m_score[this->m_val - 1];
  }
private:
  T m_val;
};

#endif /* end of include guard: __PERSON_HPP__ */
