#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>
#include <string.h>

#define SINCE_YEAR               1900
#define FACTOR_MIN_TO_SEC                         60
//#define FACTOR_HOUR_TO_MILLI          60 * 60 * 1000
#define FACTOR_HOUR_TO_MIN                        60
//#define FACTOR_DAY_TO_MILLI      24 * 60 * 60 * 1000
#define FACTOR_DAY_TO_HOUR                        24
// Min and Max values
#define MIN_MONTH                   1
#define MAX_MONTH                  12

#define SUMMERTIME_BEGIN_MONTH      3
#define SUMMERTIME_END_MONTH       10

#define MIN_DAY                     1
#define MAX_DAY                    31

#define MIN_WEEKDAY                 0
#define MAX_WEEKDAY                 7

#define MIN_HOUR                    0
#define MAX_HOUR                   24

#define MIN_MINUTE                  0
#define MAX_MINUTE                 60

#define MIN_SECOND                  0
#define MAX_SECOND                 60

#define MIN_MILLISECOND             0
#define MAX_MILLISECOND           1000


const int64_t FACTOR_SEC_TO_MILLI = 1000;
const int64_t FACTOR_MIN_TO_MILLI = 60 * 1000;
const int64_t FACTOR_HOUR_TO_MILLI = 60 * 60 * 1000;
const int64_t FACTOR_DAY_TO_MILLI = 24 * 60 * 60 * 1000;

class NFException
{
public:
	NFException(const char *format, ...)
	{
		char buf[1024] = {0};
		message = std::string(buf);
	}
	std::string GetMessage() { return message; }
protected:
	std::string message;
};


class NFTimeSpan
{
public:
	NFTimeSpan(int seconds)
	{
		Init(0, 0, 0, seconds, 0);
	}

	NFTimeSpan(int hours, int minutes, int seconds)
	{
		Init(0, hours, minutes, seconds, 0);
	}

	NFTimeSpan(int days, int hours, int minutes, int seconds)
	{
		Init(days, hours, minutes, seconds, 0);
	}

	NFTimeSpan(int days, int hours, int minutes, int seconds, int milliseconds)
	{
		Init(days, hours, minutes, seconds, milliseconds);
	}

	virtual ~NFTimeSpan()
	{

	}

	static NFTimeSpan FromMilliseconds(int milliseconds)
	{
		return NFTimeSpan(0, 0, 0, 0, milliseconds);
	}

	static NFTimeSpan FromSeconds(int seconds)
	{
		return NFTimeSpan(0, 0, 0, seconds, 0);
	}

	static NFTimeSpan FromMinutes(int minutes)
	{
		return NFTimeSpan(0, 0, minutes, 0, 0);
	}

	static NFTimeSpan FromHours(int hours)
	{
		return NFTimeSpan(0, hours, 0, 0, 0);
	}

	static NFTimeSpan FromDays(int days)
	{
		return NFTimeSpan(days, 0, 0, 0, 0);
	}

	int64_t GetMilliseconds() const { return milliseconds; }
	int GetSeconds() const { return seconds; }
	int GetMinutes() const { return minutes; }
	int GetHours() const { return hours; }
	int GetDays() const { return days; }

	int64_t GetTotalMilliseconds() const
	{
		return milliseconds + seconds * FACTOR_SEC_TO_MILLI + minutes * FACTOR_MIN_TO_MILLI + hours * FACTOR_HOUR_TO_MILLI + days * FACTOR_DAY_TO_MILLI;
	}

	//updated : GetTotalXXXXs never return double
	int64_t GetTotalSeconds() const
	{
		return GetTotalMilliseconds() / FACTOR_SEC_TO_MILLI;
	}

	int64_t GetTotalMinutes() const
	{
		return GetTotalSeconds() / FACTOR_MIN_TO_SEC;
	}

	int64_t GetTotalHours() const
	{
		return GetTotalMinutes() / FACTOR_HOUR_TO_MIN;
	}

	int64_t GetTotalDays() const
	{
		return GetTotalHours() / FACTOR_DAY_TO_HOUR;
	}

	bool operator<(const NFTimeSpan &ts) const
	{
		return GetTotalMilliseconds() < ts.GetTotalMilliseconds();
	}

	bool operator>(const NFTimeSpan &ts) const
	{
		return GetTotalMilliseconds() > ts.GetTotalMilliseconds();
	}

	bool operator<=(const NFTimeSpan &ts) const
	{
		return GetTotalMilliseconds() <= ts.GetTotalMilliseconds();
	}

