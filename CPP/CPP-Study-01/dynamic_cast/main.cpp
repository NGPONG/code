#include <iostream>
using namespace std;

class BASE { virtual ~BASE() {}; };

class DERIVED : public BASE {};

class OTHER {};

int main(void) {
  /* �������͵�ת�� */
  int *p_a = new int(0x400);
  long *p_b = dynamic_cast<long *>(p_a);                                          /* ʧ�ܣ���̬����ת����֧�ֻ����������ͺͻ�����������ָ����ת�� */


  /* ���ָ��/���õ�ת�� */
  BASE *base_non_polymorphism = new BASE;
  DERIVED *der_non_polymorphism = dynamic_cast<DERIVED *>(base_non_polymorphism); /* ʧ�ܣ�expression �޷����ɶ�̬������������ת��ʧ�ܣ�������һ����ָ�� */

  BASE *base_polymorphism = new DERIVED;
  DERIVED *der_polymorphism = dynamic_cast<DERIVED *>(base_polymorphism);         /* �ɹ���expression ���Թ��ɶ�̬ */
  BASE *base_more = dynamic_cast<BASE *>(der_polymorphism);                       /* �ɹ�����������ת�� */

  OTHER *other = dynamic_cast<BASE *>(der_polymorphism);                          /* ʧ�ܣ�OTHER �� expression ����������ͬһ���̳���ϵ���� */

  

  system("pause");
  return EXIT_SUCCESS;
}