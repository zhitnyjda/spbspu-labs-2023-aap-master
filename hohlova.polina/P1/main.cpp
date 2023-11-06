#include <iostream>
#include <stdexcept>
#include <limits>
#include "Lessmore.hpp"

int main()
{
  int prev = 0;
  int curr = 0;
  int next = 0;
  size_t countres = 0;
  using namespace hohlova;
  LessMore LessMore;
  do
  {
    std::cin >> next;
    if (!std::cin)
    {
      std::cerr << "Not a sequence\n";
      return 1;
    }
    else if (next != 0)
    {
      try
      {
        LessMore(prev, curr, next);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
      }
      prev = curr;
      curr = next;
    }
  }
  while (next != 0);
  std::cout << LessMore() << "\n";
}

