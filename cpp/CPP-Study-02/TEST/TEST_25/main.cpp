#include <iostream>

#include "kwmsgshare.pb.h"
#include "kwmsgbase.pb.h"
#include "kwmsgdefine.pb.h"

int main(void) {
  KWMsg::NGPONGTestPkg pkg;
  pkg.set_data_1("HELLO");
  pkg.set_data_1("WORLD");

  for (int i = 1; i <= 10; ++i) {
    auto item = pkg.add_list();
    item->mutable_player_id()->set_index(i);
    item->mutable_player_id()->set_svrid(1024);

    item->set_score(i + 10000);
  }

  KWMsg::Ident id;
  id.set_index(2);
  id.set_svrid(1024);

  auto it = std::find_if(pkg.mutable_list()->begin(), pkg.mutable_list()->end(), [&] (const KWMsg::NGPONGTestPkg_NGPONGTestSubPkg& item)
  {
    return item.player_id().index() == id.index() && item.player_id().svrid() == id.svrid();
  });
  if (it == pkg.mutable_list()->end()) {
    std::cout << "NOT FOUND" << std::endl;
    return EXIT_FAILURE;
  }

  it->set_score(10241024);
  std::cout << it->ShortDebugString() << std::endl;

  for (const auto &item : pkg.list())
  {
    std::cout << item.ShortDebugString() << std::endl;
  }

  

  return EXIT_SUCCESS;
}
