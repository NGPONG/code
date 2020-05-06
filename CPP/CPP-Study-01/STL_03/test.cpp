#include "test.h"

/** 
 * Person
*/
Person::Person(char _name, invoker *_inv)
  : m_name(1, _name), sorter(_inv){
  printf("create [%p]\n", this->sorter);
};
Person::~Person() {
  if (this->sorter != nullptr) {
    printf("delete [%p]\n", this->sorter);
    delete this->sorter;
    this->sorter = nullptr;
  }
}
Person::Person(Person &&per) {
  this->m_name = per.m_name;
  per.m_name.assign(1, 0);

  this->sorter = per.sorter;
  per.sorter = nullptr;

  this->m_scores.swap(per.m_scores);
  per.m_scores.clear();
}
Person &Person::operator=(Person &&per) {
  this->m_name = per.m_name;
  per.m_name.assign(1,0);

  this->sorter = per.sorter;
  per.sorter = nullptr;

  this->m_scores.swap(per.m_scores);
  per.m_scores.clear();

  return *this;
}
double Person::get_average() {
  if (m_scores.empty()) return 0;

  this->sorter->execute(*this); /* insert_sort(this->m_scores); */

  this->m_scores.pop_back();
  this->m_scores.pop_front();

  double num_result = 0;
  for (deque<int>::iterator _it = this->m_scores.begin(); _it != this->m_scores.end(); ++_it) {
    num_result += (*_it);
  }
  num_result /= static_cast<double>(this->m_scores.size());

  return num_result;
};
string &Person::get_name(void) {
  return this->m_name;
}

/** 
 * select_sort
*/
void select_sort::execute(Person &per) {
  deque<int> &__dq = per.m_scores;

  for (deque<int>::iterator i = __dq.begin(); i != __dq.end(); ++i) {
    deque<int>::iterator min = i;
    for (deque<int>::iterator j = i + 1; j != __dq.end(); ++j) {
      if (*j < *min) {
        min = j;
      }
    }
    if (min != i) {
      *i = *i ^ *min;
      *min = *i ^ *min;
      *i = *i ^ *min;
    }
  }
};
select_sort::~select_sort(){
  cout << "select_sort destructor" << endl;
};

/** 
 * insert_sort
*/
void insert_sort::execute(Person &per) {
  deque<int> &__dq = per.m_scores;

  int buff;
  for (size_t i = 0; i < __dq.size(); ++i) {
    if (__dq[i - 1] > __dq[i]) {
      buff = __dq[i];
      int j = i - 1;
      for (; j >= 0 && __dq[j] > buff; --j) {
        __dq[j + 1] = __dq[j];
      }
      __dq[j + 1] = buff;
    } else
      continue;
  }
};
insert_sort::~insert_sort(){
  cout << "insert_sort destructor" << endl;
};

invoker::~invoker(){
  cout << "invoker destructor" << endl;
};