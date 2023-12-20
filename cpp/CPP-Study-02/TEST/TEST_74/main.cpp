#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>

template<class... Ts>
struct overloaded : Ts... { using Ts::operator()...; };

template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

template<class>
inline constexpr bool always_false_v = false;

int main(void) {
  std::variant<int32_t, std::string> v;
  v = 1;
  // v = "hello,world!";

  std::get<int>(v) += 1;


 std::visit(overloaded
 {
 [] (const int32_t& arg)
 {
    std::cout << "int32_t" << std::endl;
 },
 [] (auto arg) 
 {
    using T = std::decay_t<decltype(arg)>;
    static_assert(always_false_v<T>, "ngpong");
 },
 [] (const std::string& arg)
 {
    std::cout << "string" << std::endl;
 },
 }, v);

  return EXIT_SUCCESS;
}
