#include <iostream>
#include <bitset>
#include <vector>

enum class BotArenaChallengeNum : unsigned {
  One = 0,    // 第一次挑战
  Two,        // 第二次挑战
  last,       // 最后一次挑战
};

enum class BotArenaChallengeResult : unsigned {
  None = 1,  // 未挑战
  Win  = 2,  // 胜利
  Lose = 4,  // 失败
};


unsigned InitChallengeResult() {
  unsigned ret = 0;

  for (auto challengeNum : { 0, 1, 2 }) {
    unsigned res = static_cast<unsigned>(BotArenaChallengeResult::None);
    unsigned step = 3 * static_cast<unsigned>(challengeNum);

    ret += (res << step);
  }

  return ret;
}

unsigned AppendChallengeResult(const unsigned res, const BotArenaChallengeResult result) {
  for (auto challengeNum : { 0, 1, 2 }) {
    unsigned step = 3 * static_cast<unsigned>(challengeNum);
    unsigned mask = 0b0111 << step;
    
    if (((res & mask) >> step) == static_cast<unsigned>(BotArenaChallengeResult::None) || challengeNum == 2) {
      return (res & ~mask) | (static_cast<unsigned>(result) << step);
    }
  }

  return res;
}

BotArenaChallengeResult GetChallengeResult(const unsigned res, const BotArenaChallengeNum challengeNum) {
  unsigned step = 3 * static_cast<unsigned>(challengeNum);
  unsigned mask = 0b0111 << step;
  return static_cast<BotArenaChallengeResult>((res & mask) >> step);
}

int main(void) {
  std::bitset<9> bs = InitChallengeResult();
  std::cout << bs.to_string() << std::endl;

  bs = AppendChallengeResult(bs.to_ulong(), BotArenaChallengeResult::Lose);
  std::cout << bs.to_string() << std::endl;

  bs = AppendChallengeResult(bs.to_ulong(), BotArenaChallengeResult::Win);
  std::cout << bs.to_string() << std::endl;

  bs = AppendChallengeResult(bs.to_ulong(), BotArenaChallengeResult::None);
  std::cout << bs.to_string() << std::endl;

  bs = AppendChallengeResult(bs.to_ulong(), BotArenaChallengeResult::Lose);
  std::cout << bs.to_string() << std::endl;

  bs = AppendChallengeResult(bs.to_ulong(), BotArenaChallengeResult::Win);
  std::cout << bs.to_string() << std::endl;

  bs = AppendChallengeResult(bs.to_ulong(), BotArenaChallengeResult::None);
  std::cout << bs.to_string() << std::endl;

  bs = AppendChallengeResult(bs.to_ulong(), BotArenaChallengeResult::None);
  std::cout << bs.to_string() << std::endl;

  bs = AppendChallengeResult(bs.to_ulong(), BotArenaChallengeResult::Win);
  std::cout << bs.to_string() << std::endl;

  bs = AppendChallengeResult(bs.to_ulong(), BotArenaChallengeResult::Lose);
  std::cout << bs.to_string() << std::endl;

  bs = AppendChallengeResult(bs.to_ulong(), BotArenaChallengeResult::Win);
  std::cout << bs.to_string() << std::endl;

  bs = AppendChallengeResult(bs.to_ulong(), BotArenaChallengeResult::None);
  std::cout << bs.to_string() << std::endl;

  std::cout << "================" << std::endl;

  BotArenaChallengeResult res1 = GetChallengeResult(bs.to_ulong(), BotArenaChallengeNum::One);
  BotArenaChallengeResult res2 =GetChallengeResult(bs.to_ulong(), BotArenaChallengeNum::Two);
  BotArenaChallengeResult res3 =GetChallengeResult(bs.to_ulong(), BotArenaChallengeNum::last);

  return EXIT_SUCCESS;
}
