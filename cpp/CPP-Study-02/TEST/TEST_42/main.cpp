#include <tuple>
#include <utility>
#include <iostream>

namespace detail {
  template<std::size_t... indices>
  decltype(auto) build_string(const char *str, std::index_sequence<indices...>) {
    return std::make_tuple(str[indices]...);
  }
}  // namespace detail

template<std::size_t N>
constexpr decltype(auto) make_string(const char (&str)[N]) {
  return detail::build_string(str, std::make_index_sequence<N>());
}

int main(void) {
  auto HelloStrObject = make_string(s);

  return EXIT_SUCCESS;
}
