#ifndef _D_H_
#define _D_H_

#include <iostream>

class D {
public:
  D(std::int32_t val) {
    std::cout << "D constructor" << std::endl;
    m_val = new std::int32_t(val);
  }

  ~D() {
    std::cout << "D destructor" << std::endl;
    delete m_val;
  }

  std::int32_t* m_val;
};

extern D g_d;

#endif
