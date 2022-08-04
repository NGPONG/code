#include <iostream>
#include <memory>
#include <memory.h>

#include "ccronexpr.h"

auto get_time(time_t unix_timestamp) {
  auto time_buf = std::make_unique<char[]>(80);
  struct tm ts;
  ts = *localtime(&unix_timestamp);
  strftime(time_buf.get(), 80, "%a %Y-%m-%d %H:%M:%S %Z", &ts);

  return time_buf;
}

int main(void) {
  while (true) {
    std::string exp;
    getline(std::cin, exp);

    cron_expr expr;
    memset(&expr, 0, sizeof(expr));

    const char* err = NULL;
    cron_parse_expr(exp.c_str(), &expr, &err);
    if (err) {
      std::cout << err << std::endl;
      continue;
    }

    int32_t now = 1655755199;
    std::cout << "Now time is: " << get_time(now).get() << std::endl;

    std::cout << "start to get next 10 time schedule: " << std::endl;
    int32_t next = now;
    for (int i = 0; i < 10; ++i) {
      next = cron_next(&expr, next);
      std::cout << "\t" << get_time(next).get() << std::endl;
    }

    std::cout << "start to get previous 10 time schedule: " << std::endl;
    int32_t prev = now;
    for (int i = 0; i < 10; ++i) {
      prev = cron_prev(&expr, prev);
      std::cout << "\t" << get_time(prev).get() << std::endl;
    }
  }

  return EXIT_SUCCESS;
}
