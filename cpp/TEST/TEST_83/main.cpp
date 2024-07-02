#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <variant>
#include <set>
#include <string>
#include <sstream>
#include <numeric>
#include <ranges>

template <typename... T>
constexpr static bool always_false_v = false;

template<class... Args>
struct overloaded : Args... { using Args::operator()...; };

template<class... Args>
overloaded(Args...) -> overloaded<Args...>;

struct InputProxy {
public:
    using T = std::variant<int32_t, double, std::string>;

public:
    template<typename U>
    InputProxy(const U& u) : val(u) {}

    T& get_val() 
    {
        return val;
    }

    template<typename U>
    operator U()
    {
        return std::get<typename std::decay_t<U>>(val);
    }

    template<typename U>
    InputProxy& operator=(const U& u)
    {
        val = u;
        return *this;
    }

private:
    T val = {};
};

template<typename U>
U operator+(const U& u, InputProxy& val)
{
    U nu = u;
    std::visit([&] (auto& arg) { nu += arg; }, val.get_val());
    return nu;
}
template<typename U>
U operator+(InputProxy& val, const U& u)
{
    U nu = u;
    std::visit([&] (auto& arg) { nu += arg; }, val.get_val());
    return nu;
}
template<typename U>
U operator-(U& u, InputProxy& val)
{
    U nu = u;
    std::visit([&] (auto& arg) { nu -= arg; }, val.get_val());
    return nu;
}
template<typename U>
U operator-(InputProxy& val, const U& u)
{
    U nu = u;
    std::visit([&] (auto& arg) { nu -= arg; }, val.get_val());
    return nu;
}
template<typename U>
U operator*(U& u, InputProxy& val)
{
    U nu = u;
    std::visit([&] (auto& arg) { nu *= arg; }, val.get_val());
    return nu;
}
template<typename U>
U operator*(InputProxy& val, const U& u)
{
    U nu = u;
    std::visit([&] (auto& arg) { nu *= arg; }, val.get_val());
    return nu;
}
template<typename U>
U operator/(U& u, InputProxy& val)
{
    U nu = u;
    std::visit([&] (auto& arg) { nu *= arg; }, val.get_val());
    return nu;
}
template<typename U>
U operator/(InputProxy& val, const U& u)
{
    U nu = u;
    std::visit([&] (auto& arg) { nu /= arg; }, val.get_val());
    return nu;
}
template<typename U>
InputProxy& operator+=(InputProxy& val, const U& u)
{
    std::visit([&] (auto& arg) { arg += u; }, val.get_val());
    return val;
}
template<typename U>
InputProxy& operator-=(InputProxy& val, const U& u)
{
    std::visit([&] (auto& arg) { arg -= u; }, val.get_val());
    return val;
}
template<typename U>
InputProxy& operator*=(InputProxy& val, const U& u)
{
    std::visit([&] (auto& arg) { arg *= u; }, val.get_val());
    return val;
}
template<typename U>
InputProxy& operator/=(InputProxy& val, const U& u)
{
    std::visit([&] (auto& arg) { arg /= u; }, val.get_val());
    return val;
}

InputProxy bar(const InputProxy& p)
{
  InputProxy pp = p;

  std::string str = "hjahaha";

  // pp += str;

  // pp += std::string("zxczxczxc");

  // std::string haha = std::string("NGPONG!!") + pp;

  // std::cout << haha << std::endl;

  // pp += "asdasd";

  // 1 + pp;

  // 1 - pp;

  // pp - 1;

  return pp;
}

inline auto Split2Vec(const std::string& data, const std::string& delimeter = ",") -> std::vector<std::string>
{
    if (data.empty() || delimeter.empty())
        return {};

    auto view = data | std::views::split(delimeter.front())
        | std::views::transform([](auto&& ele) { return std::string_view(&*ele.begin(), std::ranges::distance(ele)); });

    return { view.begin(), view.end() };
};

template <typename Range, typename Value = typename Range::value_type>
std::string Join(const Range& range, const char* delimiter = ",") 
{
    std::ostringstream os;

    auto b = begin(range), e = end(range);

    if (b != e) {
        std::copy(b, std::prev(e), std::ostream_iterator<Value>(os, delimiter));
        b = std::prev(e);
    }
    if (b != e) {
        os << *b;
    }

    return os.str();
}

int32_t main(void) {
  // std::string str = "asdasd";

  // std::string a = bar("asdasd");

  // std::cout << a << std::endl;

  // std::variant<int32_t, double, std::string> v = "hello,world!";

  // using T = std::string;

  // T val = "hahahah";

  // std::visit(overloaded
  // {
  //     [&] (std::string k)
  //     {
  //     std::cout << k << std::endl;
  //     }
  //     // [&] (int32_t k)
  //     // {
  //     // std::cout << k << std::endl;
  //     // }
  // }, v);

  // std::visit([&] (auto& arg) {
  //   arg += "hahahah";
  // }, v);

  // std::visit([&] (auto&& arg){
  //   std::cout << arg << std::endl;
  // }, v);

  // int32_t val = 1.7;

  // std::cout << val << std::endl;

  // std::set<std::string> s = {"123","ok","","asdasd",""};

  std::vector<std::string> s = {"", "sdasd","","", "okkkk"};

  // std::ostringstream imploded;
  // copy(s.begin(), s.end(), std::ostream_iterator<std::string>(imploded, ","));

  std::string str = ",hello,what,the,funck,,ok,";//Join(s, ",");

  std::cout << str << std::endl;

  std::vector<std::string> v = Split2Vec(str);

  for (auto& ele : v) {
    std::cout << ele << std::endl;
  }

  return 0;
}
