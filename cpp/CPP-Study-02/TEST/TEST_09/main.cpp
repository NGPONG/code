#include <iostream>
#include <time.h>
#include <ctime>
#include <string>
#include <string.h>

unsigned char awardSchedule = 0;

enum {
  UPGRADETOP,
  PVPPOINT,
  SEASONAWARD,
  MAXTYPE = 3
};

bool IsAvailableFlag(const unsigned char Type) {
  return Type < MAXTYPE && awardSchedule & ((unsigned char)(1) << Type);
}

bool SetAvailableFlag(const unsigned char Type, const char flag = 1) {
  if (Type >= MAXTYPE) {
    return false;
  }
  if (1 == flag) {
    awardSchedule |= ((unsigned char)(1) << Type);
  } else {
    awardSchedule &= ~((unsigned char)(1) << Type);
  }
  return true;
}

int main(void) {
  std::cout << (int)awardSchedule << std::endl;

  // SetAvailableFlag(UPGRADETOP);
  // std::cout << (int)awardSchedule << std::endl;

  SetAvailableFlag(PVPPOINT);
  std::cout << (int)awardSchedule << std::endl;

  SetAvailableFlag(SEASONAWARD);
  std::cout << (int)awardSchedule << std::endl;

  return 0;
}
