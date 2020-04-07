#include <iostream>
using namespace std;

#define NOTE


class Person {
public:
  /* Person constructor */
  Person(int age)
      : m_age(age) {
    cout << "Person constructor" << endl;
  };

  /* Perosn copy constructor */
  Person(Person &per) {
    this->m_age = per.m_age;
    cout << "Person copy constructor" << endl;
  };

  /* Person Move constructor */
  Person(Person &&per) {
    this->m_age = per.m_age;
    per.m_age = 0x0;
    cout << "Person move constructor" << endl;
  };

  /* Person destructor */
  ~Person() {
    this->m_age = 0x0;
    cout << "Person destructor" << endl;
  };

  /* Person move assignmenet operator */
  Person &operator=(Person &&per) {
    this->m_age = per.m_age;
    per.m_age = 0x0;
    cout << "Person move assignment operator" << endl;
  
    return *this;
  };

  /* Person copy assignment operator */
  Person &operator=(Person &per) {
    this->m_age = per.m_age;
    cout << "Person copy assignment operator" << endl;

    return *this;
  }

public:
  int m_age;
};

#pragma region func_test
Person fun_test_01(void) {
  Person per_temp = Person(0x80);
  return per_temp;
}

Person &&fun_test_02(void) {
  Person per_temp = Person(0x40);
  return move(per_temp);
}

Person &fun_test_03(Person &per) {
  return per;
}

Person &fun_test_04(Person &per) {
  per.m_age = 0x400;
  return per;
}

Person &&fun_test_05(Person &per) {
  per.m_age = 0x100;
  return (Person &&) per;
}

Person &fun_test_07(Person &per) {
  per = Person(0x400);
  return per;
}

Person fun_test_08(void) {
  Person per(0x400);
  return per;
}

Person &fun_test_09(void) {
  Person per(0x100);
  return per;
}

int &fun_test_10(void) {
  int a = 0x400;
  return a;
}

Person fun_test_11(Person per) {
  Person per_temp = per;
  return per_temp;
}
#pragma endregion func_test

int main(void) {
#ifndef NOTE
  /** 1. 匿名对象初始化对象时编译器的优化工作
   * Person per = Person(1024);
   * Person(1024) 虽然是一个右值表达式，也就是说理应这整段 (Person per = Person(1024)) 表达式会调用 Person 类的移动构造函数以完成
   * Person per 的初始化工作，但是编译器实质上会把它优化为 ==> Person per(1024)，所以实际上是不会调用移动构造函数的，只会调用默认的构造函数以完成
   * 初始化工作
   */
  Perosn per = Person(1024);

  /** 2. 拷贝/移动消除 cpp11起
   * 在一些特定情况下，在原本需要复制/移动构造函数的时并不使用，而是在原构临时变量的构造时直接构造到目标内存
   * 当存在一个函数，返回值为类类型，并且调用方使用这个函数的返回值构造相应类型的对象，并且，返回的是具有自动生存期，非volatile，非函数参数，非catch捕捉的对象（以下统称为这类对象），这个情况是NROV
   * throw了一个不超过最内层try的这类对象，可能发生复制消除
   * catch了一个与throw相同类型的这类对象，并且没有复用这个对象（即跳过该 catch 子句参数的复制构造函数和析构函数以外的原因更改可观察行为）
   * 当返回了一个匿名的对象，并且有对象使用该函数返回的对象进行构造这个情况是ROV，在C++17起，不发生临时变量实质化的前提下强制优化
   * 常量表达式和常量初始化时（待定）
   * 在不发生临时变量实质化时多次连环的复制/移动
   */

  /** 3. 移动语义和拷贝语义
   * 左值绑定到右值时，调用移动构造或者是移动语义操作符函数，当作为右值来说，它在移动完成后应该是要进行释放，当然这个是大多数类型都会做的工作，
   * 而考虑本身右值是作为一个函数的参数传入进来，并且参数是左值引用的情况下，这时候就不会自动调用析构，更理想的方式应该是我们在移动函数
   * 中在对于右值进行了数据移动操作后，我们应当手动的清空 
   */

  /** 4. 
   * When we add a customized move constructor, the default move assignment operator
   * is also set to be deleted, so we need to implement it separately, in contrast, the 
   * default copy assignment operator is not marked as deleted when we just add a customized copy constructor
   */


  /** new
   * 
   */


#endif

  int a = 10;
  int &a_ref = a;

  system("pause");
  return EXIT_SUCCESS;
}