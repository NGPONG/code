#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <unordered_set>
#include <variant>
#include <type_traits>
#include <map>
#include <set>
#include <unordered_set>
#include <random>
#include <chrono>
#include <algorithm>
#include <bit>
#include <bitset>
#include <array>

#define KW_ENUM_RANGE_MAX 128

template<typename E>
concept KWEnumType = std::is_enum_v<E>;

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

    for (std::size_t i = 0, v = 0; i < names.size(); ++i) if (!names[i].empty()) { validNames[v++] = names[i]; }
    return validNames;
}

template <typename E>
constexpr std::string_view Enum2String(E V)
{
    constexpr auto names = GetAllValidNames<E>(NormalIntegerSequence);
    constexpr auto values = GetAllValidValues<E>(NormalIntegerSequence);
    constexpr auto size = GetEnumSize<E>(NormalIntegerSequence);

    for (size_t i = 0; i < size; ++i) if (V == static_cast<E>(values[i])){ return names[i]; }
    return { std::to_string(static_cast<int>(V)) };
}

class KWEnum
{
public:
    template<typename U>
    struct TypeDeducer
    {
        U val;

        TypeDeducer(U _val): val(_val) {}

        template<typename T>
        operator T()
        {
            return static_cast<T>(val);
        }

        template<typename T>
        bool operator==(T t)
        {
            return static_cast<T>(val) == t;
        }

        template<typename T>
        bool operator!=(T t)
        {
            return static_cast<T>(val) != t;
        }
    };

    template<typename U>
    struct FlagDeducer
    {
        U val;

        constexpr FlagDeducer(U _val): val(_val) {}

        constexpr operator U() const { return val; }
        constexpr operator bool() const { return KWEnum::GetVal(val); }
    };

public:
    explicit KWEnum() {}
    ~KWEnum() {}

    template<typename T>
    static auto GetName(T e)
    {
        static_assert(KWIsEnum<T>);
        return Enum2String<T>(e);
    }

    template<typename T>
    static constexpr auto GetSeq()
    {
        static_assert(KWIsEnum<T>);
        return GetAllValidValues<T>(NormalIntegerSequence);
    }

    template <typename T>
    static constexpr typename std::underlying_type<T>::type GetVal(T t) noexcept
    {
        static_assert(KWIsEnum<T>);
        return static_cast<typename std::underlying_type<T>::type>(t);
    }

private:
    enum class Color { RED, GREEN, BLUE, };

    static void Example()
    {
        for (auto color : KWEnum::GetSeq<Color>())
        {
            std::cout << KWEnum::GetName(color) << std::endl;
        }
    }
};

#define __ENUM_FLAG_FUNC__(U) \
enum class U : uint64_t; \
inline constexpr KWEnum::FlagDeducer<U> operator & (U u1, U u2) { return static_cast<U>(KWEnum::GetVal(u1) & KWEnum::GetVal(u2)); }; \
inline constexpr U operator | (U u1, U u2) { return static_cast<U>(KWEnum::GetVal(u1) | KWEnum::GetVal(u2)); }; \
inline constexpr U operator ^ (U u1, U u2) { return static_cast<U>(KWEnum::GetVal(u1) ^ KWEnum::GetVal(u2)); }; \
inline constexpr U operator ~ (U x) { return static_cast<U>(~KWEnum::GetVal(x)); }; \
inline constexpr U& operator &= (U& u1, U u2) { u1 = u1 & u2; return u1; }; \
inline constexpr U& operator |= (U& u1, U u2) { u1 = u1 | u2; return u1; }; \
inline constexpr U& operator ^= (U& u1, U u2) { u1 = u1 ^ u2; return u1; };

#define ENUM_FLAG_(U) \
__ENUM_FLAG_FUNC__(U) \
enum class U : uint64_t

#define ENUM_2_FLAG(U) \
__ENUM_FLAG_FUNC__(U)

template<class T, std::size_t N>
constexpr T calc_bitmask() {
    if constexpr (N == sizeof(unsigned long long) * CHAR_BIT) return ~T{};
    else return static_cast<T>((1ull << N) - 1);
}

