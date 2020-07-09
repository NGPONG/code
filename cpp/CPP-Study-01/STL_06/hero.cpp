#include "hero.h"

hero::hero(){};

hero::hero(int _id, int _atk, int _def, int _hp, std::string _info, std::string _name)
  : hero_id(_id), hero_atk(_atk), hero_def(_def), hero_hp(_hp), hero_info(_info), hero_name(_name) {}

