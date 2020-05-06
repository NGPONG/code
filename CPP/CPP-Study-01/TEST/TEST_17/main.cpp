#include <iostream>
using namespace std;

class Person {
public:
  virtual ~Person() = 0;

public:
  virtual void Hello() = 0;
};
Person::~Person(){};

class Student : public Person {
public:
  ~Student() override {
    cout << "STUDENT CONSTRUCTOR" << endl;
  };

public:
  void Hello() override {
    cout << "HELLO,WORLD!" << endl;
  }
};

int main(void) {
  Student stu;

  system("pause");
  return EXIT_SUCCESS;
}