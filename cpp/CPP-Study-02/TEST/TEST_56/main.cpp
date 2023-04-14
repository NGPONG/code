#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <tuple>
#include <algorithm>
#include <memory>
#include <limits.h>
#include <utility>

class BotArenaRanking {
public:
  static int64_t GetRankingScore(int32_t point)
  {
      if (!point)
          return point;
  
      int64_t top32 = static_cast<int64_t>(point) << 32;
      int64_t low32 = INT_MAX - 10;
  
      return top32 + low32;
  }
  
  static int32_t GetPointFromScore(int64_t score)
  {
      return score >> 32;
  }

public:
  void push_back(const std::string& key, const int32_t point) 
  {
    if (auto search = find(key); search != end()) 
    {
      v.erase(search);
    }

    if (auto search = m.find(key); search != m.end()) {
      m.erase(key);
    }

    int64_t score = GetRankingScore(point);

    m.insert({ key, score});
    v.push_back({ key, score });

    std::sort(v.begin(), v.end(), [] (auto& lhs, auto& rhs) {
      if (std::get<1>(lhs) > std::get<1>(rhs)) 
        return true;

      if (std::get<1>(lhs) == std::get<1>(rhs))
        return std::get<0>(lhs) > std::get<0>(rhs);

      return false;
    });
  }

  int32_t rank(const std::string& key)
  {
    int32_t rank = -1;

    if (auto search = find(key); search != end()) 
    {
      rank = std::distance(v.begin(), search) + 1;
    }
    
    return rank;
  }

  std::vector<std::tuple<std::string, int64_t>>::iterator find(const std::string& key) {
    if (!m.count(key))
      return v.end();
    
    int64_t score = m[key];
    
    auto it = std::lower_bound(v.begin(), v.end(), std::make_tuple(key, score), [] (auto& lhs, auto& rhs) {
      if (std::get<1>(lhs) > std::get<1>(rhs)) 
        return true;

      if (std::get<1>(lhs) == std::get<1>(rhs))
        return std::get<0>(lhs) > std::get<0>(rhs);

      return false;
    });

    if (it == v.end())
    {
      return it;
    }

    if (score < std::get<1>(*it) || key != std::get<0>(*it))
    {
      return v.end();
    }

    return it;
  }

  std::vector<std::tuple<std::string, int64_t>>::iterator begin() { return v.begin(); }
  std::vector<std::tuple<std::string, int64_t>>::iterator end() { return v.end(); }
  std::vector<std::tuple<std::string, int64_t>>::const_iterator begin() const { return v.cbegin(); }
  std::vector<std::tuple<std::string, int64_t>>::const_iterator end() const { return v.cend(); }

private:
  std::vector<std::tuple<std::string, int64_t>> v;
  std::map<std::string, int64_t> m;
};

int main(void) {
  BotArenaRanking ranking;
  ranking.push_back("NGPONG", 200);
  ranking.push_back("a", 300);
  ranking.push_back("Nb", 200);
  ranking.push_back("c", 10);
  ranking.push_back("d", 650);
  ranking.push_back("e", 1234);
  ranking.push_back("f", 200);
  ranking.push_back("g", 10);
  ranking.push_back("g", 0);
  ranking.push_back("g", 0);
  ranking.push_back("g", 0);
  ranking.push_back("g", 0);
  ranking.push_back("e", 0);
  ranking.push_back("qwdqwd", 0);
  ranking.push_back("zczxc", 0);


  for (auto& [key, score] : std::as_const(ranking)) 
  {
    std::cout << "key [" << key << "], point [" << BotArenaRanking::GetPointFromScore(score) << "]." << std::endl;
  }

  if (auto search = ranking.find("hello,world!"); search == ranking.end()) {
    std::cout << "ops" << std::endl;
  }
  else {
    std::cout << std::get<0>(*search) << std::get<1>(*search) << std::endl;
  }

  if (auto search = ranking.find("f"); search == ranking.end()) {
    std::cout << "ops" << std::endl;
  }
  else {
    std::cout << std::get<0>(*search) << std::get<1>(*search) << std::endl;
  }

  if (auto search = ranking.find("NGPONG"); search == ranking.end()) {
    std::cout << "ops" << std::endl;
  }
  else {
    std::cout << std::get<0>(*search) << std::get<1>(*search) << std::endl;
  }

  // std::sort(v.begin(), v.end(), [] (auto& lhs, auto& rhs) {
  //   if (std::get<1>(lhs) > std::get<1>(rhs))
  //     return true;

  //   if (std::get<1>(lhs) == std::get<1>(rhs))
  //     return std::get<0>(lhs) > std::get<0>(rhs);

  //   return false;
  // });

  // for (auto &[key, score] : v) {
  //   std::cout << "key [" << key << "], score [" << score << "]." << std::endl;
  // }

  // auto it = std::lower_bound(v.begin(), v.end(), std::make_tuple("Nb", 200), [] (auto& lhs, auto& rhs) {
  //   if (std::get<1>(lhs) > std::get<1>(rhs))
  //     return true;

  //   if (std::get<1>(lhs) == std::get<1>(rhs))
  //     return std::get<0>(lhs) > std::get<0>(rhs);

  //   return false;
  // });

  // if (it == v.end())
  // {
  //   std::cout << "ops" << std::endl;
  //   return EXIT_SUCCESS;
  // }

  // if (200 < std::get<1>(*it) || "Nb" != std::get<0>(*it))
  // {
  //   std::cout << "ops" << std::endl;
  //   return EXIT_SUCCESS;
  // }

  // std::cout << "success" << std::endl;
  // std::cout << std::get<0>(*it) << ":" << std::get<1>(*it) << std::endl;

  return EXIT_SUCCESS;
}
