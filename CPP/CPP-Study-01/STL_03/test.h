#ifndef __TEST_H__
#define __TEST_H__

#include <deque>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/* class invoker; */

class Person;

class invoker {
public:
  virtual void execute(Person &per) = 0;
  virtual ~invoker() = 0;
};
/* invoker::~invoker() {
  cout << "invoker destructor" << endl;
}; */

class select_sort : public invoker {
public:
  void execute(Person &per) override;
  ~select_sort() override;
};

class insert_sort : public invoker {
public:
  void execute(Person &per) override;
  ~insert_sort() override;
};


class Person {
  friend void select_sort::execute(Person &per);
  friend void insert_sort::execute(Person &per);

public:
  Person(char _name, invoker *_inv);
  Person(Person &&per);
  ~Person();

public:
  Person &operator=(const Person &per);
  Person &operator=(Person &&per);

public:
  double get_average(void);
  string &get_name(void);

public:
  deque<int> m_scores;
  invoker *sorter;

private:
  string m_name;
};

#endif /* end of include guard: __TEST_H__ */
