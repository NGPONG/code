#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

class Person {
public:
  Person(int _id)
    :m_id(_id) {
    cout << "PERSON CONSTRUCTOR" << endl;
  }
  Person(const Person &per) {
    this->m_id = per.m_id;
    cout << "PERSON COPY CONSTRUCTOR" << endl;
  }
  Person(Person &&per) {
    this->m_id = per.m_id;
    per.m_id = 0x0;
    cout << "PERSON MOVE CONSTRUCTOR" << endl;
  }
  ~Person() {
    cout << "PERSON DESTRUCTOR" << endl;
  }

public:
  int get_id() {
    return this->m_id;
  }

private:
  int m_id;
};

int main(void) {
  vector<Person> _container;
  for (size_t i = 0; i < 2; i++) {
    _container.push_back(Person(i + 1));
  }

  for (vector<Person>::iterator it = _container.begin(); it < _container.end(); it++) {
    cout << it->get_id() << endl;
  }

  system("pause");
  return EXIT_SUCCESS;
}