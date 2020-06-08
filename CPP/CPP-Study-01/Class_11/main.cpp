#include <iostream>
using namespace std;

class person_base {
private:
  char m_gender = 'K';
};

class student : public person_base {
public:
  int m_age;
  char m_id;

public:
  void printp(void) {
    printf("%c\n", *(char *)this);
  }
};


int main(void) {

  /** 
   * 父类与子类的内存问题，即内存对齐
   * 父类中的对齐单位还是以子类为基础
   * 父类先初始化，其实就是把父类中的成员放在子类中，并且父类中的成员是先初始化
   */

  /** 
   * 继承方式
   * public
   * protected
   * private
   */

/* 
  0000000000000000
  0000000000000008
  0000000000000010
 */

/*   student *stu = nullptr;

  cout << sizeof(student) << endl;

  printf("%p\n", &stu->m_gender);
  printf("%p\n", &stu->m_age);
  printf("%p\n", &stu->m_id); */

  student stu;
  char *p_stu = (char *)&stu;

  cout << *p_stu << endl;

  printf("%p\n", p_stu);

  stu.printp();


  system("pause");
  return EXIT_SUCCESS;
}