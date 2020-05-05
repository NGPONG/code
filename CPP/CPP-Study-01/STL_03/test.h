#ifndef __TEST_H__
#define __TEST_H__

#include <deque>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Person {
public:
  Person(char _name);

public:
  double get_average();

public:
  string m_name;
  deque<int> m_scores;
};

void sort(deque<int> &_dq_src);



#endif /* end of include guard: __TEST_H__ */
