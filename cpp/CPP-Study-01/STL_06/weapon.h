#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>
#include <iostream>

using namespace std;

class weapon {
public:
  weapon(int _id, string _name, int _atk, int _crit_plus, int _crit_rate, int _suck_plus, int _suck_rate, int _frozen_rate);
  virtual ~weapon() {
    /* cout << "WEAPON DESTRUCTOR" << endl; */
  }

public:
  virtual int get_base_damage() = 0;
	virtual int get_crit() = 0;
	virtual int get_suck_blood() = 0;
	virtual int get_frozen() = 0;
	bool is_trigger(int rate);

public:
  int weapon_id;
  string weapon_name;
  int weapon_atk;
  int weapon_crit_plus;
  int weapon_crit_rate;
  int weapon_suck_plus;
  int weapon_suck_rate;
  int weapon_frozen_rate;
};

#endif /* end of include guard: __WEAPON_H__ */
