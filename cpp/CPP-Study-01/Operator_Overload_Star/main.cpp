#include <iostream>
using namespace std;

class Person {
public:
  Person(int age, char *name) {
    this->m_age = age;
    this->m_name = name;
  }

public:
  void Print() {
    cout << "Person age = " << this->m_age << endl;
    cout << "Person name = " << this->m_name << endl;
  }

private:
  int m_age;
  char *m_name;
};

class SmartPointer {
public:
  SmartPointer(Person *ptr) {
    this->m_ptr = ptr;
  };
  ~SmartPointer() {
    delete this->m_ptr;
    this->m_ptr = nullptr;
  }

public:
  /** '*' assginment operator
   * 1. ����� '*' ��һ��һԪ��������������ڸ��������ڲ�����������غ��������β� ('*' �����ɵ���������ʽ�������ҵĵ�һ��������Ϊ��ǰ �������� ��ʵ��)��
   */
  Person &operator*() {
    return *this->m_ptr;
  }

  /** '->' assignment operator
   * 1. ����� '->' ��һ��һԪ��������������ڸ��������ڲ�����������غ��������β� ('->' �����ɵ���������ʽ�������ҵĵ�һ��������Ϊ��ǰ �������� ��ʵ��)
   * 2. '->' ��Ȼ��һ��һԪ����������ȴ��֧�ֵ���ʹ�ã���������������ı��ʽ��֮��������Ҫ�н��Ŷ�����һ���ĵ��ò��ܹ�ͨ������
   * 3. '->' �������������ֻ�ܹ���Ϊһ����Ա����������
   * 4. '->' �ķ���ֵ����Ҫô����һ����ָ�룬Ҫô�������û�ֵ������ͬ������������� -> �Ķ��������䷵��ֵ�����ƻ��� '->' �޷�����ʹ�õ����ԣ���ζ������ʹ�� '->' �����ɵı��ʽ��ӳ�䵽��Ӧ�ĺ���������ϲ��ҷ�����Ӧ��ֵ�����ǻ�Ҫ�н���һ�� '->' �ĵ��ã���ζ��ʵ��Ҫ���õı��ʽ��Ҫ������ '->' ��������ʹ�� '->->' ���Ǳ����������ʡȥ��һ�� '->'
   */
  Person *operator->() {
    return *this->m_ptr;
  }

public:
  Person *m_ptr;
};

int main(void) {
  SmartPointer sp(new Person(1024, (char *)"Person"));
  (*sp).Print();
  sp->Print();

  Person &per_ref = *sp;
  per_ref.Print();

  /* faild */
  /* Person *per = sp->; */

  system("pause");
  return EXIT_SUCCESS;
}