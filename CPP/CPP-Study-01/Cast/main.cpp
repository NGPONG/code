#include <iostream>
using namespace std;

class BASE {};

class DERIVED_01 : public BASE {};

class DERIVED_02 : public BASE {};

class OTHEER {};

int main(void) {
  DERIVED_01 *dp_01 = new DERIVED_01;
  BASE *base = static_cast<BASE *>(dp_01);

  system("pause");
  return EXIT_SUCCESS;
}