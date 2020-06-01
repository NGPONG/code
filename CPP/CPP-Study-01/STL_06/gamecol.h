#ifndef __GAME_CONTROLLER_H
#define __GAME_CONTROLLER_H

#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

#include "filemanager.h"
#include "hero.h"
#include "player.h"
#include "weapon.h"
#include "knife.h"
#include "dragonsword.h"
#include "broadsword.h"
#include "monster.h"

using namespace std;

class controller {
public:
  controller();
  ~controller();

public:
  /**
   * @brief 打印信息
   * @param __mes 信息
  */
  void print(const char *__mes);
  /**
   * @brief 打印英雄选择界面
  */
  void get_heros();
  /**
   * @brief 选择英雄
  */
  void select_heros();
  /**
   * @brief 获取英雄信息
   * @return 返回指向在堆中存储英雄信息的指针，该指针的生命周期由 controller 的析构来进行维护
  */
  map<int, hero> *init_hero_data();
  /**
   * @brief 获取武器信息
   * @return 返回指向在堆中存储武器信息的指针，该指针的生命周期由 controller 的析构来进行维护
  */
  map<int, weapon *> *init_weapon_data();
  /**
   * @brief 打印武器选择界面
  */
  void get_weapons();
  /**
   * @brief 选择武器
  */
  void select_weapons();

public:
  Player game_player;

private:
  FileManager c_fm;
  map<int, hero> *c_heros = nullptr;
  map<int, weapon *> *c_weapons = nullptr;
};

#endif /* end of include guard: __GAME_CONTROLLER_H */
