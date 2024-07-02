#include "gamecol.h"

using namespace std;

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
  if (this->c_heros == nullptr) init_hero_data();

  for (map<int, hero>::const_iterator i = this->c_heros->begin(); i != this->c_heros->end(); ++i) {
    printf("  %d: %s [%s]\n", i->first, i->second.hero_name.c_str(), i->second.hero_info.c_str());
  }
}

/**
 * @brief 获取英雄信息
 * @return 返回指向在堆中存储英雄信息的指针，该指针的生命周期由 controller 的析构来进行维护
*/
map<int, hero> *controller::init_hero_data() {
  if (this->c_heros != nullptr) delete this->c_heros;

  this->c_heros = new map<int, hero>();

  map<int, map<string, string>> __hero_src;
  c_fm.load_CSV_file("./hero.dt", __hero_src);

  for (map<int, map<string, string>>::const_iterator i = __hero_src.begin(); i != __hero_src.end(); ++i) {
    this->c_heros->insert(make_pair(i->first, hero(stoi(i->second.at("heroId")), stoi(i->second.at("heroAtk")), stoi(i->second.at("heroDef")), stoi(i->second.at("heroHp")), i->second.at("heroInfo"), i->second.at("heroName"))));
  }

  return this->c_heros;
}

/**
 * @brief 选择英雄
*/
void controller::select_heros() {
  while (true) {
    int selected_val;
    do {
      selected_val = ((int)_getch() - 48);
    } while (selected_val < 0 || selected_val > 3);

    map<int, hero>::const_iterator result = this->c_heros->find(selected_val);
    if (result != this->c_heros->end()) {
      this->game_player.selected_hero = &result->second;
      cout << "The hero you choose is [" << this->game_player.selected_hero->hero_name << "]" << endl
           << endl;
      break;
    }

    cout << "无效选择，请重新输入" << endl;
  }
}

/**
 * @brief 获取武器信息
 * @return 返回指向在堆中存储武器信息的指针，该指针的生命周期由 controller 的析构来进行维护
*/
map<int, weapon *> *controller::init_weapon_data() {
  if (this->c_weapons != nullptr) delete this->c_weapons;

  this->c_weapons = new map<int, weapon *>();

  map<int, map<string, string>> __weapon_src;
  c_fm.load_CSV_file("./weapons.dt", __weapon_src);

  for (map<int, map<string, string>>::const_iterator i = __weapon_src.begin(); i != __weapon_src.end(); ++i) {
    weapon *w_temp = nullptr;
    if (i->second.at("weaponName") == "Pocket-knife") {
      w_temp = new knife(stoi(i->second.at("weaponId")), i->second.at("weaponName"), stoi(i->second.at("weaponAtk")), stoi(i->second.at("weaponCritPlus")), stoi(i->second.at("weaponCritRate")), stoi(i->second.at("weaponSuckPlus")), stoi(i->second.at("weaponSuckRate")), stoi(i->second.at("weaponFrozenRate")));
    } else if (i->second.at("weaponName") == "Machete") {
      w_temp = new broad_sword(stoi(i->second.at("weaponId")), i->second.at("weaponName"), stoi(i->second.at("weaponAtk")), stoi(i->second.at("weaponCritPlus")), stoi(i->second.at("weaponCritRate")), stoi(i->second.at("weaponSuckPlus")), stoi(i->second.at("weaponSuckRate")), stoi(i->second.at("weaponFrozenRate")));
    } else if (i->second.at("weaponName") == "Dragon-slayer's-knife") {
      w_temp = new dragon_sword(stoi(i->second.at("weaponId")), i->second.at("weaponName"), stoi(i->second.at("weaponAtk")), stoi(i->second.at("weaponCritPlus")), stoi(i->second.at("weaponCritRate")), stoi(i->second.at("weaponSuckPlus")), stoi(i->second.at("weaponSuckRate")), stoi(i->second.at("weaponFrozenRate")));
    }
    /* printf("create [%p]\n", w_temp); */
    this->c_weapons->insert(make_pair(i->first, w_temp));
  }

  return this->c_weapons;
}

/**
 * @brief 打印武器选择界面
*/
void controller::get_weapons() {
  if (this->c_weapons == nullptr) init_weapon_data();

  for (map<int, weapon *>::const_iterator i = this->c_weapons->begin(); i != this->c_weapons->end(); ++i) {
    printf("  %d: %s ATK [%d] SUK [%d] CRT [%d]\n", i->first, i->second->weapon_name.c_str(), i->second->weapon_atk, i->second->weapon_suck_rate, i->second->weapon_crit_rate);
  }
}

/**
 * @brief 选择武器
*/
void controller::select_weapons() {
  while (true) {
    int selected_val;
    do {
      selected_val = ((int)_getch() - 48);
    } while (selected_val < 0 || selected_val > 3);

    map<int, weapon *>::const_iterator result = this->c_weapons->find(selected_val);
    if (result != this->c_weapons->end()) {
      this->game_player.selected_weapon = result->second;
      cout << "The weapon you choose is [" << this->game_player.selected_weapon->weapon_name << "]" << endl
           << endl;
      break;
    }

    cout << "无效选择，请重新输入" << endl;
  }
}


controller::~controller() {
  if (this->c_heros != nullptr) delete this->c_heros;
  if (this->c_weapons != nullptr) {
    for (map<int, weapon *>::const_iterator i = this->c_weapons->begin(); i != this->c_weapons->end(); ++i) {
      /* printf("delete [%p]\n", i->second); */
      delete i->second;
    }
    delete this->c_weapons;
  }
}
controller::controller() {}
