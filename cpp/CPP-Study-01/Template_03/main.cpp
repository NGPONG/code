#include <iostream>
using namespace std;

template<class T1, class T2>
class Person {
public:
  Person(T1 _name, T2 _age)
      : m_name(_name), m_age(_age){
    cout << "Person constructor" << endl;
  };

public:
  T1 m_name;
  T2 m_age;
};

template<typename T1, typename T2>
void fun_test(Person<T1, T2> per) {
  cout << "common function recalled" << endl;
}

template<>
void fun_test(Person<char *, int> per) {
  cout << "customitzed function recalled" << endl;
}

int main(void) {
  fun_test<char *, int>(Person<char *, int>((char *)"Hello,World", 0x400));

  system("pause");
  return EXIT_SUCCESS;
}