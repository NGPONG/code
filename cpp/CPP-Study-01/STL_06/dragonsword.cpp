#include "dragonsword.h"

/** 
 * @brief ��ȡ������
*/
int dragon_sword::get_base_damage() {
  return weapon::weapon_atk;
};

/** 
 * @brief ��������
*/
int dragon_sword::get_crit() {
  if (weapon::is_trigger(weapon::weapon_crit_rate)) {
    return weapon::weapon_atk * weapon::weapon_crit_plus;
  } else {
    return 0;
  }
};

/** 
 * @brief ������Ѫ
*/
int dragon_sword::get_suck_blood() {
  if (weapon::is_trigger(weapon::weapon_suck_rate)) {
    return weapon::weapon_atk * weapon::weapon_suck_plus;
  } else {
    return 0;
  }
};

/** 
 * @brief ��������
*/
int dragon_sword::get_frozen() {
  if (weapon::is_trigger(weapon::weapon_frozen_rate)) {
    return 1;
  } else {
    return 0;
  }
};

dragon_sword::~dragon_sword(){
  /* cout << "DRAGON_SWORD" << endl; */
};
dragon_sword::dragon_sword(int _id, string _name, int _atk, int _crit_plus, int _crit_rate, int _suck_plus, int _suck_rate, int _frozen_rate)
  : weapon(_id, _name, _atk, _crit_plus, _crit_rate, _suck_plus, _suck_rate, _frozen_rate){};