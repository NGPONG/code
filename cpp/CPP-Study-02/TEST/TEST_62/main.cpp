#include <iostream>
#include <memory>
#include <functional>
#include <vector>
#include <string>
#include <set>
#include <utility>

using EXECUTE_USER_DATA = void;
using EXECUTE_USER_DATA_PTR = std::shared_ptr<EXECUTE_USER_DATA>;

using EXECUTE_READY_FUNC = std::function<void(EXECUTE_USER_DATA_PTR)>;
using EXECUTE_READY_FUNC_PTR = std::shared_ptr<const EXECUTE_READY_FUNC>;

using EXECUTE_HANDLER_FUNC = std::function<bool(EXECUTE_USER_DATA_PTR)>;
using EXECUTE_HANDLER_FUNC_PTR = std::shared_ptr<const EXECUTE_HANDLER_FUNC>;

template<typename BaseType, typename... Items>
void make_dragon_list(BaseType* pBase, bool (BaseType::*executeFunc)(EXECUTE_USER_DATA_PTR), Items... maidens) {
  std::array<void (BaseType::*)(EXECUTE_USER_DATA_PTR), sizeof...(Items)> arr = { { maidens... } };

  EXECUTE_HANDLER_FUNC_PTR executeHandler = std::make_shared<EXECUTE_HANDLER_FUNC>(
    std::bind(executeFunc, pBase, std::placeholders::_1));

  executeHandler->operator()(nullptr);

  std::vector<EXECUTE_READY_FUNC_PTR> vv;
  for (auto a : arr) {
    EXECUTE_READY_FUNC_PTR executeReadyHandler = std::make_shared<EXECUTE_READY_FUNC>(
        std::bind(a, pBase, std::placeholders::_1));

    vv.push_back(executeReadyHandler);
  }

  for (auto h : vv) {
    h->operator()(nullptr);
  }

  // here be dragons
}

class BASE {
public:
  bool exeucte_func(EXECUTE_USER_DATA_PTR userData) {
    std::cout << "execute handler" << std::endl;
    return true;
  }

  void finished_func1(EXECUTE_USER_DATA_PTR userData) {
    std::cout << "execute ready 1" << std::endl;
    return;
  }

  void finished_func2(EXECUTE_USER_DATA_PTR userData) {
    std::cout << "execute ready 2" << std::endl;
    return;
  }

  void finished_func3(EXECUTE_USER_DATA_PTR userData) {
    std::cout << "execute ready 3" << std::endl;
    return;
  }

  void finished_func4(EXECUTE_USER_DATA_PTR userData) {
    std::cout << "execute ready 4" << std::endl;
    return;
  }

  void foo() {
    make_dragon_list(this, &BASE::exeucte_func); // , &BASE::finished_func1, &BASE::finished_func2, &BASE::finished_func3, &BASE::finished_func4
  }
};

void foo_01() {
  std::vector<int32_t> v1 = {1,2,3,4,5,6,7,8};
  auto v2 = std::move(v1);

  for (auto i : v1) 
    std::cout << i << std::endl;

  // std::set<std::string> s1 = { "A", "B","C","D","E","F", };

  // for (auto& str : s1)
  //   std::cout << str << std::endl;

  // std::set<std::string> s2;
  // for (auto& str : s1)
  //   s2.emplace(std::move(str));

  // for (auto& str : s1)
  //   std::cout << str << std::endl;

  // for (auto& str : s2)
  //   std::cout << str << std::endl;
}

int main(void) {
  foo_01();

  return EXIT_SUCCESS;
}
