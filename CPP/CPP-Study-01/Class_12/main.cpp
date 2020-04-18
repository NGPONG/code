#include <iostream>
using namespace std;

class ANIMAL {
public:
  ANIMAL() { }

  ANIMAL(char _SEX)
      : SEX(_SEX) {
    cout << "ANIMAL CONSTRUCTOR" << endl;
  }

public:
  char SEX;
};

class DOG : public virtual ANIMAL {
public:
  DOG(char *name)
      : d_name(name) {
    cout << "DOG CONSTRUCTOR" << endl;
  }

public:
  char *d_name;
};

class CAT : public virtual ANIMAL {
public:
  CAT(char *name)
      : c_name(name) {
    cout << "CAT CONSTRUCTOR" << endl;
  }

public:
  char *c_name;
};

class HYBIRD : public DOG, public CAT {
public:
  HYBIRD(char *name, char _SEX)
      : ANIMAL(_SEX), DOG(name), CAT(name) {
    cout << "HYBIRD CONSTRUCTOR" << endl;
  }

public:
  int h_age = 0x400;
};

int main(void) {
  HYBIRD hy((char *)"Hello,World!", 'K');

  cout << *(((int *)(*(int *)&hy))) << endl;

  system("pause");
  return EXIT_SUCCESS;
}