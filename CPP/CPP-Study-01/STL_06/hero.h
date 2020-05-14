#ifndef __HERO_H__
#define __HERO_H__

#include <string>

class hero {
public:
  hero(int _id, int _atk, int _def, int _hp, std::string _info, std::string _name)
    : hero_id(_id), hero_atk(_atk), hero_def(_def), hero_hp(_hp), hero_info(_info), hero_name(_name) {}
  hero(const hero &__h) {
    this->hero_id = __h.hero_id;
    this->hero_atk = __h.hero_atk;
    this->hero_def = __h.hero_def;
    this->hero_hp = __h.hero_hp;
    this->hero_info.assign(__h.hero_info);
    this->hero_name.assign(__h.hero_name);
  }
  hero(hero &&__h) {
    this->hero_id = __h.hero_id;
    this->hero_atk = __h.hero_atk;
    this->hero_def = __h.hero_def;
    this->hero_hp = __h.hero_hp;
    this->hero_info.assign(__h.hero_info);
    this->hero_name.assign(__h.hero_name);

    __h.hero_id = 0x0;
    __h.hero_atk = 0x0;
    __h.hero_def = 0x0;
    __h.hero_hp = 0x0;
    __h.hero_name.assign(1, 0);
    __h.hero_info.assign(1, 0);
  }

public:
  int hero_id;
  int hero_atk;
  int hero_def;
  int hero_hp;
  std::string hero_info;
  std::string hero_name;
};


#endif /* end of include guard: __HERO_H__ */
