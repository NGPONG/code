#ifndef _A_H_
#define _A_H_

#include <iostream>

#include "b.h"

class A {
public:
  A(std::int32_t val) {
    std::cout << "A constructor:" << std::endl;
    std::cout << "  g_b: " << (g_b.m_val == nullptr ? 0 : *g_b.m_val) << std::endl;
    m_val = new std::int32_t(val);
  }

  ~A() {
    std::cout << "A destructor" << std::endl;
    std::cout << "  g_b: " << (g_b.m_val == nullptr ? 0 : *g_b.m_val) << std::endl;

    delete m_val;
  }

  std::int32_t* m_val;
};

extern A g_a;

#endif
