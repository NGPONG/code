#ifndef __M_STRING_H__
#define __M_STRING_H__

#include <string.h>
#include <iostream>

using namespace std;

class m_string {
  friend ostream &operator<<(ostream &cout, const m_string &str);

public:
  /* constructor */
  m_string(const char *data_);
  
  /* copy constructor */
  m_string(const m_string &str_l);

  /* move constructor */
  m_string(m_string &&str_r);

  /* destructor */
  ~m_string();

public:
  /* copy assignment operator */
  m_string &operator=(const m_string &str_l);
  /* move assignment operator */
  m_string &&operator=(m_string &&str_r);

public:
  m_string &operator=(const char *data_);
  char &operator[](int index);
  m_string &operator+(const char *data_);
  m_string &operator+(const m_string &str);
  bool operator==(const char *str);
  bool operator==(const m_string &str);
  
public:
  int length = 0;

private:
  char *p_str = nullptr;
  void dispose();
};

#endif /* end of include guard: __M_STRING_H__ */
