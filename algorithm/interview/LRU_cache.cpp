#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 题目: LRU 缓存设计

class node {
public:
  string key;
  int value;
  node *next;
  node *pre;

  node(string _key, int _value) : key(_key), value(_value) {}
};

class LRU_cache {
  // 为了保证查询时拥有 O(1) 的时间复杂度，所以除了 head 本身能
  // 够代表一张链表外，hash 同样存储着这份数据
  unordered_map<string, node *> hash;
  int capacity;
  node *head = nullptr;
  node *tail = nullptr;

  void remove_and_insert(node *node) {
    if (node == head) {
      return;
    } else if (node == tail) {
      this->tail = node->pre;
      this->tail->next = nullptr;
    } else {
      node->pre->next = node->next;
      node->next->pre = node->pre;
    }

    node->next = head;
    node->pre = nullptr;
    head->pre = node;
    head = node;
  }

public:
  LRU_cache(int _capacity) : capacity(_capacity) {
    if (capacity == 0) throw range_error("Unable to initialize LRU_cache with capacity 0");
  }

  ~LRU_cache() {
    node *prev = head;
    node *next = prev->next;
    while (prev) {
      delete prev;
      prev = next;
      next = next->next;
    }
  }

  void put(string key, int value) {
    if (head == nullptr) {
      node *cur = new node(key, value);
      this->head = cur;
      this->tail = cur;
      this->hash[key] = cur;
      return;
    }

    auto finder = hash.find(key);
    if (finder == hash.end()) { // 缓存未命中
      // 首先需要判断目前 LRU_cache 的容量已经达到了最大阈值，如果是的话，则需要移
      // 除掉尾节点的元素，并将头节点设置为当前节点，相当于链表往后的偏移量 -1
      if (hash.size() == capacity) {
        hash.erase(finder);

        node *cur_node = finder->second;
        remove_and_insert(cur_node);
      } else {
        
        ++capacity;
      }
    } else {                    // 缓存命中 
      // 我们仅需要更改 map 中所获取到的元素即可，由于使用的是指针，所以 head 链表
      // 中维护的元素也同样会被更新掉
      node *cur_node = finder->second;
      cur_node->value = value;
    }
  }
};

int
main(void) {

  return EXIT_SUCCESS;
}
