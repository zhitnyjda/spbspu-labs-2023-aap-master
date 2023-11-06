#include <iostream>
#include "divCounter.hpp"

int main()
{
  int number;
  int seq_length = 0;
  using namespace shagieva;
  DivCounter divCounter;

  do
  {
    std::cin >> number;

    if (!std::cin)
    {
      std::cerr << "Not a sequence.\n";
      return 1;
    }

    else if (number != 0)
    {
      ++seq_length;
      try
      {
        divCounter(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error" << e.what() << "\n";
        return 2;
      }
    }
  }
  while (number != 0);

  if (seq_length < 2)
  {
    std::cerr << "The sequence is too short.\n";
    return 2;
  }

  std::cout << divCounter() << "\n";
  return 0;
}

