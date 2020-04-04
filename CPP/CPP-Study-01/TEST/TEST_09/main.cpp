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

  /** Person Move constructor
   * When we add a customized move constructor, the default move assignment operator
   * is also set to be deleted, so we need to implement it separately, in contrast, the 
   * default copy assignment operator is not marked as deleted when we just add a customized copy constructor
   */
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
  Person per_temp = Person(128);
  return per_temp;
}

Person &&fun_test_02(void) {
  Person per_temp = Person(64);
  return move(per_temp);
}

Person &fun_test_03(Person &per) {
  return per;
}

Person &fun_test_04(Person &per) {
  per.m_age = 1024;
  return per;
}

Person &&fun_test_05(Person &per) {
  per.m_age = 256;
  return (Person &&)per;
}
#pragma endregion func_test

int main(void) {
#ifndef NOTE
  /** 1. ���������ʼ������ʱ���������Ż�����
   * Person per = Person(1024);
   * Person(1024) ��Ȼ��һ����ֵ���ʽ��Ҳ����˵��Ӧ������ (Person per = Person(1024)) ���ʽ����� Person ����ƶ����캯�������
   * Person per �ĳ�ʼ�����������Ǳ�����ʵ���ϻ�����Ż�Ϊ ==> Person per(1024)������ʵ�����ǲ�������ƶ����캯���ģ�ֻ�����Ĭ�ϵĹ��캯�������
   * ��ʼ������
   */
  Perosn per = Person(1024);

  /** 2. ����/�ƶ����� cpp11��
   * ��һЩ�ض�����£���ԭ����Ҫ����/�ƶ����캯����ʱ����ʹ�ã�������ԭ����ʱ�����Ĺ���ʱֱ�ӹ��쵽Ŀ���ڴ�
   * ������һ������������ֵΪ�����ͣ����ҵ��÷�ʹ����������ķ���ֵ������Ӧ���͵Ķ��󣬲��ң����ص��Ǿ����Զ������ڣ���volatile���Ǻ�����������catch��׽�Ķ�������ͳ��Ϊ������󣩣���������NROV
   * throw��һ�����������ڲ�try��������󣬿��ܷ�����������
   * catch��һ����throw��ͬ���͵�������󣬲���û�и���������󣨼������� catch �Ӿ�����ĸ��ƹ��캯�����������������ԭ����Ŀɹ۲���Ϊ��
   * ��������һ�������Ķ��󣬲����ж���ʹ�øú������صĶ�����й�����������ROV����C++17�𣬲�������ʱ����ʵ�ʻ���ǰ����ǿ���Ż�
   * �������ʽ�ͳ�����ʼ��ʱ��������
   * �ڲ�������ʱ����ʵ�ʻ�ʱ��������ĸ���/�ƶ�
   */

  /** 3. �ƶ�����Ϳ�������
   * ��ֵ�󶨵���ֵʱ�������ƶ�����������ƶ��������������������Ϊ��ֵ��˵�������ƶ���ɺ�Ӧ����Ҫ�����ͷţ���Ȼ����Ǵ�������Ͷ������Ĺ�����
   * �����Ǳ�����ֵ����Ϊһ�������Ĳ���������������Ҳ�������ֵ���õ�����£���ʱ��Ͳ����Զ�����������������ķ�ʽӦ�����������ƶ�����
   * ���ڶ�����ֵ�����������ƶ�����������Ӧ���ֶ������ 
   */

  /** 4. 
   * When we add a customized move constructor, the default move assignment operator
   * is also set to be deleted, so we need to implement it separately, in contrast, the 
   * default copy assignment operator is not marked as deleted when we just add a customized copy constructor
   */


#endif

  Person per = fun_test_01();

  Person per_new = fun_test_05(per);


  per_new = fun_test_05(per);


  system("pause");
  return EXIT_SUCCESS;
}