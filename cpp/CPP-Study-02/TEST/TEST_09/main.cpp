#include <iostream>
#include <algorithm>
#include <deque>
#include <functional>

template<typename F>
class KWQueueUpLogScopeExit 
{
public:
    KWQueueUpLogScopeExit(const F& f) : func(f) {}
    ~KWQueueUpLogScopeExit() {
        func();
    }

private:
    F func;
};

template<typename S>
class BASE 
{
public:
  BASE(S str): mStr(str) {
    std::cout << "hello,world" << std::endl;
  }

  BASE(std::string&& str): mStr(str) {
    std::cout << "hello,world" << std::endl;
  }

  ~BASE() {
    std::cout << "NGPONG" << std::endl;
  }

private:
  S mStr;
};

int main(void) {
  KWQueueUpLogScopeExit ([&]() {
    std::cout << "hello,world!" << std::endl;
  });

  std::cout << "NGPOPNG"  << std::endl;

  return -1;
}
