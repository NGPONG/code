#include <iostream>
using namespace std;

class BASE {};

class DERIVED : public BASE {};

class OTHER {};

int main(void) {
  /* 1. ������������ת�� */
  int a = 0x400;
  long a_l = static_cast<long>(a);                        /* ���͵ķ�ǿ��ת�� */     
  int b = 364;                    
  char b_c = static_cast<char>(b);                        /* խ��ת�������ܻᶪʧ���� */

  /* 2. �޷�Ӧ�����Զ����������͵�ת�� */
  BASE base_01;
  DERIVED derived_01 = static_cast<BASE>(base_01);

  /* 3. ָ�����͵�ת�������ڳ��˷� void * ��ָ�����ͣ��Ի� Ŀ����������ʽ���� ֮���ָ�����ͽ���У�� */
  char *c_p = static_cast<char *>(&a);                    /* ʧ�ܣ�int * �� char * ��ƥ�� */
  void *p_01 = static_cast<void *>(&a);                   /* �ɹ���void * ָ�����Ͳ������� */
  int *p_02 = static_cast<int *>(p_01);                   /* �ɹ���void * ָ�����Ͳ������� */
  int *p_03 = static_cast<int *>(p_02);                   /* �ɹ���int * �� int * ƥ�� */

  /* 4. ��ָ��ľ�̬��λ */
  BASE base;
  DERIVED derived;
  OTHER other;
  BASE *p_base = static_cast<BASE *>(&derived);           /* ����ת�� */
  DERIVED *p_derived = static_cast<DERIVED *>(p_base);    /* ����ת�� */
  OTHER *p_other = static_cast<OTHER *>(p_base);          /* ʧ�ܣ�ת������䲻���ڼ̳���ϵ */

  system("pause");
  return EXIT_SUCCESS;
}