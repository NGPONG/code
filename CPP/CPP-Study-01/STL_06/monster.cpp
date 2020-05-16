#include "monster.h"

monster::monster(int _id, string _name, int _atk, int _def, int _hp)
  : monster_id(_id), monster_name(_name), monster_atk(_atk), monster_def(_def), monster_hp(_hp){};

void monster::attack(hero *_hero) {
  if (this->is_frozen) {
    cout << "Monster [" << this->monster_name << "] was frozen and can't move for the current round." << endl;
    return;
  }

  /* Calculate the damage to the hero. */
  int damage = this->monster_atk - _hero->hero_def > 0 ? this->monster_atk - _hero->hero_def : 1;
  /* The hero was done damage. */
  _hero->hero_hp -= damage;

  cout << "Monster [" << this->monster_name << "] attacked the hero, inflicting " << damage << " points of damage." << endl;
}