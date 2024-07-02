#include "test.h"

std::unordered_set<std::string> foo() {
  const std::string& str1 = "1";
  const std::string& str2 = "2";
  const std::string& str3 = "3";
  const std::string& str4 = "1";

  std::unordered_set<std::string> us;
  us.emplace(str1);
  us.emplace(str2);
  us.emplace(str3);
  us.emplace(str4);

  return us;
}
