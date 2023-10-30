#include <iostream>
#include <execution>
#include "Lessmore.hpp"

int main()
{
  int prev = 0;
  int curr = 0;
  int next = 9999;
  int countnum = 0;
  int countres = 0;
  std::cin.exceptions(std::cin.failbit);
  while (next != 0)
  {
    try
    {
      std::cin >> next;
      lessmore(prev,curr, next, &countnum, &countres);
      prev = curr;
      curr = next;
    }
    catch (const std::exception &ex)
    {
      return 1;
    }
  }
  std::cout << countres;
  return 0;
}
