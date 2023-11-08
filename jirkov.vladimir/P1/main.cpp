#include <iostream>
#include "findingCount.hpp"
using namespace jirkov;
int main()
{
  size_t prev = 0;
  size_t current = 0;
  size_t next = 0;
  FindingCount findingCount;
  std::cin >> prev;
  std::cin >> current;
  do
  {
    std::cin >> next;
    if (!std::cin)
    {
      std::cerr << "Wrong input\n";
      return 1;
    }
    if (next != 0)
    {
    findingCount(prev, current, next);
    prev = current;
    current = next;
    }
  } while (next != 0);
  try
  {
    std::cout << findingCount() << "\n";
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 2;
  }
}
