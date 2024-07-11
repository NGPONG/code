#include "common.hpp"

class LRUCache {
  using List = std::list<std::pair<int, int>>;

private:
  int capacity;
  List datas;
  std::unordered_map<int, List::iterator> hash;

public:
  LRUCache(int _capacity) {
    capacity = _capacity;
  }

  int get(int key) {
    if (auto it = hash.find(key); it != hash.end()) {
      datas.splice(datas.begin(), datas, it->second);
      return it->second->second;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (auto it = hash.find(key); it != hash.end()) {
      it->second->second = value;
      datas.splice(datas.begin(), datas, it->second);
    } else {
      datas.emplace_front(key, value);
      hash.emplace(key, datas.begin());

      if (datas.size() > capacity) {
        hash.erase(datas.back().first);
        datas.pop_back();
      }
    }
  }
};

void solution() {
  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  std::cout << cache.get(1) << std::endl;
  cache.put(3, 3);
  std::cout << cache.get(2) << std::endl;
  cache.put(4, 4);
  std::cout << cache.get(1) << std::endl;
  std::cout << cache.get(3) << std::endl;
  std::cout << cache.get(4) << std::endl;
}

int main(int argc, char *argv[]) {
  solution();

  return 0;
}
