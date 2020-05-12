#include <time.h>
#include "test.h"

void foo(void) {
  vector<Person> _pers;
  for (size_t i = 65; i < 70; ++i) {
    _pers.push_back(Person(i, new select_sort()));
  }

  srand(time(NULL)); /* set the random seed */
  int judges_id = 1;
  for (vector<Person>::iterator _it = _pers.begin(); _it != _pers.end(); ++_it) {
    cout << "The judges [" << judges_id++ << "] start scoring" << endl;
    for (size_t i = 0; i < 10; ++i) {
      /* To get the random integer of [a, b], use (rand ()% (b-a + 1)) + a; */
      _it->m_scores.push_back((rand() % (99 - 40 + 1)) + 40);
    }
  }

  for (vector<Person>::iterator _it = _pers.begin(); _it != _pers.end(); ++_it) {
    cout << "PERSON [" << _it->get_name() << "] : ";
    for (deque<int>::iterator _it_per = _it->m_scores.begin(); _it_per != _it->m_scores.end(); ++_it_per) {
      cout << *_it_per << " ";
    }
    cout << "  " << "| average = " << _it->get_average() << endl;
  }
}

int main(void) {
  foo();

  system("pause");
  return EXIT_SUCCESS;
}