ENUM_FLAG_(RewardFlag)
{
    A = 1u << 0,
    B = 1u << 1,
    C = 1u << 2,
    D = 1u << 3,
    E = 1u << 4,
    INIT = 1u << 5,
};

ENUM_FLAG_(RewardFlagLevel)
{
    L1 = 0,
    L2 = 1,
};

consteval uint64_t GetInitRewardFlag() {
    constexpr std::size_t level_size = KWEnum::GetSeq<RewardFlagLevel>().size();
    constexpr std::size_t flags_size = KWEnum::GetSeq<RewardFlag>().size();
    
    uint64_t ret = 0;

    for (int32_t level = 0; level < level_size; ++level) {
        ret |= (static_cast<uint64_t>(RewardFlag::INIT) << (level * flags_size));
    }

    return ret;
}

void SetRewardFlag(uint64_t& val, RewardFlag flag) {
    constexpr std::size_t flag_size  = KWEnum::GetSeq<RewardFlag>().size();
    constexpr std::size_t level_size = KWEnum::GetSeq<RewardFlagLevel>().size();
    constexpr uint64_t bit_mask = calc_bitmask<uint64_t, flag_size>();

    for (std::size_t i = static_cast<std::size_t>(RewardFlagLevel::L1); i < level_size; ++i) {
        const std::size_t step = flag_size * i;

        const uint64_t raw_flag = val & (bit_mask << step);

        if ((raw_flag >> step) & static_cast<uint64_t>(RewardFlag::INIT)) {
            const uint64_t new_flag = static_cast<uint64_t>(flag) << step;

            val = (val & ~raw_flag) | new_flag;

            break;
        }
    }

    std::cout << std::bitset<64>(val).to_string() << std::endl;
    std::cout << std::endl;
}

void SetRewardFlag(uint64_t& val, RewardFlag flg, RewardFlagLevel level) {
    constexpr std::size_t flags_size = KWEnum::GetSeq<RewardFlag>().size();
    constexpr uint64_t bit_mask = calc_bitmask<uint64_t, flags_size>();

    const std::size_t step = flags_size * static_cast<std::size_t>(level);

    const uint64_t raw_flag = val & (bit_mask << step);

    const uint64_t new_flag = static_cast<uint64_t>(flg) << step;

    val = (val & ~raw_flag) | new_flag;

    std::cout << std::bitset<64>(val).to_string() << std::endl;
    std::cout << std::endl;
}

uint64_t GetRewardFlag(uint64_t& val) {
    return val;
}

RewardFlag GetRewardFlag(uint64_t& val, RewardFlagLevel level) {
    constexpr std::size_t flags_size = KWEnum::GetSeq<RewardFlag>().size();
    constexpr uint64_t bit_mask = calc_bitmask<uint64_t, flags_size>();

    const std::size_t step = flags_size * static_cast<std::size_t>(level);

    const uint64_t raw_flag = val & (bit_mask << step);

    return static_cast<RewardFlag>(raw_flag >> step);
}

int32_t main(void) {
    uint64_t i = GetInitRewardFlag();
    std::cout << std::bitset<64>(i).to_string() << std::endl;
    std::cout << std::endl;

    SetRewardFlag(i, RewardFlag::INIT);

    SetRewardFlag(i, RewardFlag::E);

    SetRewardFlag(i, RewardFlag::B);

    SetRewardFlag(i, RewardFlag::C, RewardFlagLevel::L2);

    // SetRewardFlag(i, RewardFlag::A);

    // SetRewardFlag(i, RewardFlag::D);

    // SetRewardFlag(i, RewardFlag::E, RewardFlagLevel::L1);

    // SetRewardFlag(i, RewardFlag::A, RewardFlagLevel::L1);

    // SetRewardFlag(i, RewardFlag::D, RewardFlagLevel::L2);

    std::cout << KWEnum::GetName(GetRewardFlag(i, RewardFlagLevel::L1)) << std::endl;

    std::cout << KWEnum::GetName(GetRewardFlag(i, RewardFlagLevel::L2)) << std::endl;

    return 0;
}
