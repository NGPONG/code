#include <iostream>
using namespace std;

class EXCEPTION {
public:
  EXCEPTION() {
    cout << "EXCEPTION CONSTRUCTOR" << endl;
  }
  EXCEPTION(const EXCEPTION &ex) {
    cout << "EXCEPTION COPY CONSTRUCTOR" << endl;
  }
  EXCEPTION(EXCEPTION &&ex) {
    cout << "EXCEPTION MOVE CONSTRUCTOR" << endl;
  }
  ~EXCEPTION() {
    cout << "EXCEPTION DESTRUCTOR" << endl;
  }
};

void fun_test() {
  try {
    throw EXCEPTION();
  } catch(EXCEPTION ex) {
    throw;
  }
}

int main(void) {
  try {
    fun_test();
  } catch (EXCEPTION ex) {
    cout << "HELLO,EXCE" << endl;
  } catch (int i) {
    cout << i << endl;
    cout << "HELLO,WORLD" << endl;
  }
  

  system("pause");
  return EXIT_SUCCESS;
}