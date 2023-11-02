#include <iostream>
#include <limits>
#include "findmaxima.hpp"

int main()
{
  redko::FindMaxima findSecondMaxValue;
  const int minimum = std::numeric_limits< int > ::min();
  int value = 0;
  try
  {
    do
    {
      std::cin.exceptions(std::istream::failbit);
      std::cin >> value;
      if (findSecondMaxValue() == minimum && value == 0)
      {
        throw std::logic_error("Error: not enough values\n");
      }
      findSecondMaxValue(value);
    }
    while (value != 0);
    std::cout << findSecondMaxValue() << '\n';
    return 0;
  }
  catch (const std::istream::failure & e)
  {
    std::cerr << "Error: not a sequence\n";
    return 1;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what();
    return 2;
  }
}
