#ifndef __GAME_CONTROLLER_H
#define __GAME_CONTROLLER_H

#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include "filemanager.h"
#include "hero.h"
#include "player.h"

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

public:
  Player game_player;

private:
  FileManager __fm;
  map<int, hero> *__heros = nullptr;
};

#endif /* end of include guard: __GAME_CONTROLLER_H */
