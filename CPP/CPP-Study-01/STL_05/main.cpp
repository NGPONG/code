#include <iostream>
using namespace std;

#include <map>
#include <deque>
#include <time.h>
#include <string>
#include <numeric>
#include <string.h>
#include <vector>
#include <algorithm>
#include <functional>

static int _ROUNT_COUNT = 1;

class Person {
public:
  Person() {}

  Person(string _name, int _id, int _score)
    : m_name(_name), m_id(_id) {
    memset(this->m_score, 0, sizeof(int) * 3);
  };
  Person(const Person &per) {
    memcpy(this->m_score, per.m_score, sizeof(int) * 3);
    this->m_name = per.m_name;
    this->m_id = per.m_id;
  }

public:
  void set_person_score(int _score, int _index) {
    this->m_score[_index] = _score;
  }

public:
  string m_name;
  int m_score[3]; /* Three rounds of scoring */
  int m_id;
};

bool per_sort(Person &_left, Person &_right) {
  return _left.m_score[_ROUNT_COUNT - 1] > _right.m_score[_ROUNT_COUNT - 1];
}

/**
 * @brief Random draw
 * @param __v Data-source
*/
void draw(vector<int> &__v) {
  random_shuffle(__v.begin(), __v.end());
}

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
}

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

void speech_contest(vector<Person> &__src, map<int, vector<Person>> &__m, int __match_num) {
  if (__match_num == 0)
    return;

  random_shuffle(__src.begin(), __src.end());

  int c_end = 1;
  int c_start = 0;
  int a_start = 0;

  /* Track of who is promoted in the current round */
  vector<Person> current_adv;
  current_adv.resize(__src.size() / 2);

  for (vector<Person>::iterator i = __src.begin(); i != __src.end(); ++i) {
    i->m_score[_ROUNT_COUNT - 1] = get_average();

    if (c_end % 6 == 0) {
      sort(__src.begin() + c_start, __src.begin() + c_end, per_sort);
      copy(__src.begin() + c_start, __src.begin() + c_start + 3, current_adv.begin() + a_start);

      a_start += 3;
      c_start += 6;
    }
    ++c_end;
  }

  __m.insert(make_pair(_ROUNT_COUNT, current_adv));

  /* To be the next round */
  ++_ROUNT_COUNT;
  speech_contest(current_adv, __m, --__match_num);
}

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
    cout << "第 [" << i->first << "] 轮的结果为：" << endl;
    for (vector<Person>::const_iterator j = i->second.begin(); j != i->second.end(); ++j) {
      cout << "\t name = [" << j->m_name << "] score = [" << j->m_score[0] << "," << j->m_score[1] << "," << j->m_score[2] << "]" << endl;
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