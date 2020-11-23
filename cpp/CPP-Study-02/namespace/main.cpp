#include <iostream>
#include <functional>
using namespace std;

int main(void) {
  int i = 10;

  function<bool(void)> invoker = [&](void) -> bool {
    i++;
    return true;
  };

  if(invoker()) {
    cout << "SUCCESS i = " << i << endl;
  }

  return EXIT_SUCCESS;
}