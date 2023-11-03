#include <iostream>
#include <stdexcept>
#include "counter_minimums.hpp"

int main()
{
  using namespace popov;
  count_min_st count_min;
  int a;
  do
  {
    std::cin >> a;
    if (!std::cin)
    {
      std::cerr << "not a number\n";
      return 1;
    }
    if (a != 0)
    {
      try
      {
        count_min(a);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
      }
    }
  }
  while (a != 0);
  std::cout << count_min() << "\n";
  return 0;
}
