#ifndef KW_DATETIME_HPP
#define KW_DATETIME_HPP

#include <sstream>
#include <iomanip>
#include <string>
#include <chrono>

#define STR_CASE(_Enum, _Str) case _Enum::_Str : return # _Str
#define MONTH_CASE(_Month) STR_CASE(::Month, _Month)
#define DAY_CASE(_Day)     STR_CASE(::DayOfWeek, _Day)

using namespace std::chrono;

enum class DayOfWeek {
  Sunday = 0,
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday
};

enum class Month {
  January = 1,
  February,
  March,
  April,
  May,
  June,
  July,
  August,
  September,
  October,
  November,
  December
};

class KWDateTime;

class KWTimeSpan {
public:
  using KWTimeDiff = int32_t;

  static constexpr KWTimeDiff KW_ONE_SECOND = 1L;
  static constexpr KWTimeDiff KW_ONE_MINUTE_S = 60 * KW_ONE_SECOND;
  static constexpr KWTimeDiff KW_ONE_HOUR_S = 60 * KW_ONE_MINUTE_S;
  static constexpr KWTimeDiff KW_ONE_DAY_S = 24 * KW_ONE_HOUR_S;
  static constexpr KWTimeDiff KW_ONE_WEEK_S = 7 * KW_ONE_DAY_S;

  static constexpr KWTimeDiff KW_ONE_SECOND_MS = 1000L;
  static constexpr KWTimeDiff KW_ONE_MINUTE_MS = 60 * KW_ONE_SECOND_MS;
  static constexpr KWTimeDiff KW_ONE_HOUR_MS = 60 * KW_ONE_MINUTE_MS;
  static constexpr KWTimeDiff KW_ONE_DAY_MS = 24 * KW_ONE_HOUR_MS;
  static constexpr KWTimeDiff KW_ONE_WEEK_MS = 7 * KW_ONE_DAY_MS;

  explicit KWTimeSpan(int seconds)
    : totalSecond(seconds) {}

  KWTimeSpan(int hours, int minutes, int seconds)
    : KWTimeSpan(0, hours, minutes, seconds) {}

  KWTimeSpan(int days, int hours, int minutes, int seconds)
    : totalSecond(days * KW_ONE_DAY_S + hours * KW_ONE_HOUR_S + minutes * KW_ONE_MINUTE_S + seconds * KW_ONE_SECOND) {}

  inline int TotalSecond() const {
    return totalSecond;
  }

  inline int Seconds() const {
    return totalSecond - totalSecond / KW_ONE_MINUTE_S;
  }

  inline int Minutes() const {
    return (totalSecond - totalSecond / KW_ONE_HOUR_S) / KW_ONE_MINUTE_S;
  }

  inline int Hours() const {
    return (totalSecond - totalSecond / KW_ONE_DAY_S) / KW_ONE_HOUR_S;
  }

  inline int Days() const {
    return totalSecond / KW_ONE_DAY_S;
  }

  inline void AddSeconds(int value) {
    totalSecond += value;
  }

  inline void AddMinutes(int value) {
    totalSecond += value * KW_ONE_MINUTE_S;
  }

  inline void AddHours(int value) {
    totalSecond += value * KW_ONE_HOUR_S;
  }

  inline void AddDays(int value) {
    totalSecond += value * KW_ONE_DAY_S;
  }

  static bool Equals(const KWTimeSpan &t1, const KWTimeSpan &t2) {
    return t1.totalSecond == t2.totalSecond;
  }

  inline bool Equals(const KWTimeSpan &value) const {
    return totalSecond == value.totalSecond;
  }

  inline KWTimeSpan Subtract(const KWTimeSpan &ts) const {
    return KWTimeSpan(totalSecond - ts.totalSecond);
  }

  inline std::string ToString() const {
    std::stringstream ss(std::stringstream::in | std::stringstream::out);
    ss << std::setfill('0') << Days() << "." << std::setw(2) << Hours() << ":" << std::setw(2) << Minutes() << ":" << std::setw(2) << Seconds();
    return ss.str();
  }

  inline KWTimeSpan operator+(const KWTimeSpan &t) const {
    return KWTimeSpan(totalSecond + t.totalSecond);
  }

  inline KWTimeSpan operator-(const KWTimeSpan &t) const {
    return KWTimeSpan(totalSecond - t.totalSecond);
  }

  inline KWTimeSpan &operator+=(const KWTimeSpan &t) {
    totalSecond += t.totalSecond;
    return *this;
  }

  inline KWTimeSpan &operator-=(const KWTimeSpan &t) {
    totalSecond -= t.totalSecond;
    return *this;
  }

  inline bool operator==(const KWTimeSpan &t) {
    return totalSecond == t.totalSecond;
  }

  inline bool operator!=(const KWTimeSpan &t) {
    return totalSecond != t.totalSecond;
  }

  inline bool operator<(const KWTimeSpan &t) {
    return totalSecond < t.totalSecond;
  }

