#include <iostream>
using namespace std;

#include "filemanager.h"
#include "gamecol.h"

void foo(void) {
  controller sys;
  map<int, hero> *heros = sys.init_hero_data();
}

int main(void) {
  foo();

  system("pause");
  return EXIT_SUCCESS;
}