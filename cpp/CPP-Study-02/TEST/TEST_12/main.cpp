#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
#include <climits>

int64_t g_num = 0;

inline int64_t NFGetTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

inline int64_t NFGetTimeSec()
{
	return NFGetTime() / 1000;
}

int64_t GetVotesFromScore(double score)
{
    return static_cast<int64_t>(score);
}

double IncrementVotes(double score, int32_t voteNum, int64_t activityTs)
{
    // 之前的投票数 + 本次投票数 + 时间戳小数位表示
    //
    // votenum.{Day}{Total seconds per day = Hour * Minutes * Seconds + Seconds}
    //
    // 保证小数仅有6位，这能让整数部分的精度能够正确的表示
    // int64_t nowTs     = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    // int64_t duration = nowTs - activityTs;

    // double digital = std::round(std::log10(duration)); // 获取数位，即结果有几位数
    // double max     = std::pow(10.0, digital);      // 数位 + 1 即获取下一个十位，将它与10的开方获取位的最大值
    // double decimal = (max - duration) / max;           // 计算小数点

    // return GetVotesFromScore(score) + voteNum + decimal;
    
    // double max = std::pow(10.0, 7.0);
    // double decimal = (max - g_num) / max;
    // return GetVotesFromScore(score) + voteNum + decimal;

    constexpr double max = 60 * 60 * 24 * (31 * 2); // 两个月

    // 之前的投票数 + 本次投票数 + 距离活动开始到现在时间段秒数的小数化表示
    double decimal = (max - g_num) / max;
    return GetVotesFromScore(score) + voteNum + decimal;
}

int main(void) {
  // double i = ULLONG_MAX;

  // uint64_t a = ULLONG_MAX;

  // int64_t b = std::round(i);

  // std::cout << std::setprecision(19) << i << std::endl;

  // std::cout << a << std::endl;

  // std::cout << b << std::endl;

   // int64_t b = LONG_MAX - 1;

   // std::cout << b << std::endl;

   // double a = *reinterpret_cast<double *>(&b);
   // std::cout << std::setprecision(19) << a << std::endl;
   // std::cout << std::isnan(a) << std::endl;

   // int64_t c = *reinterpret_cast<int64_t *>(&a);
   // std::cout << c << std::endl;

  // int64_t a = 0x3FFFFFFFFFFFFE - 3;
  // std::cout << a << std::endl;

  // double b = a;
  // std::cout << std::setprecision(19) << b << std::endl;

  // int64_t a = 0xFFFF;

  // double b = 0xFFFF;

  // double c = 2;

  // double d = 1.0 / c;

  // std::cout << std::setprecision(19) << d << std::endl;

  // double f = 1 + d;

  // std::cout << (int)f << std::endl;

  // double score = 0;

  // score = IncrementVotes(score, 200);
  // std::cout << std::setprecision(std::numeric_limits<double>::max_digits10 + 1) << score << std::endl;

  // score = IncrementVotes(score, 2021);
  // std::cout << std::setprecision(std::numeric_limits<double>::max_digits10 + 1) << score << std::endl;

  // score = IncrementVotes(score, 30);
  // std::cout << std::setprecision(std::numeric_limits<double>::max_digits10 + 1) << score << std::endl;

  // score = IncrementVotes(score, 5000000);
  // std::cout << std::setprecision(std::numeric_limits<double>::max_digits10 + 1) << score << std::endl;

  // score = IncrementVotes(score, 58753);
  // std::cout << std::setprecision(std::numeric_limits<double>::max_digits10 + 1) << score << std::endl;

  // std::time_t end_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  // std::tm* now = std::localtime(&end_time);

  // std::ostringstream buf;
  // buf << now->tm_mon + 1 << now->tm_mday << now->tm_hour << now->tm_min << now->tm_sec;

  // std::cout << buf.str() << std::endl;

  // typedef std::chrono::duration<std::uint32_t, std::ratio<3600 * 24>> day;

  g_num = 1;

  int64_t activityTs = 1638354886;
  double score = 0;
  while (true) {
    // auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()) % 1000;
    // std::cout << ms.count() << std::endl;

    // std::chrono::time_point<std::chrono::system_clock, day> day_getter;
    // std::cout << day_getter.time_since_epoch().count() << std::endl;

    int64_t vote_num = 0;
    std::cin >> vote_num;

    score = IncrementVotes(score, vote_num, activityTs);
    std::cout << std::setprecision(std::numeric_limits<double>::max_digits10 + 1) << score << std::endl;

    ++g_num;
    ++g_num;
  }

  return EXIT_SUCCESS;
}
