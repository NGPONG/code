#include <iostream>
using namespace std;

#include <map>
#include <string>

#define DEVELOP_DEPATMENT  1 /* 研发部门 */
#define FINACIAL_DEPATMENT 2 /* 财务部门 */
#define SALE_DEPATMENT     3 /* 销售部门 */

class Person {
public:
  Person(){
    cout << "PERSON DEFAULT CONSTRUCTOR";
  };
public:
  string m_name;
  int m_age;
};

void foo() {
  multimap<int, Person> __m;
  __m.insert(make_pair(DEVELOP_DEPATMENT, Person("wwwwpppppp", 23)));
  __m.insert(make_pair(DEVELOP_DEPATMENT, Person("NGPONG", 0x400)));
  __m.insert(make_pair(DEVELOP_DEPATMENT, Person("wupeng", 1)));

  __m.insert(make_pair(FINACIAL_DEPATMENT, Person("choushabi", 3)));
  __m.insert(make_pair(FINACIAL_DEPATMENT, Person("wdnmd", 5)));

  __m.insert(make_pair(SALE_DEPATMENT, Person("hahahha", 7)));

  multimap<int, Person>::iterator develop_it = __m.find(DEVELOP_DEPATMENT);
  size_t develop_count = __m.count(DEVELOP_DEPATMENT);
  for (size_t i = 0; i < develop_count; ++i, ++develop_it) {
    cout << "employee_name [" << develop_it->second.m_name << "], employee_age [" << develop_it->second.m_age << "]" << endl;
  }

  multimap<int, Person>::iterator finacial_it = __m.find(FINACIAL_DEPATMENT);
  size_t finacial_count = __m.count(FINACIAL_DEPATMENT);
  for (size_t i = 0; i < finacial_count; ++i, ++finacial_it) {
    cout << "employee_name [" << finacial_it->second.m_name << "], employee_age [" << finacial_it->second.m_age << "]" << endl;
  }
}

int main(void) {
  foo();

  system("pause");
  return EXIT_SUCCESS;
}