	bool operator>=(const NFTimeSpan &ts) const
	{
		return GetTotalMilliseconds() >= ts.GetTotalMilliseconds();
	}

	bool operator==(const NFTimeSpan &ts) const
	{
		return GetTotalMilliseconds() == ts.GetTotalMilliseconds();
	}

	void Init(int days, int hours, int minutes, int seconds, int64_t milliseconds)
	{
		this->days = days;
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
		this->milliseconds = milliseconds;
	}

protected:

	int64_t milliseconds;
	int seconds;
	int minutes;
	int hours;
	int days;
};


class NFDateTime
{
public:

	enum Day
	{
		Sunday,
		Monday,
		Thuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday
	};

	enum Month
	{
		January,
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

	NFDateTime(int day, int month, int year)
	{
		Init(day, month, year, 0, 0, 0, 0);
	}

	NFDateTime(int day, int month, int year, int hour, int minute, int second)
	{
		Init(day, month, year, hour, minute, second, 0);
	}

	NFDateTime(int day, int month, int year, int hour, int minute, int second, int millisecond)
	{
		Init(day, month, year, hour, minute, second, millisecond);
	}

	NFDateTime(time_t timestamp)
	{
		SetWithTimestamp(timestamp);
	}

	~NFDateTime() 
	{
	}

	static NFDateTime Now()
	{
		NFDateTime dt;
		dt.SetNow();
		return dt;
	}

    static std::string GetNowKey()
    {
        static int nIndex = 0;
	    uint64_t t = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        t = t * 1000000 + nIndex++;
        if (nIndex == 999999)
            t = 0;

        std::stringstream ss(std::stringstream::in | std::stringstream::out);
        ss << t;
        return ss.str();
    }

	/*
	static int GetNowYear() const { return year; }
	static int GetNowMonth() const { return month; }
	static int GetNowDay() const { return day; }

	static int GetNowHour() const { return hour; }
	static int GetNowMinute() const { return minute; }
	static int GetNowSecond() const { return second; }
	static int GetNowMillisecond() const { return millisecond; }
	*/

	void SetNow()
	{
		SetWithTimestamp(time(0));
	}
	
	int GetYear() const { return year; }
	int GetMonth() const { return month; }
	int GetDay() const { return day; }

	int GetHour() const { return hour; }
	int GetMinute() const { return minute; }
	int GetSecond() const { return second; }
	int64_t GetMillisecond() const { return millisecond; }
    int GetOffset() const { return offset; }
    int GetDst() const { return dst; }


	void SetWithTimestamp(time_t timestamp)
	{
	    struct tm time = *localtime(&timestamp);
        // struct tm gmt = *gmtime(&timestamp);
        // time_t gmts = mktime(&gmt);
        // int offset = (int)difftime(timestamp, gmts);
	    Init(time.tm_mday, time.tm_mon + 1, time.tm_year + SINCE_YEAR, time.tm_hour, time.tm_min, time.tm_sec, 0);
	}

	time_t GetTimestamp() const
	{
		// time_t rawtime = time(0);
		// struct tm *time = localtime(&rawtime);
		// time->tm_year = year - SINCE_YEAR;
		// time->tm_mon = month - 1;
		// time->tm_mday = day;
		// time->tm_hour = hour;
		// time->tm_min = minute;
		// time->tm_sec = second;
		// return mktime(time);

		struct tm _tm {second, minute, hour, day, month - 1, year - SINCE_YEAR, 0, 0, -1};
		return mktime(&_tm);
	}

	struct tm GetTMStruct() const
	{
		time_t rawtime = time(0);
		struct tm *time = localtime(&rawtime);
		time->tm_year = year - SINCE_YEAR;
		time->tm_mon = month - 1;
		time->tm_mday = day;
		time->tm_hour = hour;
		time->tm_min = minute;
		time->tm_sec = second;
		mktime(time);
		return *time;
	}

	void Add(const NFTimeSpan *ts)
	{
		AddMilliseconds(ts->GetTotalMilliseconds());
        InitOffset();
	}

	void AddYears(int years)
	{
        year += years;
        InitOffset();
	}

	void AddMonths(int months)
	{
		AddYears(months / MAX_MONTH);
        month += months % MAX_MONTH;
        InitOffset();
	}

	void AddDays(int days)
	{
		int nMaxDay = daysOfMonth[month - 1];
		AddMonths(days / nMaxDay);
        day += days % nMaxDay;
        InitOffset();
	}

	void AddHours(int hours)
	{
		AddDays(hours / MAX_HOUR);
        hour += hours % MAX_HOUR;
        InitOffset();
	}

