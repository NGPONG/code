#ifndef __HERO_H__
#define __HERO_H__

#include <string>
using namespace std;

#include "monster.h"

class hero {
public:
  hero();
  hero(int _id, int _atk, int _def, int _hp, string _info, string _name);

public:
  void attack(monster *_monster);

public:
  int hero_id;
  int hero_atk;
  int hero_def;
  int hero_hp;
  string hero_info;
  string hero_name;
};


#endif /* end of include guard: __HERO_H__ */
