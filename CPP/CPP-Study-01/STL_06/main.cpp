#include <iostream>
using namespace std;

#include "filemanager.h"
#include "gamecol.h"

void foo(void) {
  controller sys;
  sys.print("Welcome!\n\n");

  sys.print("Please choose your favorite hero:\n");
  sys.get_heros();
  sys.select_heros();

  sys.print("Please choose your what weapon will used\n");

}

int main(void) {
  foo();

  system("pause");
  return EXIT_SUCCESS;
}
