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
   * ������������ڴ����⣬���ڴ����
   * �����еĶ��뵥λ����������Ϊ����
   * �����ȳ�ʼ������ʵ���ǰѸ����еĳ�Ա���������У����Ҹ����еĳ�Ա���ȳ�ʼ��
   */

  /** 
   * �̳з�ʽ
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