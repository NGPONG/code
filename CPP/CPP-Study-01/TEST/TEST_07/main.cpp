#include <iostream>
using namespace std;

#include "test.h"

class Student {
public:
  int age;
};

int main(void) {

  Student stu;
  stu.age = 1024;

  system("pause");
  return EXIT_SUCCESS;
}