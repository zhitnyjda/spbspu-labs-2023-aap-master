#include <iostream>
#include "findCount.hpp"

int main()
{
  size_t value = 0;
  using namespace gorbunova;
  FindCount findCount;
  do
  {
    std::cin >> value;
    if (!std::cin)
    {
      std::cerr << "Wrong input\n";
      return 1;
    }
    else if (value != 0)
    {
      findCount(value);
    }
  }
  while (value != 0);
  try
  {
    std::cout << findCount() << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }
}
