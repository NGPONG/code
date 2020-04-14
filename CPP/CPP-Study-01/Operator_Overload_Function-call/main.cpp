#include <iostream>
using namespace std;

class Printer {
public:
  /** 
   * function-call assignment operator
   * 1. 只能声明为成员函数
   */
  void operator()(char *str) {
    cout << str << endl;
  }
};

int main(void) {
  Printer()((char *)"Hello,World!");

  system("pause");
  return EXIT_SUCCESS;
}