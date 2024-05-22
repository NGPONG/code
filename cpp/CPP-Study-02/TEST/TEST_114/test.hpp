#include <iostream>

class Base {
public:
  __attribute__((visibility("hidden")))
  static std::int32_t val;

  // __attribute__((visibility("hidden")))
  static void set_val(std::int32_t _val);
};

class BaseWrapper : protected Base {
public:
  static void foo();
};
