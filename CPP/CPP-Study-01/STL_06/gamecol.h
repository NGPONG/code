#ifndef __GAME_CONTROLLER_H
#define __GAME_CONTROLLER_H

#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include "filemanager.h"
#include "hero.h"

using namespace std;

class controller {
public:
  controller();
  ~controller();
  
public:
  /** 
   * @brief 获取英雄信息
   * @return 返回指向在堆中存储英雄信息的指针，该指针的生命周期由 controller 的析构来进行维护
  */
  map<int, hero> *init_hero_data();
  /** 
   * @brief 打印英雄选择界面
   * @param __data 存储英雄的数据
  */
  void print_hero_select(map<string, map<string, string>> &__data);

private:
  FileManager __fm;
  map<int, hero> *__heros = nullptr;
};

#endif /* end of include guard: __GAME_CONTROLLER_H */