  inline bool operator>(const KWTimeSpan &t) {
    return totalSecond > t.totalSecond;
  }

  inline bool operator<=(const KWTimeSpan &t) {
    return totalSecond <= t.totalSecond;
  }

  inline bool operator>=(const KWTimeSpan &t) {
    return totalSecond >= t.totalSecond;
  }

  inline KWTimeSpan operator+(KWTimeDiff seconds) const {
    return KWTimeSpan(totalSecond + seconds);
  }

  inline KWTimeSpan operator-(KWTimeDiff seconds) const {
    return KWTimeSpan(totalSecond - seconds);
  }

  inline KWTimeSpan &operator+=(KWTimeDiff seconds) {
    totalSecond += seconds;
    return *this;
  }

  inline KWTimeSpan &operator-=(KWTimeDiff seconds) {
    totalSecond -= seconds;
    return *this;
  }

  inline bool operator==(KWTimeDiff seconds) {
    return totalSecond == seconds;
  }

  inline bool operator!=(KWTimeDiff seconds) {
    return totalSecond != seconds;
  }

  inline bool operator<(KWTimeDiff seconds) {
    return totalSecond < seconds;
  }

  inline bool operator>(KWTimeDiff seconds) {
    return totalSecond > seconds;
  }

  inline bool operator<=(KWTimeDiff seconds) {
    return totalSecond <= seconds;
  }

  inline bool operator>=(KWTimeDiff seconds) {
    return totalSecond >= seconds;
  }

protected:
  int64_t totalSecond;
  friend class KWDateTime;
};


class KWDateTime {
public:
  //seconds, from 1970-01-01
  //std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() / 1000
  explicit KWDateTime(const int64_t seconds)
    : _totalSecond(seconds) {
    UpdateTM();
  }

  //yyyy-MM-dd hh:mm:ss
  explicit KWDateTime(const std::string &data) {
    try {
      std::stringstream ss(data);
      ss >> std::get_time(&_tm, "%Y-%m-%d %H:%M:%S");
      // _totalSecond = timegm(&_tm);
      _totalSecond = timelocal(&_tm);
    } catch (...) {
    }
  }

  KWDateTime(int year, int month, int day)
    : KWDateTime(year, month, day, 0, 0, 0) {}


  KWDateTime(int year, int month, int day, int hour, int minute, int second)
    : _tm{ second, minute, hour, day, month - 1, year - 1900, 0, 0, -1, 0 } {
    // _totalSecond = timegm(&_tm);
    _totalSecond = timelocal(&_tm);
  }

