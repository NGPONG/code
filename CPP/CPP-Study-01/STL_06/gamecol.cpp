#include "gamecol.h"

/** 
 * @brief 打印信息
 * @param __mes 信息
*/
void controller::print(const char *__mes) {
  printf(__mes);
}

/** 
 * @brief 打印英雄选择界面
 * @param __data 存储英雄的数据
*/
void controller::get_heros() {
  if (this->__heros == nullptr) init_hero_data();

  for (map<int, hero>::const_iterator i = this->__heros->begin(); i != this->__heros->end(); ++i) {
    printf("  %d: %s [%s]\n", i->first, i->second.hero_name.c_str(), i->second.hero_info.c_str());
  }
}

/** 
 * @brief 获取英雄信息
 * @return 返回指向在堆中存储英雄信息的指针，该指针的生命周期由 controller 的析构来进行维护
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
 * @brief 选择英雄
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

    cout << "无效选择，请重新输入" << endl;
  }
}


controller::~controller() {
  if (this->__heros != nullptr) delete this->__heros;
}
controller::controller() {}