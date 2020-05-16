#include "gamecol.h"

/** 
 * @brief ��ӡ��Ϣ
 * @param __mes ��Ϣ
*/
void controller::print(const char *__mes) {
  printf(__mes);
}

/** 
 * @brief ��ӡӢ��ѡ�����
 * @param __data �洢Ӣ�۵�����
*/
void controller::get_heros() {
  if (this->__heros == nullptr) init_hero_data();

  for (map<int, hero>::const_iterator i = this->__heros->begin(); i != this->__heros->end(); ++i) {
    printf("  %d: %s [%s]\n", i->first, i->second.hero_name.c_str(), i->second.hero_info.c_str());
  }
}

/** 
 * @brief ��ȡӢ����Ϣ
 * @return ����ָ���ڶ��д洢Ӣ����Ϣ��ָ�룬��ָ������������� controller ������������ά��
*/
map<int, hero> *controller::init_hero_data() {
  if (this->__heros != nullptr) delete this->__heros;

  this->__heros = new map<int, hero>();

  map<int, map<string, string>> __hero_src;
  __fm.load_CSV_file("./hero.dt", __hero_src);

  for (map<int, map<string, string>>::const_iterator i = __hero_src.begin(); i != __hero_src.end(); ++i) {
    this->__heros->insert(make_pair(i->first, hero(stoi(i->second.at("heroId")), stoi(i->second.at("heroAtk")), stoi(i->second.at("heroDef")), stoi(i->second.at("heroHp")), i->second.at("heroInfo"), i->second.at("heroName"))));
  }

  return this->__heros;
}

/** 
 * @brief ѡ��Ӣ��
*/
void controller::select_heros() {
  while (true) {
    int selected_val;
    scanf("%d\n", &selected_val);

    map<int, hero>::const_iterator result = this->__heros->find(selected_val);
    if (result != this->__heros->end()) {
      this->game_player.selected_hero = result->second;
      cout << "The hero you choose is [" << this->game_player.selected_hero.hero_name << "]" << endl;
      break;
    }

    cout << "��Чѡ������������" << endl;
  }
}


controller::~controller() {
  if (this->__heros != nullptr) delete this->__heros;
}
controller::controller() {}