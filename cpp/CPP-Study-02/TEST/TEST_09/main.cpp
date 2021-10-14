#include <iostream>
#include <random>

int main(void) {
    std::random_device dev;
    std::mt19937 rng(dev());

    for (int i = 0; i < 10; ++i) {
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, 10); // distribution random number in [1, playerData.size()]
        int postion = dist(rng);
      
        std::cout << postion << std::endl;
    }


  return -1;
}
