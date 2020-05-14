#include "gamecol.h"

/** 
 * @brief ��ӡӢ��ѡ�����
 * @param __data �洢Ӣ�۵�����
*/
void controller::print_hero_select(map<string, map<string, string>> &__data) {
  printf("Welcome to the power contest:\n");

  printf("Please choose your favorite hero:\n");

  char _buf[1024] = { 0 };
  printf("\t%s [%s]\n", __data["1"]["heroName"].c_str(), __data["1"]["heroInfo"].c_str());
  printf("\t%s [%s]\n", __data["2"]["heroName"].c_str(), __data["2"]["heroInfo"].c_str());
  printf("\t%s [%s]\n", __data["3"]["heroName"].c_str(), __data["3"]["heroInfo"].c_str());
}

/** 
 * @brief ��ȡӢ����Ϣ
 * @return ����ָ���ڶ��д洢Ӣ����Ϣ��ָ�룬��ָ������������� controller ������������ά��
*/
map<int, hero> *controller::init_hero_data() {
  map<int, map<string, string>> __hero_src;
  __fm.load_CSV_file("./hero.dt", __hero_src);

  for (map<int, map<string, string>>::const_iterator i = __hero_src.begin(); i != __hero_src.end(); ++i) {
    this->__heros->insert(make_pair(i->first, hero(stoi(i->second.at("heroId")), stoi(i->second.at("heroAtk")), stoi(i->second.at("heroDef")), stoi(i->second.at("heroHp")), i->second.at("heroInfo"), i->second.at("heroName"))));
  }

  return this->__heros;
}


controller::~controller() {
  if (this->__heros != nullptr) delete this->__heros;
}
controller::controller() {
  this->__heros = new map<int, hero>();
}