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

#include "cron.hpp"
#include "datetime.hpp"

int main(void) {
  KWCron cron("0 * * * *");

  int64_t now = KWDateTime::KWGetTimeMS();
  for (int i = 0; i < 5; ++i) {
    now = cron.CronToNext(now);
  }
  return EXIT_SUCCESS;
}
