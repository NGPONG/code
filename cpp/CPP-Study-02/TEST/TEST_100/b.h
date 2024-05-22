#ifndef _B_H_
#define _B_H_

#include <iostream>

#include "c.h"

class B {
public:
  B(std::int32_t val) {
    std::cout << "B constructor:" << std::endl;
    std::cout << "  g_c: " << (g_c.m_val == nullptr ? 0 : *g_c.m_val) << std::endl;
    m_val = new std::int32_t(val);
  }

  ~B() {
    std::cout << "B destructor" << std::endl;
    std::cout << "  g_c: " << (g_c.m_val == nullptr ? 0 : *g_c.m_val) << std::endl;

    delete m_val;
  }

  std::int32_t* m_val;
};

extern B g_b;

#endif
