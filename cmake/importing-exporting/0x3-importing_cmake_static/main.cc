#include <iostream>

#include "MathFunctions.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    // report version
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  const double inputValue = std::stod(argv[1]);

  const double outputValue = MathFunctions::sqrt(inputValue);

  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
