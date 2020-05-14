#ifndef __MATCH_H__
#define __MATCH_H__

#include <vector>
#include <map>
#include <deque>
#include <time.h>
#include <numeric>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#include "person.hpp"

/**
 * @brief Random draw
 * @param __v Data-source
*/
void draw(vector<int> &__v);

/**
 * @brief Init data
 * @param __v Container for loading all member information
*/
void init(vector<Person> &__v);

/** 
 * @brief Get random numbers based on the scores of ten judges
 * @result random number
*/
int get_average();

/** 
 * @brief Start!
 * @param __src person data-source
 * @param __m 
 * @param __match_num The rount of game what we need
*/
void speech_contest(vector<Person> &__src, map<int, vector<Person>> &__m, int __match_num);

#endif /* end of include guard: __MATCH_H__ */
