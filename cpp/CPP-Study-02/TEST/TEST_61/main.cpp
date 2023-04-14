#include <iostream>
#include <ranges>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <random>
#include <sstream>
#include <fstream>

#include <benchmark/benchmark.h>

class BotArenaRanking {
public:
  static const std::string &GetKey(const std::tuple<std::string, int64_t> &t) {
    return std::get<0>(t);
  }
  static int64_t GetScore(const std::tuple<std::string, int64_t> &t) {
    return std::get<1>(t);
  }

public:
  BotArenaRanking() 
  {
    // v.reserve(100000);
  }

public:
  typedef std::vector<std::tuple<std::string, int64_t>>::iterator iterator;
  typedef std::vector<std::tuple<std::string, int64_t>>::reverse_iterator reverse_iterator;
  typedef std::vector<std::tuple<std::string, int64_t>>::const_iterator const_iterator;
  typedef std::vector<std::tuple<std::string, int64_t>>::const_reverse_iterator const_reverse_iterator;

public:
  void test(const std::string &key, const int64_t score)
  {
    auto it = std::lower_bound(v.begin(), v.end(), std::make_tuple(key, score), [](const auto &lhs, const auto &rhs) {
      if (GetScore(lhs) > GetScore(rhs))
        return true;

      if (GetScore(lhs) == GetScore(rhs))
        return GetKey(lhs) > GetKey(rhs);

      return false;
    });
    
    if (it == v.begin())
      std::cout << "Find key v.begin()." << std::endl;
    else if (it == v.end())
      std::cout << "Find key v.end()." << std::endl;
    else
      std::cout << "Find key [" << GetKey(*it) << ", score." << GetScore(*it) << "]." << std::endl;
  }

  void insert(const std::string &key, const int64_t score) {
    if (auto search = find(key); search != end()) {
      v.erase(search);
    }

    if (auto search = m.find(key); search != m.end()) {
      m.erase(key);
    }

    if (!score)
      return;

    m.insert({ key, score });

    auto it = std::lower_bound(v.begin(), v.end(), std::make_tuple(key, score), [](const auto &lhs, const auto &rhs) {
      if (GetScore(lhs) > GetScore(rhs))
        return true;

      if (GetScore(lhs) == GetScore(rhs))
        return GetKey(lhs) > GetKey(rhs);

      return false;
    });
    v.insert(it, { key, score });
  }

  int32_t rank(const std::string &key) {
    int32_t rank = -1;

    if (auto search = find(key); search != end()) {
      rank = std::distance(v.begin(), search) + 1;
    }

    return rank;
  }

  const std::tuple<std::string, int64_t> &at(std::size_t idx) const {
    return v.at(idx);
  }

  void clear() {
    v.clear();
    m.clear();
  }

  std::int32_t size() {
    return v.size();
  }

  BotArenaRanking::iterator find(const std::string &key) {
    if (!m.count(key))
      return v.end();

    int64_t score = m[key];

    auto it = std::lower_bound(v.begin(), v.end(), std::make_tuple(key, score), [](const auto &lhs, const auto &rhs) {
      if (GetScore(lhs) > GetScore(rhs))
        return true;

      if (GetScore(lhs) == GetScore(rhs))
        return GetKey(lhs) > GetKey(rhs);

      return false;
    });

    if (it == v.end()) {
      return it;
    }

    if (score != GetScore(*it) || key != GetKey(*it)) {
      return v.end();
    }

    return it;
  }

  BotArenaRanking::reverse_iterator rfind(const std::string &key) {
    if (!m.count(key))
      return v.rend();

    int64_t score = m[key];

    auto it = std::lower_bound(v.rbegin(), v.rend(), std::make_tuple(key, score), [](const auto &lhs, const auto &rhs) {
      if (GetScore(lhs) < GetScore(rhs))
        return true;

      if (GetScore(lhs) == GetScore(rhs))
        return GetKey(lhs) < GetKey(rhs);

      return false;
    });

    if (it == v.rend()) {
      return it;
    }

    if (score != GetScore(*it) || key != GetKey(*it)) {
      return v.rend();
    }

    return it;
  }

  BotArenaRanking::iterator begin() {
    return v.begin();
  }
  BotArenaRanking::iterator end() {
    return v.end();
  }
  BotArenaRanking::const_iterator begin() const {
    return v.cbegin();
  }
  BotArenaRanking::const_iterator end() const {
    return v.cend();
  }
  BotArenaRanking::const_iterator cbegin() const {
    return v.cbegin();
  }
  BotArenaRanking::const_iterator cend() const {
    return v.cend();
  }

  BotArenaRanking::reverse_iterator rbegin() {
    return v.rbegin();
  }
  BotArenaRanking::reverse_iterator rend() {
    return v.rend();
  }
  BotArenaRanking::const_reverse_iterator rbegin() const {
    return v.crbegin();
  }
  BotArenaRanking::const_reverse_iterator rend() const {
    return v.crend();
  }
  BotArenaRanking::const_reverse_iterator crbegin() const {
    return v.crbegin();
  }
  BotArenaRanking::const_reverse_iterator crend() const {
    return v.crend();
  }

private:
  std::vector<std::tuple<std::string, int64_t>> v;
  std::map<std::string, int64_t> m;
};

namespace uuid {
    // static std::random_device              rd;
    static std::default_random_engine         rd;  
    static std::mt19937                    gen(rd());
    static std::uniform_int_distribution<> dis(0, 15);
    static std::uniform_int_distribution<> dis2(8, 11);

    std::string generate_uuid_v4() {
        std::stringstream ss;
        int i;
        ss << std::hex;
        for (i = 0; i < 8; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 4; i++) {
            ss << dis(gen);
        }
        ss << "-4";
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        ss << dis2(gen);
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 12; i++) {
            ss << dis(gen);
        };
        return ss.str();
    }
}

void foo_01(benchmark::State& state) {
  for (auto _: state) {
    std::default_random_engine dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,100000);
    
    BotArenaRanking ranking;

    ranking.insert(uuid::generate_uuid_v4(), dist6(rng));
  }
}
BENCHMARK(foo_01);

BENCHMARK_MAIN();
