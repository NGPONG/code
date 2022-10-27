#include <iostream>

#define GB_WRAP_CONSTCTX [] { return std::string_view(__PRETTY_FUNCTION__); }

constexpr std::string_view SplitSuffix(const std::string_view ctx, const char split) {
  for (size_t j = 0; j < ctx.size(); ++j) {
    if (ctx[j] == split) {
      return { ctx.begin(), ctx.begin() + j };
    }
  }

  // invalid ctx
  return {};
}

constexpr std::string_view SplitPrefix(const std::string_view ctx, const char split) {
  for (int32_t j = ctx.size() - 1; j >= 0; --j) {
    if (ctx[j] == split) {
      return { ctx.begin() + j + 1, ctx.end() };
    }
  }

  // invalid ctx
  return {};
}

template <typename... T>
constexpr bool always_false_v = false;

template<typename X>
void test(X x) {
  // if constexpr (SplitSuffix(x(), ':') != "BASE")
  // {
  //   static_assert(always_false_v<X>, "");
  // }
  // if constexpr (SplitSuffix(x(), ':') != "BASE")
  // {
  //   static_assert(always_false_v<X>, "");
  // }

  std::cout << x() << std::endl;

  std::cout << SplitSuffix(x(), '(') << std::endl;
  std::cout << SplitSuffix(SplitSuffix(x(), '('), ':') << std::endl;
  std::cout << SplitPrefix(SplitSuffix(x(), '('), ':') << std::endl;
}

class BASE {
public:
  bool foo(int i, std::string &str, std::string str2, const std::string &str3) {
    test(GB_WRAP_CONSTCTX);
    return true;
  };
};

int main() {
  std::string str;

  BASE b;
  b.foo(1, str, str, str);
}
