#include <iostream>

unsigned char awardSchedule = 0;

enum {
  TREASURE_LEVEL_EASY,
  TREASURE_LEVEL_NORMAL,
  TREASURE_LEVEL_HARD,
  MAXTYPE = 3
};
bool IsValAvailableFlag(const unsigned char val, const unsigned char levelType) {
  return levelType < MAXTYPE && val & ((unsigned char)(1) << levelType);
}
bool SetValAvailableFlag(unsigned char* val, const unsigned char levelType, const char flag = 1) {
  if (levelType >= MAXTYPE) return false;
  *val |= ((unsigned char)(1) << levelType);
  return true;
}


int main(void) {
  std::cout << (int)awardSchedule << std::endl;

  SetValAvailableFlag(&awardSchedule, TREASURE_LEVEL_NORMAL);
  std::cout << (int)awardSchedule << std::endl;
  
  awardSchedule = 0;

  SetValAvailableFlag(&awardSchedule, TREASURE_LEVEL_EASY);
  std::cout << (int)awardSchedule << std::endl;

  return 0;
}
