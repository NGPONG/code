#ifndef __BROAD_SWORD_H__
#define __BROAD_SWORD_H__

#include "weapon.h"

class broad_sword : public weapon {
public:
  broad_sword(int _id, string _name, int _atk, int _crit_plus, int _crit_rate, int _suck_plus, int _suck_rate, int _frozen_rate);
  ~broad_sword() override;

public:
 /** 
  * @brief »ñÈ¡¹¥»÷Á¦
  */
  int get_base_damage() override;

  /** 
   * @brief ´¥·¢±©»÷
  */
  int get_crit() override;

  /** 
   * @brief ´¥·¢ÎüÑª
  */
  int get_suck_blood() override;

  /** 
   * @brief ´¥·¢±ù¶³
  */
  int get_frozen() override;
};

#endif /* end of include guard: __BROAD_SWORD_H__ */
