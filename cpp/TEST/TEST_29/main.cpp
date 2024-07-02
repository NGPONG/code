#include <iostream>
#include <string>
#include <vector>

#define LEV_OPT_LEAVE_SOCKETS_BLOCKING	(1u<<0)
#define LEV_OPT_CLOSE_ON_FREE		(1u<<1)
#define LEV_OPT_CLOSE_ON_EXEC		(1u<<2)
#define LEV_OPT_REUSEABLE		(1u<<3)
#define LEV_OPT_THREADSAFE		(1u<<4)
#define LEV_OPT_DISABLED		(1u<<5)

enum MonopolyEventDataReset {
  RESOURCE       = 1u << 0,
  SHOP           = 1u << 1,
  TRY_SHOP       = 1u << 2,
  SQUARES        = 1u << 3,
  TRY_SQUARES    = 1u << 4,
  ROUNDS         = 1u << 5,
  HELP_CHALLENGE = 1u << 6,
  POWER_CONSUME  = 1u << 7,
  NOT_RESET_TS   = 1u << 8,
};

template <typename T, typename std::enable_if<std::is_integral<T>::value>::type * = nullptr>
T foo() { std::cout << "integral" << std::endl; return T(); }

template < typename T, typename std::enable_if< !std::is_integral<T>::value>::type * = nullptr >
T foo() {
  if (std::is_same<T, std::string>::value) {
    std::cout << "string" << std::endl;
  } else if (std::is_same<T, float>::value) {
    std::cout << "float" << std::endl;
  } else {
    std::cout << "non intergal" << std::endl;
  }

  return T(); 
}

int main(void) {
  // unsigned flags = SHOP | SQUARES | TRY_SQUARES | ROUNDS | HELP_CHALLENGE | TRY_SHOP;

  // if (flags & MonopolyEventDataReset::RESOURCE)
  //   std::cout << "RESOURCE" << std::endl;

  // if (flags & MonopolyEventDataReset::SHOP)
  //   std::cout << "SHOP" << std::endl;

  // if (flags & MonopolyEventDataReset::SQUARES)
  //   std::cout << "SQUARES" << std::endl;

  // if (flags & MonopolyEventDataReset::ROUNDS)
  //   std::cout << "ROUNDS" << std::endl;

  // if (flags & MonopolyEventDataReset::HELP_CHALLENGE)
  //   std::cout << "HELP_CHALLENGE" << std::endl;

  // if (flags & MonopolyEventDataReset::POWER_CONSUME)
  //   std::cout << "POWER_CONSUME" << std::endl;

  // if (!(flags & MonopolyEventDataReset::NOT_RESET_TS))
  //   std::cout << "NOT RESET" << std::endl;

  // if (flags & TRY_SHOP)
  //   std::cout << "TRY_SHOP" << std::endl;

  // if (flags & TRY_SQUARES)
  //   std::cout << "TRY_SQUARES" << std::endl;

  foo<int>();

  foo<int32_t>();

  foo<float>();

  foo<std::string>();

  foo<std::vector<int>>();

  foo<void *>();

  foo<int *>();

  return EXIT_SUCCESS;
}
