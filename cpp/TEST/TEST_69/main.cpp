#include <iostream>
#include <memory>
#include <map>
#include <set>
#include <vector>

class A {
public:
void func() {
  std::shared_ptr<A> local_sp_a(this);
  // do something with local_sp_a
}

~A() {
  std::cout << "d" << std::endl;
}
};

int main() {
  std::vector<std::shared_ptr<std::string>> v;
  v.push_back(std::make_shared<std::string>("hallo"));

  for (std::shared_ptr<std::string> s : v) {   // <<== does not compile
    std::cout << s.use_count() << std::endl;
  }

  std::cout << v.front().use_count() << std::endl;

  // std::set<std::string> s;

  // std::cout << s.insert("NGPONG").second << std::endl;
  // std::cout << s.insert("NGPONG").second << std::endl;
  // std::cout << s.insert("NGPONG").second << std::endl;

  // std::multimap<int32_t, std::string> mm;
  // mm.insert({ -1, "-1" });
  // mm.insert({ 1, "1" });
  // mm.insert({ 0, "0" });
  // mm.insert({ 0, "0" });

  // for (auto&& [idx, str] : mm)
  //   std::cout << str << std::endl;

  // A* a = new A();
  // std::shared_ptr<A> sp_a(a);
  // // a->func();

  // std::shared_ptr<A> sp_b(a);

  // std::cout << sp_a.use_count() << std::endl;

  // sp_a->func();
  // sp_a->func();
  // sp_a->func();
  // sp_a becomes dangling.
}
