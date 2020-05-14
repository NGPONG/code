#include <iostream>
#include <time.h>
#include "match.h"

void foo(void) {
  vector<Person> pers;
  init(pers);

  /**
   * key: Round of the game
   * val: People promoted in the current round
  */
  map<int, vector<Person>> math_info;

  speech_contest(pers, math_info, 3);

  for (map<int, vector<Person>>::const_iterator i = math_info.begin(); i != math_info.end(); ++i) {
    cout << "The [" << i->first << "] loop result is:" << endl;
    for (vector<Person>::const_iterator j = i->second.begin(); j != i->second.end(); ++j) {
      cout << "\t name (" << j->m_name << "), score (" << j->m_score[0] << "," << j->m_score[1] << "," << j->m_score[2] << ")" << endl;
    }
  }
}

int main(void) {
  /* Set a random-seed */
  srand((unsigned int)time(NULL));

  foo();

  system("pause");
  return EXIT_SUCCESS;
}