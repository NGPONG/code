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
   * @brief ��ȡӢ����Ϣ
   * @return ����ָ���ڶ��д洢Ӣ����Ϣ��ָ�룬��ָ������������� controller ������������ά��
  */
  map<int, hero> *init_hero_data();
  /** 
   * @brief ��ӡӢ��ѡ�����
   * @param __data �洢Ӣ�۵�����
  */
  void print_hero_select(map<string, map<string, string>> &__data);

private:
  FileManager __fm;
  map<int, hero> *__heros = nullptr;
};

#endif /* end of include guard: __GAME_CONTROLLER_H */
