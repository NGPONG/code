#include <iostream>
#include <unordered_map>

#include "magic_enum.hpp"

#define KW_ENUM_RANGE_MIN 0
#define KW_ENUM_RANGE_MAX 256

template <typename T>
inline constexpr bool KWIsEnum = std::is_enum_v<T> && std::is_same_v<T, std::decay_t<T>>;

template <typename E, E V>
constexpr auto PrettyName()
{
    std::string_view name{__PRETTY_FUNCTION__, sizeof(__PRETTY_FUNCTION__) - 2};
    name.remove_prefix(name.find_last_of(" ") + 1);
    if (name.front() == '(') name.remove_prefix(name.size());
    return name;
}

template <typename E, E V>
constexpr bool IsValidEnum()
{
    return !PrettyName<E, V>().empty();
}

template <int... Seq>
constexpr auto MakeIntegerSequence(std::integer_sequence<int, Seq...>)
{
    return std::integer_sequence<int, (Seq)...>();
}

constexpr auto NormalIntegerSequence = MakeIntegerSequence(std::make_integer_sequence<int, KW_ENUM_RANGE_MAX>());

template <typename E, int... Seq>
constexpr size_t GetEnumSize(std::integer_sequence<int, Seq...>)
{
    constexpr std::array<bool, sizeof...(Seq)> valid{IsValidEnum<E, static_cast<E>(Seq)>()...};
    constexpr std::size_t count = [](decltype((valid)) v) constexpr noexcept->std::size_t
    {
        auto cnt = std::size_t{0};
        for (auto b : v) if (b) ++cnt;
        return cnt;
    }(valid);
    return count;
}

template <typename E, int... Seq>
constexpr auto GetAllValidValues(std::integer_sequence<int, Seq...>)
{
    constexpr std::size_t count = sizeof...(Seq);
    constexpr std::array<bool, count> valid{IsValidEnum<E, static_cast<E>(Seq)>()...};
    constexpr std::array<int, count> seq{Seq...};

    std::array<E, GetEnumSize<E>(NormalIntegerSequence)> values{};
    for (std::size_t i = 0, v = 0; i < count; ++i) 
        if (valid[i]) 
            values[v++] = static_cast<E>(seq[i]);

    return values;
}

template <typename E, int... Seq>
constexpr auto GetAllValidNames(std::integer_sequence<int, Seq...>)
{
    constexpr std::array<std::string_view, sizeof...(Seq)> names{PrettyName<E, static_cast<E>(Seq)>()...};
    std::array<std::string_view, GetEnumSize<E>(NormalIntegerSequence)> validNames{};

    for (std::size_t i = 0, v = 0; i < names.size(); ++i) if (!names[i].empty()) validNames[v++] = names[i];
    return validNames;
}

template <typename E>
constexpr std::string_view Enum2String(E V)
{
    constexpr auto names = GetAllValidNames<E>(NormalIntegerSequence);
    constexpr auto values = GetAllValidValues<E>(NormalIntegerSequence);
    constexpr auto size = GetEnumSize<E>(NormalIntegerSequence);

    for (size_t i = 0; i < size; ++i) if (V == static_cast<E>(values[i])) return names[i];
    return { std::to_string(static_cast<int>(V)) };
}

class KWEnum
{
public:
    explicit KWEnum() {}
    ~KWEnum() {}

    template<typename T>
    static auto GetName(T e)
    {
        using D = std::decay_t<T>;

        static_assert(KWIsEnum<D>);
        return Enum2String<D>(e);
    }

    template<typename T>
    static auto GetSeq() 
    {
        using D = std::decay_t<T>;

        static_assert(KWIsEnum<D>);
        return GetAllValidValues<D>(NormalIntegerSequence);
    }

    static void Test()
    {
        Color c = Color::GREEN;
        std::cout << GetName(c);
    }
private:
    enum class Color { RED, GREEN, BLUE, };
};

enum class Color {
  RED = 1 << 0,
  GREEN = 1 << 1,
  BLUE = 1 << 2,
  AAA = 1 << 3,
  BBB = 1 << 4,
  CCC = 1 << 5,
  DDD = 1 << 6,
  EEE = 1 << 7,
  FFF = 300,
  GGG,
  HHH,
  III,
  JJJ,
};

// enum class Color {
//   RED,
//   GREEN,
//   BLUE,
//   AAA,
//   BBB,
//   CCC,
//   DDD,
//   EEE,
// };

enum class NGPONG {
  H,
  E,
  L
};

int main(void) {
  for (auto color : KWEnum::GetSeq<Color &&>()) {
    std::cout << KWEnum::GetName(color) << std::endl;
  }

  // std::cout << KWEnum::GetName(Color::RED) << std::endl;
  //   std::cout << KWEnum::GetName(Color::GREEN) << std::endl;
  //     std::cout << KWEnum::GetName(Color::BLUE) << std::endl;
  //       std::cout << KWEnum::GetName(Color::AAA) << std::endl;
  //         std::cout << KWEnum::GetName(Color::BBB) << std::endl;
  //           std::cout << KWEnum::GetName(Color::CCC) << std::endl;
  //             std::cout << KWEnum::GetName(Color::DDD) << std::endl;
                // std::cout << KWEnum::GetName(Color::EEE) << std::endl;

  std::cout << magic_enum::enum_name(Color::RED) << std::endl;
  std::cout << magic_enum::enum_name(Color::GGG) << std::endl;
  std::cout << magic_enum::enum_name(Color::HHH) << std::endl;
  std::cout << magic_enum::enum_name(Color::RED) << std::endl;
    // std::cout << magic_enum::enum_name(Color::GREEN) << std::endl;
  //     std::cout << magic_enum::enum_name(Color::BLUE) << std::endl;
  //       std::cout << magic_enum::enum_name(Color::AAA) << std::endl;
  //         std::cout << magic_enum::enum_name(Color::BBB) << std::endl;
  //           std::cout << magic_enum::enum_name(Color::CCC) << std::endl;
  //             std::cout << magic_enum::enum_name(Color::DDD) << std::endl;
  //               std::cout << magic_enum::enum_name(Color::EEE) << std::endl;

  // auto range = magic_enum::enum_values<int>();

  return EXIT_SUCCESS;
}