  static inline int64_t KWGetTimeMS() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
  }

  static KWDateTime Now() {
    return KWDateTime(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());
  }

  inline int Month() const {
    return _tm.tm_mon + 1;
  }

  inline int Minute() const {
    return _tm.tm_min;
  }

  inline int Millisecond() const {
    return _totalSecond;
  }

  inline int Hour() const {
    return _tm.tm_hour;
  }

  inline int DayOfYear() const {
    return _tm.tm_yday;
  }

  inline ::DayOfWeek DayOfWeek() const {
    return static_cast<::DayOfWeek>(_tm.tm_wday);
  }

  inline int WeekOfYear() const {
    return _tm.tm_yday / 7;
  }

  inline int Day() const {
    return _tm.tm_mday;
  }

  inline int Second() const {
    return _tm.tm_sec;
  }

  inline KWTimeSpan TimeOfDay() const {
    return KWTimeSpan(0, _tm.tm_hour, _tm.tm_min, _tm.tm_sec);
  }

  inline int Year() const {
    return _tm.tm_year + 1900;
  }

  inline int Timestamp() {
    return _totalSecond;
  }

  static int DaysInMonth(int year, int month) {
    switch (static_cast<::Month>(month)) {
    case Month::January:
    case Month::March:
    case Month::May:
    case Month::July:
    case Month::August:
    case Month::October:
    case Month::December:
      return 31;
    case Month::April:
    case Month::June:
    case Month::September:
    case Month::November:
      return 30;
    case Month::February:
      return IsLeapYear(year) ? 29 : 28;
    default:
      break;
    }

    return -1;
  }

  static bool IsLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
  }

  inline void Add(const KWTimeSpan &value) {
    _totalSecond += value.totalSecond;
    UpdateTM();
  }

  inline void AddDays(const int value) {
    _totalSecond += value * KWTimeSpan::KW_ONE_DAY_S;
    UpdateTM();
  }

  inline void AddHours(const int value) {
    _totalSecond += value * KWTimeSpan::KW_ONE_HOUR_S;
    UpdateTM();
  }

  inline void AddMinutes(const int value) {
    _totalSecond += value * KWTimeSpan::KW_ONE_MINUTE_S;
    UpdateTM();
  }

  inline void AddSeconds(const int value) {
    _totalSecond += value;
    UpdateTM();
  }

  inline KWDateTime AddMonths(const int value) const {
    auto new_month = _tm.tm_mon + value;
    auto new_year = _tm.tm_year + new_month / 12 + 1900;
    new_month = new_month % 12 + 1;
    auto daysInMonth = DaysInMonth(new_year, new_month);
    auto new_day = _tm.tm_mday < daysInMonth ? _tm.tm_mday : daysInMonth;
    return KWDateTime(_tm.tm_year, new_month, new_day, _tm.tm_hour, _tm.tm_min, _tm.tm_sec);
  }


  inline KWDateTime AddYears(const int value) const {
    auto new_year = _tm.tm_year + value + 1900;
    auto daysInMonth = DaysInMonth(new_year, _tm.tm_mon);
    auto new_day = _tm.tm_mday < daysInMonth ? _tm.tm_mday : daysInMonth;
    return KWDateTime(_tm.tm_year, _tm.tm_mon, new_day, _tm.tm_hour, _tm.tm_min, _tm.tm_sec);
  }

  inline bool Equals(const KWDateTime &value) {
    return *this == value;
  }

  inline bool IsDaylightSavingTime() const {
    return _tm.tm_isdst;
  }

  inline KWTimeSpan Subtract(const KWDateTime &value) const {
    return KWTimeSpan(_totalSecond - value._totalSecond);
  }

  inline void Subtract(const KWTimeSpan &value) {
    _totalSecond -= value.totalSecond;
    UpdateTM();
  }

  //yyyy-MM-dd hh:mm:ss
  inline std::string ToString() {
    std::stringstream ss(std::stringstream::in | std::stringstream::out);
    ss << std::setfill('0') << std::setw(4) << Year() << "-" << std::setw(2) << Month() << "-" << std::setw(2) << Day();
    ss << "T";
    ss << std::setfill('0') << std::setw(2) << Hour() << ":" << std::setw(2) << Minute() << ":" << std::setw(2) << Second();

    int offset = _tm.tm_gmtoff;
    int offHour = std::abs(offset) / KWTimeSpan::KW_ONE_HOUR_S;
    int offMin = std::abs(offset) % KWTimeSpan::KW_ONE_HOUR_S / KWTimeSpan::KW_ONE_MINUTE_S;

    ss << (offset > 0 ? "+" : "-") << std::setw(2) << offHour << ":" << std::setw(2) << offMin;
    return ss.str();
  }

  inline KWTimeSpan operator-(const KWDateTime &d) const {
    return Subtract(d);
  }

  inline bool operator==(const KWDateTime &dt) const {
    return _totalSecond == dt._totalSecond;
  }

  inline bool operator!=(const KWDateTime &dt) const {
    return _totalSecond != dt._totalSecond;
  }

  inline bool operator<(const KWDateTime &dt) const {
    return _totalSecond < dt._totalSecond;
  }

  inline bool operator>(const KWDateTime &dt) const {
    return _totalSecond > dt._totalSecond;
  }

  inline bool operator<=(const KWDateTime &dt) const {
    return _totalSecond <= dt._totalSecond;
  }

  inline bool operator>=(const KWDateTime &dt) const {
    return _totalSecond >= dt._totalSecond;
  }

  std::tm GetTM() {
    return _tm;
  }

protected:
  int _totalSecond;
  std::tm _tm;

  void UpdateTM() {
    time_t t = static_cast<time_t>(_totalSecond);
    // _tm = *std::gmtime(&t);
    _tm = *std::localtime(&t);
  }

  static std::string NameOfDay(::DayOfWeek day) {
    switch (day) {
      DAY_CASE(Monday);
      DAY_CASE(Tuesday);
      DAY_CASE(Wednesday);
      DAY_CASE(Thursday);
      DAY_CASE(Friday);
      DAY_CASE(Saturday);
      DAY_CASE(Sunday);

    default:
      //throw KWException("Day %d is not in valid weekday range ( %d - %d )", day, ::DayOfWeek::Sunday, ::DayOfWeek::Saturday);
      break;
    }
  }

  static std::string NameOfMonth(int month) {
    switch (static_cast<::Month>(month)) {
      MONTH_CASE(January);
      MONTH_CASE(February);
      MONTH_CASE(March);
      MONTH_CASE(April);
      MONTH_CASE(May);
      MONTH_CASE(June);
      MONTH_CASE(July);
      MONTH_CASE(August);
      MONTH_CASE(September);
      MONTH_CASE(October);
      MONTH_CASE(November);
      MONTH_CASE(December);

    default:
      //throw KWException("Month %d is not in valid range ( %d - %d )", month, ::Month::January, ::Month::December);
      break;
    }
  }
  static std::string DaySuffix(int day) {
    switch (day) {
    case 1:
    case 21:
    case 31:
      return "st";

    case 2:
    case 22:
      return "nd";

    case 3:
    case 23:
      return "rd";

    default:
      return "th";
    }
  }
};

#endif
