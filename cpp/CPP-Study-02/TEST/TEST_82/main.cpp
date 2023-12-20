#include <iostream>
#include <vector>
#include <map>

std::vector<int32_t> v;

int32_t foo(int32_t cursor) {
  auto max   = static_cast<int32_t>(v.size());
  auto distn = cursor + 1 > max ? max - cursor : 1;
  auto upper = v.begin() + cursor;
  auto lower = upper + distn;

  std::cout << "==========================================" << std::endl;
  for (auto it = upper; it != lower; ++it) {
    std::cout << *it << std::endl;
  }
  std::cout << "==========================================" << std::endl;

  cursor += distn;

  if (cursor != max) {
    return cursor;
  } else {
    return -1;
  }
}

int32_t bar(int32_t cursor) {
  auto max   = static_cast<int32_t>(v.size());
  auto distn = cursor + 3 > max ? max - cursor : 3;
  auto upper = v.rbegin() + cursor;
  auto lower = upper + distn;

  std::cout << "==========================================" << std::endl;
  for (auto it = upper; it != lower; ++it) {
    std::cout << *it << std::endl;
  }
  std::cout << "==========================================" << std::endl;

  cursor += distn;

  if (cursor != max) {
    return cursor;
  } else {
    return -1;
  }
}

class BASE {
public:
  void foo() {
    bar();
  }

private:
  virtual void bar() = 0;
};

class HAHA : public BASE {
private:
  virtual void bar() {
    std::cout << "hello,world!" << std::endl;
  }
};

int32_t main(void) {
  // for (int i = 0; i < 20; ++i) {
  //   v.push_back(i);
  // }

  // int32_t cursor = 0;
  // bool flag = true;
  // while (true) {
  //   if (flag) {
  //     cursor = bar(cursor);
  //   }
  //   else {
  //     cursor = foo(cursor);
  //   }

  //   flag = !flag;

  //   if (cursor < 0)
  //     break;
  // }

  // std::map<int32_t, std::tuple<std::string, int32_t>> m;
  // m.emplace(0, std::make_tuple("hello,world!", 1024));
  // m.emplace(1, std::make_tuple("NGPONG", 256));
  // m.emplace(2, std::make_tuple("wupeng", 2333));

  // for (auto& [idx, tp] : m) {
  //   std::cout << "(" << idx << ") [" << std::get<0>(tp) << "], [" << std::get<1>(tp) << "]" << std::endl;
  // }

  // if (auto it = m.find(1); it != m.end()) {
  //   std::get<0>(it->second) = "shabiwupeng!";
  //   std::get<1>(it->second) = 555555;
  // }

  // for (auto& [idx, tp] : m) {
  //   std::cout << "(" << idx << ") [" << std::get<0>(tp) << "], [" << std::get<1>(tp) << "]" << std::endl;
  // }

  BASE* b = new HAHA;
  b->foo();

  return 0;
}
