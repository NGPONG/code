#ifndef __MONSTER_H__
#define __MONSTER_H__

#include <iostream>
#include "hero.h"

class hero;
class monster {
public:
  monster(int _id,string _name,int _atk,int _def,int _hp);
  void attack(hero *_hero);

public:
  int monster_id;
  string monster_name;
  int monster_atk;
  int monster_def;
  int monster_hp;
  bool is_frozen = false;
};

#endif /* end of include guard: __MONSTER_H__ */