	void AddMinutes(int minutes)
	{
		AddHours(int(minutes / MAX_MINUTE));
        minute += minutes % MAX_MINUTE;
        InitOffset();
	}

	void AddSeconds(long long seconds)
	{
		AddMinutes(int(seconds / MAX_SECOND));
        second += int(seconds % MAX_SECOND);
        InitOffset();
	}

	void AddMilliseconds(int64_t milliseconds)
	{
		AddSeconds(milliseconds / MAX_MILLISECOND);
        millisecond += milliseconds % MAX_MILLISECOND;
        InitOffset();
	}

	static bool IsYearLeapYear(int year)
	{
		return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	}

	bool IsSummertime() { return IsDateSummertime(day, month); }
	bool IsLeapYear() { return IsYearLeapYear(year); }

	static bool IsDateSummertime(int day, int month)
	{
		// FIXME: include day in calculation
		if (month >= SUMMERTIME_BEGIN_MONTH && month <= SUMMERTIME_END_MONTH)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	std::string GetNameOfDay(int day)
	{
		if (IsValidWeekday(day))
		{
			return dayNames[day - 1];
		}
		else
		{
			throw NFException("Day %d is not in valid weekday range ( %d - %d )", day, MIN_WEEKDAY, MAX_WEEKDAY);
		}
	}

	std::string GetNameOfMonth(int month)
	{
		if (IsValidMonth(month))
		{
			return monthNames[month - 1];
		}
		else
		{
			throw NFException("Month %d is not in valid range ( %d - %d )", month, MIN_MONTH, MAX_MONTH);
		}
	}

	Day GetDayOfWeek()
	{
		return static_cast<NFDateTime::Day>(GetTMStruct().tm_wday);
	}

	int GetDayOfYear()
	{
		return GetTMStruct().tm_yday;
	}

	int GetDaysOfMonth(int month)
	{
		return IsValidMonth(month) ? daysOfMonth[month - 1] : -1;
	}

	bool operator<(const NFDateTime &dt) const
	{
		return GetTimestamp() < dt.GetTimestamp();
	}

	bool operator>(const NFDateTime &dt) const
	{
		return GetTimestamp() > dt.GetTimestamp();
	}

	bool operator<=(const NFDateTime &dt) const
	{
		return GetTimestamp() <= dt.GetTimestamp();
	}

	bool operator>=(const NFDateTime &dt) const
	{
		return GetTimestamp() >= dt.GetTimestamp();
	}

	bool operator==(const NFDateTime &dt) const
	{
		return GetTimestamp() == dt.GetTimestamp();
	}

	NFDateTime operator+(const NFTimeSpan &ts)
	{
		NFDateTime *tmp = this;
		tmp->Add(&ts);
		return *tmp;
	}

	void operator+=(const NFTimeSpan &ts)
	{
		Add(&ts);
	}


	std::string GetAsString()
	{
		return GetShortDateString() + std::string(" - ") + GetShortTimeString();
	}

	std::string GetShortTimeString()
	{
		std::stringstream ss(std::stringstream::in | std::stringstream::out);
		ss << std::setfill('0') << std::setw(2) << hour << ":" << std::setw(2) << minute << ":" << std::setw(2) << second;
		return ss.str();
	}

	std::string GetLongTimeString()
	{
		std::stringstream ss(std::stringstream::in | std::stringstream::out);
		ss << std::setfill('0') << std::setw(2) << hour << ":" << std::setw(2) << minute << ":" << std::setw(2) << second << ":" << std::setw(2) << millisecond;
		return ss.str();
	}

	std::string GetShortDateString()
	{
		std::stringstream ss(std::stringstream::in | std::stringstream::out);
		ss << std::setfill('0') << std::setw(2) << day << "." << std::setw(2) << month << "." << year;
		return ss.str();
	}

    std::string GetCustomFomatString()
    {
        std::stringstream ss(std::stringstream::in | std::stringstream::out);
        ss << std::setfill('0') << year << "-" << std::setw(2) << month << "-" << std::setw(2) << day
            << " "  << std::setw(2) << hour << ":" << std::setw(2) << minute << ":" << std::setw(2) << second;
        return ss.str();
    }

	std::string GetLongDateString()
	{
		std::stringstream ss(std::stringstream::in | std::stringstream::out);
		ss << GetNameOfDay(GetDayOfWeek()) << ", " << GetNameOfMonth(month) << " " << day << ", " << year;
		return ss.str();
	}

    std::string GetAsFriendlyString()
    {
        std::stringstream ss(std::stringstream::in | std::stringstream::out);
        ss << std::setfill('0') << std::setw(4) << year << "-" << std::setw(2) << month << "-" << std::setw(2) << day << "T"
            << std::setw(2) << hour << ":" << std::setw(2) << minute << ":" << std::setw(2) << second 
            << (offset > 0 ? "+" : "-");
        int offHour = std::abs(offset) / 3600;
        int offMin = std::abs(offset) % 3600 / 60;
        ss << std::setw(2) << offHour << ":" << std::setw(2) << offMin;
        return ss.str();
    }

protected:
	NFDateTime()
	{
		this->day = 0;
		this->month = 0;
		this->year = 0;

		this->hour = 0;
		this->minute = 0;
		this->second = 0;
		this->millisecond = 0;

        this->dst = 0;
        this->offset = 0;

		InitMonths();
		InitMonthNames();
		InitDayNames();
		//InitOffset();
	}

    void Init(int day, int month, int year, int hour, int minute, int second, int64_t millisecond, int offset)
    {
        Init(day, month, year, hour, minute, second, millisecond);
        this->offset = offset;
    }

	void Init(int day, int month, int year, int hour, int minute, int second, int64_t millisecond)
	{
		this->year = year;

		InitMonths();
		InitMonthNames();
		InitDayNames();

		if (!IsValidMonth(month))
		{
			throw NFException("Month %d is not in range", month);
		}

		if (!IsValidDayOfMonth(day, month))
		{
			throw NFException("Day %d is not in month %d's range", day, month);
		}

		if (!IsValidHour(hour))
		{
			throw NFException("Hour %d is not in valid range ( %d - %d )", hour, MIN_HOUR, MAX_HOUR);
		}

		if (!IsValidMinute(minute))
		{
			throw NFException("Minute %d is not in valid range ( %d - %d )", minute, MIN_MINUTE, MAX_MINUTE);
		}

		if (!IsValidSecond(second))
		{
			throw NFException("Second %d is not in valid range ( %d - %d )", second, MIN_SECOND, MAX_SECOND);
		}

		if (!IsValidMillisecond(millisecond))
		{
			throw NFException("Millisecond %d is not in valid range ( %d - %d )", millisecond, MIN_MILLISECOND, MAX_MILLISECOND);
		}

		this->day = day;
		this->month = month;

		this->hour = hour;
		this->minute = minute;
		this->second = second;
		this->millisecond = millisecond;

		InitOffset();
	}

	void InitMonths()
	{
		// Perhaps an algorithm would be more efficient
		daysOfMonth[Month::January] = 31;
		daysOfMonth[Month::February] = IsLeapYear() ? 29 : 28; // In a leapyear 29 else 28
		daysOfMonth[Month::March] = 31;
		daysOfMonth[Month::April] = 30;
		daysOfMonth[Month::May] = 31;
		daysOfMonth[Month::June] = 30;
		daysOfMonth[Month::July] = 31;
		daysOfMonth[Month::August] = 31;
		daysOfMonth[Month::September] = 30;
		daysOfMonth[Month::October] = 31;
		daysOfMonth[Month::November] = 30;
		daysOfMonth[Month::December] = 31;
	}

	void InitMonthNames()
	{
		monthNames[Month::January] = "January";
		monthNames[Month::February] = "February";
		monthNames[Month::March] = "March";
		monthNames[Month::April] = "April";
		monthNames[Month::May] = "May";
		monthNames[Month::June] = "June";
		monthNames[Month::July] = "July";
		monthNames[Month::August] = "August";
		monthNames[Month::September] = "September";
		monthNames[Month::October] = "October";
		monthNames[Month::November] = "November";
		monthNames[Month::December] = "December";
	}

	void InitDayNames()
	{
		dayNames[Day::Monday] = "Monday";
		dayNames[Day::Thuesday] = "Thuesday";
		dayNames[Day::Wednesday] = "Wednesday";
		dayNames[Day::Thursday] = "Thursday";
		dayNames[Day::Friday] = "Friday";
		dayNames[Day::Saturday] = "Saturday";
		dayNames[Day::Sunday] = "Sunday";
	}

	void InitOffset()
	{
		/*
		time_t t = time(0);
        struct tm gmt = *gmtime(&t);
        time_t gmts = mktime(&gmt);
        int offset = (int)difftime(t, gmts);
		this->offset = offset;
		*/

		// time_t t = time(0);
		time_t t = GetTimestamp();
		struct tm *locg = localtime(&t);
		struct tm locl;
        memcpy(&locl, locg, sizeof(struct tm));

		int offset = timegm(locg) - mktime(&locl);
		this->dst = locl.tm_isdst;
		this->offset = offset;
	}

	bool IsValidWeekday(int day)
	{
		return day >= MIN_WEEKDAY && day <= MAX_WEEKDAY;
	}

	bool IsValidDayOfMonth(int day, int month)
	{
		if (IsValidMonth(month))
		{
			return day >= 1 && day <= GetDaysOfMonth(month);
		}
		else
		{
			return false;
		}
	}

	bool IsValidMonth(int month)
	{
		return month >= MIN_MONTH && month <= MAX_MONTH;
	}

	bool IsValidYear(int year)
	{
		return year >= 0;
	}

	bool IsValidHour(int hour)
	{
		return hour >= MIN_HOUR && hour < MAX_HOUR;
	}

	bool IsValidMinute(int minute)
	{
		return minute >= MIN_MINUTE && minute < MAX_MINUTE;
	}

	bool IsValidSecond(int second)
	{
		return second >= MIN_SECOND && second < MAX_SECOND;
	}

	bool IsValidMillisecond(int64_t millisecond)
	{
		return millisecond >= MIN_MILLISECOND && millisecond < MAX_MILLISECOND;
	}

	
protected:
	int daysOfMonth[MAX_MONTH];
	std::string monthNames[MAX_MONTH];
	std::string dayNames[MAX_WEEKDAY];

	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int64_t millisecond;
    int offset;
	int dst;

	bool summertime;
	bool leapyear;
};

const int NF_MINUTE(60);
const int NF_HOUR(60 * 60);
const int NF_DAY(24 * 60 * 60);
const int NF_MONTH(30 * 24 * 60 * 60);


int GetMonthResetTs(const NFDateTime& triggerDate)
{
    const int nowTS = NFDateTime::Now().GetTimestamp();
    NFDateTime nowDate = NFDateTime(nowTS - (triggerDate.GetHour() * NF_HOUR + triggerDate.GetMinute() * NF_MINUTE + triggerDate.GetSecond())); // 调整重置时间点的偏移

    int64_t curMonthTs = NFDateTime(1, nowDate.GetMonth(), nowDate.GetYear(), triggerDate.GetHour(), triggerDate.GetMinute(), triggerDate.GetSecond()).GetTimestamp();
    NFDateTime curMonthReset = NFDateTime(curMonthTs + triggerDate.GetDay() * NF_DAY);
    const int nextIntervalDays = nowDate.GetDaysOfMonth(nowDate.GetMonth());

    const int lastResetTs = curMonthReset.GetTimestamp();
    const int nextResetTs = lastResetTs + nextIntervalDays * NF_DAY;

    if (nowTS < lastResetTs) {
        std::cout << lastResetTs - nowTS << std::endl;
    } else {
        std::cout << nextResetTs - nowTS << std::endl;
    }

    return nextResetTs - nowTS;
}

int GetWeekResetTs(int64_t nowTs, int triggerDay, int triggerSec)
{
    NFDateTime nowDate = NFDateTime(nowTs);

    NFDateTime triggerDate(nowDate.GetDay(), nowDate.GetMonth(), nowDate.GetYear());
    triggerDate.AddSeconds(triggerSec);

    int nowDay = nowDate.GetDayOfWeek() == 0 ? 7 : nowDate.GetDayOfWeek();
    if (triggerDay > nowDay) 
        triggerDate.AddDays(triggerDay - nowDay);
    else if (triggerDay < nowDay || triggerDate.GetTimestamp() < nowDate.GetTimestamp()) 
        triggerDate.AddDays(7 - nowDay + triggerDay);

    return triggerDate.GetTimestamp() - nowDate.GetTimestamp();
}

int main(void) {
  std::cout << GetWeekResetTs(NFDateTime::Now().GetTimestamp(), 2, 36000) << std::endl;
  std::cout << GetWeekResetTs(NFDateTime::Now().GetTimestamp(), 2, 72000) << std::endl;

  std::cout << GetWeekResetTs(NFDateTime::Now().GetTimestamp(), 1, 72000) << std::endl;

  std::cout << GetWeekResetTs(NFDateTime::Now().GetTimestamp(), 7, 72000) << std::endl;

  std::cout << GetWeekResetTs(NFDateTime::Now().GetTimestamp(), 5, 36000) << std::endl;

  std::cout << GetWeekResetTs(1636423200, 2, 36000) << std::endl;

  return EXIT_SUCCESS;
}
