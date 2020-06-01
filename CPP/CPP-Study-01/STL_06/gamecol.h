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
  /**
   * @brief ��ȡ������Ϣ
   * @return ����ָ���ڶ��д洢������Ϣ��ָ�룬��ָ������������� controller ������������ά��
  */
  map<int, weapon *> *init_weapon_data();
  /**
   * @brief ��ӡ����ѡ�����
  */
  void get_weapons();
  /**
   * @brief ѡ������
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
