#include "match.h"

/**
 * @brief Random draw
 * @param __v Data-source
*/
void draw(vector<Person> &__v) {
  random_shuffle(__v.begin(), __v.end());
};

/**
 * @brief Init data
 * @param __v Container for loading all member information
*/
void init(vector<Person> &__v) {
  string name_seed = "ABCDEFGHIJKLMNOPQRSTUVWX";
  for (size_t i = 0; i < 24; ++i) {
    string name = "Player [";
    (name += name_seed[i]) += ']';
    __v.push_back(Person(name, i + 1, 0));
  }
};

/** 
 * @brief Get random numbers based on the scores of ten judges
 * @result random number
*/
int get_average() {
  deque<int> __d_temp;
  for (int i = 0; i < 10; i++) {
    __d_temp.push_back(rand() % 41 + 60); /* 60 ~ 100 */
  }

  sort(__d_temp.begin(), __d_temp.end());

  __d_temp.pop_back();
  __d_temp.pop_front();

  return accumulate(__d_temp.begin(), __d_temp.end(), 0) / __d_temp.size();
}

/** 
 * @brief Start!
 * @param __src person data-source
 * @param __m 
 * @param __match_num The rount of game what we need
*/
void speech_contest(vector<Person> &__src, map<int, vector<Person>> &__m, int __match_num) {
  if (__match_num == 0)
    return;

  int c_end = 1;
  int c_start = 0;
  int a_start = 0;
  static int __rount_count = 1;

  /* Random draw */
  draw(__src);

  /* Track of who is promoted in the current round */
  vector<Person> current_adv;
  current_adv.resize(__src.size() / 2);

  for (vector<Person>::iterator i = __src.begin(); i != __src.end(); ++i) {
    i->m_score[__rount_count - 1] = get_average();

    if (c_end % 6 == 0) {
      sort(__src.begin() + c_start, __src.begin() + c_end, person_sort<int, Person>(__rount_count));
      copy(__src.begin() + c_start, __src.begin() + c_start + 3, current_adv.begin() + a_start);

      a_start += 3;
      c_start += 6;
    }
    ++c_end;
  }

  __m.insert(make_pair(__rount_count, current_adv));

  /* To be the next round */
  ++__rount_count;
  speech_contest(current_adv, __m, --__match_num);
}
