#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "hero.h"
#include "weapon.h"

class Player {
public: 
  Player() {

  }

public:
  const hero *selected_hero;
  const weapon *selected_weapon;
};

#endif /* end of include guard: __PLAYER_H__ */
