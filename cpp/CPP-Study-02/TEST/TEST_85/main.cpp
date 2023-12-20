#include <iostream>
#include <vector>

#include "kwmsgshare.pb.h"

int32_t main(void) {
  KWMsg::ReqQuickConfigBotarenaDefensiveTeam pkg;
  pkg.add_witch_id_list();
  pkg.add_witch_id_list();
  pkg.add_witch_id_list();
  pkg.add_witch_id_list();
  pkg.add_witch_id_list();

  std::cout << pkg.witch_id_list_size() << std::endl;

  std::cout << pkg.DebugString() << std::endl;

  return 0;
}
