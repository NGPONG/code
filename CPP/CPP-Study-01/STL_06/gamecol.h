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
   * @brief ��ӡ��Ϣ
   * @param __mes ��Ϣ
  */
  void print(const char *__mes);
  /** 
   * @brief ��ӡӢ��ѡ�����
  */
  void get_heros();
  /** 
   * @brief ѡ��Ӣ��
  */
  void select_heros();
  /** 
   * @brief ��ȡӢ����Ϣ
   * @return ����ָ���ڶ��д洢Ӣ����Ϣ��ָ�룬��ָ������������� controller ������������ά��
  */
  map<int, hero> *init_hero_data();

public:
  Player game_player;

private:
  FileManager __fm;
  map<int, hero> *__heros = nullptr;
};

#endif /* end of include guard: __GAME_CONTROLLER_H */
