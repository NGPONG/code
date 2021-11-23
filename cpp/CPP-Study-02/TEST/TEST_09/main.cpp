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
  MAXTYPE = 7
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

  
    SetAvailableFlag(PVPPOINT);
std::cout << (int)awardSchedule << std::endl;
  SetAvailableFlag(PVPPOINT);
std::cout << (int)awardSchedule << std::endl;
  SetAvailableFlag(PVPPOINT);
std::cout << (int)awardSchedule << std::endl;
  SetAvailableFlag(PVPPOINT);
std::cout << (int)awardSchedule << std::endl;
  SetAvailableFlag(PVPPOINT);
  SetAvailableFlag(PVPPOINT);
  SetAvailableFlag(PVPPOINT);

  if (IsAvailableFlag(UPGRADETOP)) {
    std::cout << "1" << std::endl;
  }
  SetAvailableFlag(UPGRADETOP);
  if (IsAvailableFlag(UPGRADETOP)) {
    std::cout << "2" << std::endl;
  }
  SetAvailableFlag(UPGRADETOP, 0);
  if (IsAvailableFlag(UPGRADETOP)) {
    std::cout << "3" << std::endl;
  }
  if (IsAvailableFlag(PVPPOINT)) {
    std::cout << "4" << std::endl;
  }

  return 0;
}
