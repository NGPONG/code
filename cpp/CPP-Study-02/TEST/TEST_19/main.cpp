#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

int main(void) {
  std::string channel_id = "012";
  std::string zone_id = "003";
  int32_t digital_id = 123456;

  std::stringstream ss(std::stringstream::in | std::stringstream::out);
  ss << std::setw(3) << std::setfill('0') << channel_id;
  ss << std::setw(3) << std::setfill('0') << zone_id;
  ss << std::setw(6) << std::setfill('0') << digital_id;

  std::cout << ss.str() << std::endl;

  return EXIT_SUCCESS;
}
