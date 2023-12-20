#ifndef KWI_BOT_ARENA_MODULE_H
#define KWI_BOT_ARENA_MODULE_H

#ifdef _MSC_VER
#pragma once
#endif

#include <iostream>
#include <string>

using namespace std;

class HAHAH{};

class BASE: public HAHAH {
public:
  BASE(const std::string& str) {
    std::cout << str << std::endl;
  }

  void foo() {
    std::cout << "hello,world!" << std::endl;
  }
};

#endif
