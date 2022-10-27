#include <tuple>
#include <utility>
#include <iostream>

#include <fmt/compile.h>

class BASE {
private:
  template<typename... T>
  static constexpr bool is_false_v = false;

  static constexpr bool select(const std::string_view s) {
    constexpr std::size_t size = 3;

    constexpr auto axis = []() {
      return std::array<std::string_view, 3>{
        "hello,world!",
        "ngpong",
        "what the funck"
      };
    }();

    for (std::size_t i = 0; i < size; i++)
      if (axis[i] == s)
        return true;
    return false;
  }

  static constexpr std::string_view split(std::string_view ctx) {
    // remove prefix
    for (size_t idx = 1; idx <= ctx.size(); ++idx) {
      if (ctx[idx - 1] == ' ') {
        ctx.remove_prefix(idx);
        break;
      }
    }

    // remove suffix
    for (size_t j = 0; j < ctx.size(); ++j) {
      if (ctx[j] == '(') {
        return { ctx.begin(), ctx.begin() + j };
      }
    }

    // invalid ctx
    return {};
  }

public:
  template<typename X>
  auto foo(const std::string resourceId, const std::string val, X x) {
    constexpr std::string_view name = split(x());

    if constexpr (name == "") {
      // function to call implement by child class.
      return std::make_tuple(0x0, "abcdefg");
    } else if constexpr (name == "main") {
      return std::make_tuple(1, "NGPONG, TEST!");
    } else {
      static_assert(is_false_v<X>, "hello,world!");
    }
  }
};

int main() {
  // constexpr std::string_view sv = "hello,world";
  // constexpr size_t n = sv.size();
  // constexpr auto indices = std::make_index_sequence<n>();

  // [&]<std::size_t... I>(std::index_sequence<I...>) {
  //   static constexpr char text[]{ (char)sv.at(I)..., 0 };
  //   compile_time_display<text>();  // the char array will convert to FS
  // }(indices);

  // BASE b;
  // if (const auto &[err, my_str] = b.foo("hahahah", "hahahah", [] { return std::string_view(__PRETTY_FUNCTION__); }); err == 1) {
  //   std::cout << my_str << std::endl;
  // }
}
