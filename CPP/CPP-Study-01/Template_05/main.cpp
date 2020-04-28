#include <iostream>
using namespace std;

/* Template class */
template<class T>
class Person {
public:
  Person(T _age)
    : m_age(_age){};
public:
  /* Declare function members of the template class */
  void p_print(T _age_plus);
public:
  T m_age;
  char gender;
};
/* Function member that implement the template class */
template<class T>
void Person<T>::p_print(T _age_plus) {
  cout << this->m_age + _age_plus << endl;
}


/* Declare template function */
template<typename T>
void fun_test(T &per);

/* Implement template function */
template<typename T>
void fun_test(T &var) {
  var.p_print(0x100);
}

int main(void) {
  Person<int> per(0x200);
  fun_test(per);

  system("pause");
  return EXIT_SUCCESS;
}