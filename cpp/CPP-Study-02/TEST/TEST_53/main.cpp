#include <iostream>
#include <tuple>
#include <vector>

using DataList = std::tuple<std::string, int32_t, int32_t>;

int main(void) {
  std::vector<DataList> v = { 
    { "Item_001", 10, 1 },
    { "Item_002", 30, 2 },
    { "Item_006", 40, 2 },
    { "Item_001", 20, 1 },
    { "Gold", 500, 3 },
    { "Item_001", 60, 3 },
    { "Item_001", 60, 3 },
    { "EXP", 3000, 2 },
    { "Item_004", 70, 2 },
    { "Gold", 300, 3 },
    { "Item_001", 30, 2 },
    { "Item_001", 60, 1 },
  };

  std::vector<DataList> vv;

  std::cout << &vv << std::endl;
  std::cout << &*vv.begin() << std::endl;
  std::cout << &*vv.end() << std::endl;

  std::cout << &vv << std::endl;
  std::cout << &*vv.begin() << std::endl;
  std::cout << &*vv.end() << std::endl;

  auto cmp = [] (const DataList& lhs, const DataList& rhs) {
    const std::string& lhsstr = std::get<0>(lhs);
    const int32_t lhsint = std::get<2>(lhs);

    return std::tie(lhsstr, lhsint) < std::tie(std::get<0>(rhs), std::get<2>(rhs));
  };

  std::sort(v.begin(), v.end(), cmp);
  for (std::vector<DataList>::iterator first = v.begin(), last = {}; last != v.end();) {
    auto result = *first;

    last = std::upper_bound(first++, v.end(), result, cmp);
    for (; first != last; ++first) {
        std::get<1>(result) = std::get<1>(result) + std::get<1>(*first);
    }

    vv.push_back(std::move(result));
  }

  // Item [EXP], count [3000], flag [2].
  // Item [Gold], count [500], flag [3].
  // Item [Gold], count [300], flag [3].
  // Item [Item_001], count [10], flag [1].
  // Item [Item_001], count [20], flag [1].
  // Item [Item_001], count [60], flag [1].
  // Item [Item_001], count [30], flag [2].
  // Item [Item_001], count [60], flag [3].
  // Item [Item_001], count [60], flag [3].
  // Item [Item_002], count [30], flag [2].
  // Item [Item_004], count [70], flag [2].
  // Item [Item_006], count [40], flag [2].

  for (const auto& item : v) 
    std::cout << "Item [" << std::get<0>(item) << "], count [" << std::get<1>(item) << "], flag [" << std::get<2>(item) << "]." << std::endl;

  std::cout << "--------------------------" << std::endl;

  for (const auto& item : vv) 
    std::cout << "Item [" << std::get<0>(item) << "], count [" << std::get<1>(item) << "], flag [" << std::get<2>(item) << "]." << std::endl;

  // std::vector<std::tuple<std::string, int32_t, int32_t>> v2;

  return EXIT_SUCCESS;
}
