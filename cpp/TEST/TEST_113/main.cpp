#include <cstring>
#include <iostream>

class C1 {
public:
  std::int64_t c1_val = 0x1111111111111111; // 0x7fffffffe018
};

class C2 {
public:
  std::int64_t c2_val = 0x2222222222222222; // 0x7fffffffe020
};

class C3 : public virtual C1, public virtual C2 {
public:
  C3() {
    c1_val += 0x1111111111111111;
    c2_val += 0x2222222222222222;
  }

  std::int64_t c3_val = 0x3333333333333333;
};

class C4 : public C3 {
public:
  C4() : C1(), C2(), C3() {}

  std::int64_t c4_val = 0x4444444444444444;
};

std::int32_t main(void) {
  C4 c4;

  // hy.m_age += 0x12345678;
  // hy.m_val_dog += 0x12345678;
  // hy.m_val_cat += 0x12345678;

  // Base b; //
  // 即便是空类，为了保证地址运算于对象唯一性，编译器都至少为其分配一个字节的全部初始化为空的内存数据
  // std::cout << sizeof(b) << std::endl;

  // 虚函数和虚析构警惕使用这个东西
  // std::memset((void *)&last, 0x0, sizeof(Last));

  return EXIT_SUCCESS;
}
