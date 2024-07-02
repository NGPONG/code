#include <iostream>

using namespace std;

typedef struct person student;

struct person {
  int m_age = 0x400;
};

void get_student_age(student *stu) {
  cout << stu->m_age << endl;
}

student *get_student(void) {
  return new student();
}