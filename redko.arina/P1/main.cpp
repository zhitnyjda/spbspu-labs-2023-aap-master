#include "findmaxima.hpp"
#include <iostream>
#include <limits>

int main()
{
  try
  {
    int firstMaxValue = std::numeric_limits< int > ::min();
    int secondMaxValue = std::numeric_limits< int > ::min();
    int value = 0;
    std::cin.exceptions(std::istream::failbit);
    std::cin >> value;
    while (value != 0)
    {
      redko::findMaxima(value, firstMaxValue, secondMaxValue);
      std::cin >> value;
    }
    if (secondMaxValue == std::numeric_limits< int > ::min() && value == 0)
    {
      throw std::logic_error("Error: not enough values");
    }
    std::cout << secondMaxValue << '\n';
    return 0;
  }
  catch (const std::istream::failure& e)
  {
    std::cerr << "Error: invalid sequence" << '\n';
    return 1;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << '\n';
    return 2;
  }
}
