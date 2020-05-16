#include <iostream>
using namespace std;

#include "filemanager.h"
#include "gamecol.h"

void foo(void) {
  controller sys;
  sys.print("Welcome!\n\n");

  sys.print("Please choose your favorite hero:\n");
  sys.get_heros();


}

int main(void) {
  foo();

  system("pause");
  return EXIT_SUCCESS;
}