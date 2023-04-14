// #include <iostream>
// #include <vector>
// #include <string>

// #define PRINT_BODY true
// #define WITHOUT_BODY false

// void foo(int32_t msgId, std::string msg) {
//   std::cout << "1" << std::endl;
// }

// void foo(int32_t msgId, std::string msg, int32_t playerId) {
//   std::cout << "2" << std::endl;
// }

// void foo(int32_t msgId, std::string msg, bool printBody) {
//   std::cout << "3" << std::endl;
// }

// void foo(int32_t msgId, std::string msg, int32_t playerId, bool printBody) {
//   std::cout << "4" << std::endl;
// }

// #define FOO_1_ARGS(msgId, msg)                        foo(msgId, msg)
// #define FOO_2_ARGS(msgId, msg, playerId_or_printBody) foo(msgId, msg, playerId_or_printBody)
// #define FOO_3_ARGS(msgId, msg, playerId, printBody)   foo(msgId, msg, playerId, printBody)

// #define FOO_MARCOS(arg1, arg2, arg3, arg4, last, ...) last
// #define FOO_CHOOSER(...) \
//     FOO_MARCOS(__VA_ARGS__, FOO_3_ARGS, FOO_2_ARGS, FOO_1_ARGS)

// #define FOO(...) FOO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)


// int main(void) {
//   int32_t msg_id = 1;
//   std::string msg = "hello,world!";
//   int32_t player_id = 0x400;

//   FOO(msg_id, msg);
//   FOO(msg_id, msg, player_id);
//   FOO(msg_id, msg, PRINT_BODY);
//   FOO(msg_id, msg, WITHOUT_BODY);
//   FOO(msg_id, msg, player_id, PRINT_BODY);
//   FOO(msg_id, msg, player_id, WITHOUT_BODY);

//   return EXIT_SUCCESS;
// }


// #include <iostream>
// #include <vector>
// #include <string>

// #define PRINT_BODY PRINT_BODY
// #define WITHOUT_BODY WITHOUT_BODY

// void fooWITHOUT_BODY(int32_t msgId, std::string msg) {
//   std::cout << "1" << std::endl;
// }

// void fooWITHOUT_BODY(int32_t msgId, std::string msg, int32_t playerId) {
//   std::cout << "2" << std::endl;
// }

// void fooPRINT_BODY(int32_t msgId, std::string msg) {
//   std::cout << "3" << std::endl;
// }

// void fooPRINT_BODY(int32_t msgId, std::string msg, int32_t playerId) {
//   std::cout << "4" << std::endl;
// }

// #define FOO_3_ARGS(msgId, msg, token)           foo##token(msgId, msg)
// #define FOO_4_ARGS(msgId, msg, playerId, token) foo##token(msgId, msg, playerId)
// #define FOO_MARCOS(arg1, arg2, arg3, arg4, last, ...) last
// #define FOO_CHOOSER(...) \
//     FOO_MARCOS(__VA_ARGS__, FOO_4_ARGS, FOO_3_ARGS)
// #define FOO(...) FOO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)

// int main(void) {
//   int32_t msg_id = 1;
//   std::string msg = "hello,world!";
//   int32_t player_id = 0x400;

//   FOO(msg_id, msg, PRINT_BODY);
//   FOO(msg_id, msg, WITHOUT_BODY);

//   FOO(msg_id, msg, player_id, PRINT_BODY);
//   FOO(msg_id, msg, player_id, WITHOUT_BODY);

//   return EXIT_SUCCESS;
// }

#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <cstdint>

#define PRINT_BODY true
#define WITHOUT_BODY false

class PlayerId 
{
public:
  PlayerId(int32_t _id) : id(_id) {};

  int32_t id = 0x0;
};

void foo(int32_t, std::string, PlayerId, PlayerId) {}
void foo(int32_t, std::string, bool, bool) {}
void foo(int32_t msgId, std::string msg, PlayerId playerId, bool printBody) {
  std::cout << msgId << ",";
  std::cout << msg << ",";
  std::cout << playerId.id << ",";
  std::cout << printBody << std::endl;
}

#define FOO_1_ARGS(msgId, msg) \
  foo(msgId, msg, PlayerId(0x0), WITHOUT_BODY); \

#define FOO_2_ARGS(msgId, msg, playerId_or_printBody) \
  if constexpr (std::is_same_v<std::decay_t<decltype(playerId_or_printBody)>, bool>) \
  { \
    foo(msgId, msg, PlayerId(0x0), playerId_or_printBody); \
  } \
  else \
  { \
    foo(msgId, msg, playerId_or_printBody, WITHOUT_BODY); \
  } \

#define FOO_3_ARGS(msgId, msg, playerId, printBody) \
  foo(msgId, msg, playerId, printBody); \

#define FOO_MARCOS(arg1, arg2, arg3, arg4, last, ...) last
#define FOO_CHOOSER(...) \
    FOO_MARCOS(__VA_ARGS__, FOO_3_ARGS, FOO_2_ARGS, FOO_1_ARGS)

#define FOO(...) FOO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)

int main(void) {
  int32_t msg_id = 1;
  std::string msg = "hello,world!";
  PlayerId player_id(0x400);

  const int32_t v = 10;
  if constexpr (v == 10) 
  {
    static_assert(std::true_type::value, "hello,world!");
  }
  else 
  {
    static_assert(std::false_type::value, "hello,world!");
  }

  // FOO(msg_id, msg);
  // FOO(msg_id, msg, player_id);
  // FOO(msg_id, msg, PRINT_BODY);
  // FOO(msg_id, msg, WITHOUT_BODY);
  // FOO(msg_id, msg, player_id, PRINT_BODY);
  // FOO(msg_id, msg, player_id, WITHOUT_BODY);

  return EXIT_SUCCESS;
}
