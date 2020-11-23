#include <iostream>
using namespace std;

class person_base {
public:
  char m_gender = 'K';
};

class student : public person_base {
public:
  int m_age = 10;
};

int main(void) {
  student stu_stack;
  person_base *base_1 = &stu_stack;

  person_base *base_2 = new student();
  student *stu_heap = (student *)base_2;

  return EXIT_SUCCESS;
}