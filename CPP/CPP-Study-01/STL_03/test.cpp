#include "test.h"

Person::Person(char _name)
  : m_name(1, _name) {}

double Person::get_average() {
  if (m_scores.empty()) return 0;

  sort(this->m_scores);

  this->m_scores.pop_back();
  this->m_scores.pop_front();

  double num_result = 0;
  for (deque<int>::iterator _it = this->m_scores.begin(); _it != this->m_scores.end(); ++_it) {
    num_result += (*_it);
  }
  num_result /= static_cast<double>(this->m_scores.size());
  
  return num_result;
}

void sort(deque<int> &_dq_src) {
  for (deque<int>::iterator i = _dq_src.begin(); i != _dq_src.end(); ++i) {
    deque<int>::iterator min = i;
    for (deque<int>::iterator j = i + 1; j != _dq_src.end();++j) {
      if(*j < *min) {
        min = j;
      }
    }
    if(min != i) {
      *i = *i ^ *min;
      *min = *i ^ *min;
      *i = *i ^ *min;
    }
  }
}