#include "weapon.h"

weapon::weapon(int _id, string _name, int _atk, int _crit_plus, int _crit_rate, int _suck_plus, int _suck_rate, int _frozen_rate)
  : weapon_id(_id), weapon_name(_name), weapon_atk(_atk), weapon_crit_plus(_crit_plus), weapon_crit_rate(_crit_rate), weapon_suck_plus(_suck_plus), weapon_suck_rate(_suck_rate), weapon_frozen_rate(_frozen_rate){};

bool weapon::is_trigger(int rate) {
  if ((rand() % 100 + 1) < rate) {
    return true;
  } else {
    return false;
  }
}