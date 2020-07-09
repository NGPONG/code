#include <iostream>
using namespace std;

#include <functional>

#include "filemanager.h"
#include "gamecol.h"


void foo(void) {
  controller sys;
  sys.get_heros();
  sys.print("Welcome!\n\n");
  sys.print("Please choose your favorite hero:\n");
  sys.get_heros();
  sys.select_heros();
  sys.print("Please choose your what weapon will used\n");
  sys.get_weapons();
  sys.select_weapons();
}

int main(void) {
  foo();
  return EXIT_SUCCESS;
}
