#include <iostream>
#include <stdexcept>
#include "seqCounter.hpp"

int main()
{
  using namespace tellez;

  SequenceCounter sequenceCounter;

  while (true)
  {
    int value = 0;
    std::cin >> value;
    if (!std::cin)
    {
      std::cerr << "Not a valid input. Exiting...\n";
      return 1;
    }
    else if (value != 0)
    {
      try
      {
        sequenceCounter(value);
      }
      catch (const std::exception &e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
    else
    {
      break;
    }
  }
  std::cout << "Sequence count: " << sequenceCounter() << "\n";
  return 0;
}
