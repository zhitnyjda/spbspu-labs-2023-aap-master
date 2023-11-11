#include <iostream>
#include <stdexcept>
#include "seqCounter.hpp"

int main ()
{
  int num = 0;
  yartsev::Counter counter;
  do {
    std::cin >> num;
    if (!std::cin) {
      std::cerr << "Error: Not a sequence\n";
      return 1;
    } else if (num != 0) {
      try {
        counter(num);
      } catch (const std::exception & e) {
        std::cerr << "Error: " << e.what() << "\n";
        std::cout << counter.getMaxSequence() << "\n";
        return 2;
      }
    }
  } while (num != 0);
  std::cout << counter.getMaxSequence() << "\n" << counter.getMinCounter() << "\n";
  return 0;
}
