#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
#include <climits>
#include <map>
#include <thread>
#include <vector>

int32_t g_ts = 1750003341;

inline int64_t NFGetTime() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

inline int64_t NFGetTimeSec() {
	return NFGetTime() / 1000;
}

double CvrtSteps2Score(int32_t steps) {
  // return ((int64_t)steps << 32) + (int64_t)(INT_MAX - (int32_t)NFGetTimeSec());

  ++g_ts;
  return ((int64_t)steps << 32) + (int64_t)(INT_MAX - g_ts);
}

double CvrtSteps2Score(int32_t steps, int32_t ts) {
  return ((int64_t)steps << 32) + (int64_t)(ts);
}

int32_t GetStepsFromScore(double score) {
    return (int64_t)score >> 32;
}

int main(void) {
  std::map<int32_t, std::map<int32_t, int32_t>> m;

  std::vector<std::thread> threads;

  for (int32_t i = 0; i < INT_MAX; ++i) {
    for (int32_t j = 0; j < 99999999; ++j) {
      double score = CvrtSteps2Score(i, j);
      int32_t step = GetStepsFromScore(score);

      if (step != i) {

      }
    }
  }

  for (auto& th : threads)
    th.join();

  return EXIT_SUCCESS;
}

