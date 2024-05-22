#ifndef _C_H_
#define _C_H_

#include <iostream>

#include "d.h"

class C {
public:
  C(std::int32_t val) {
    std::cout << "C constructor:" << std::endl;
    std::cout << "  g_d: " << (g_d.m_val == nullptr ? 0 : *g_d.m_val) << std::endl;
    m_val = new std::int32_t(val);
  }

  ~C() {
    std::cout << "C destructor:" << std::endl;
    std::cout << "  g_d: " << (g_d.m_val == nullptr ? 0 : *g_d.m_val) << std::endl;

    delete m_val;
  }

  std::int32_t* m_val;
};

extern C g_c;

#endif
