#ifndef KW_CRON_HPP
#define KW_CRON_HPP

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <chrono>
#include <iterator>

#include "datetime.hpp"

class KWCron {
public:
  explicit KWCron(const std::string &expression) {
    std::istringstream iss(expression);
    std::vector<std::string> tokens(std::istream_iterator<std::string>(iss), {});

    Parse(tokens[0], expression, mMinute, 0, 59);
    Parse(tokens[1], expression, mHour, 0, 23);
    Parse(tokens[2], expression, mDay, 1, 31);
    Parse(tokens[3], expression, mMonth, 1, 12, true);
    Parse(tokens[4], expression, mDayOfWeek, 0, 6);
  }

  int64_t CronToNext(int64_t nowTs) {
    KWDateTime now(nowTs / 1000);
    std::cout << ">>>cron now ts in ms: " << nowTs << std::endl;

    std::tm next = now.GetTM();

    next.tm_sec = 0;
    AddDuration(next, std::chrono::minutes(1));

    while (true) {
      if (mMonth != -1 && next.tm_mon != mMonth) {
        // add a month
        // if this will bring over a year, increment the year and reset the month
        if (next.tm_mon + 1 > 11) {
          next.tm_mon = 0;
          next.tm_year++;
        } else
          next.tm_mon++;

        next.tm_mday = 1;
        next.tm_hour = 0;
        next.tm_min = 0;
        continue;
      }

      if (mDay != -1 && next.tm_mday != mDay) {
        AddDuration(next, std::chrono::hours(24));
        next.tm_hour = 0;
        next.tm_min = 0;
        continue;
      }

      if (mDayOfWeek != -1 && next.tm_wday != mDayOfWeek) {
        AddDuration(next, std::chrono::hours(24));
        next.tm_hour = 0;
        next.tm_min = 0;
        continue;
      }

      if (mHour != -1 && next.tm_hour != mHour) {
        AddDuration(next, std::chrono::hours(1));
        next.tm_min = 0;
        continue;
      }

      if (mMinute != -1 && next.tm_min != mMinute) {
        AddDuration(next, std::chrono::minutes(1));
        continue;
      }

      break;
    }

    next.tm_isdst = -1;

    int64_t nextTs = timelocal(&next) * 1000;
    std::cout << ">>>cron next ts in ms: " << nextTs << std::endl;
    return nextTs;
  }

private:
  void Parse(const std::string &token, const std::string &expression, int &field, const int lowerBound, const int upperBound, const bool adjust = false) {
    if ("*" == token) {
      field = -1;
      return;
    }

    field = std::stoi(token);

    if (adjust)
      field--;
  }

  void AddDuration(std::tm &tm, const std::chrono::system_clock::duration &duration) {
    auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    auto tpAdjusted = tp + duration;
    auto tmAdjusted = std::chrono::system_clock::to_time_t(tpAdjusted);
    tm = *std::localtime(&tmAdjusted);
  }

private:
  int mMinute;
  int mHour;
  int mDay;
  int mMonth;
  int mDayOfWeek;
};

#endif
