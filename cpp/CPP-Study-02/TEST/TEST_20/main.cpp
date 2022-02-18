#include <iostream>
#include <chrono>

using f_minutes = std::chrono::duration<double, std::chrono::minutes::period>;

int main() {

  //get the starting number of minutes
  double input;
  std::cout << "Enter number of minutes: ";
  std::cin >> input;

  f_minutes decimalMinutes(input);

  auto mins = duration_cast<std::chrono::minutes>(decimalMinutes);
  decimalMinutes -= mins;

  //output days, hours, minutes and seconds
  std::cout << mins.count() << "h " << std::endl;
}
