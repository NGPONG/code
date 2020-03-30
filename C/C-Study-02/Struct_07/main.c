#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

struct Student {

  void (*invoker)(struct Student);
  int age;
};

void fun_test(struct Student stu) {
  printf("Student age = %d\n", stu.age);
}

int main(void) {

  struct Student student;
  student.age = 1024;
  student.invoker = fun_test;

  student.invoker(student);

  system("pause");
  return EXIT_SUCCESS;
}