#include <iostream>
#include "Header.hpp"

int main()
{
  int countmax = 0;
  try
  {
    countmax = count_loc_max(std::cin);
    std::cout << countmax;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
    return 1;
  }
}
