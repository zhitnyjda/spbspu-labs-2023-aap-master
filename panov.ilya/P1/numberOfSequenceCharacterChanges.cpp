#include "numberOfSequenceCharacterChanges.hpp"
#include <iostream>

long long numberOfSequenceCharacterChanges(std::istream& cin)
{
  int c, a, count = 0;
  std::cout << "enter a number \n";
  std::cin >> a;
  if (std::cin.fail())
  {
    std::cout << "You Can't Write In Letters";
    return 0;
  }
    while (true)
    {
      std::cin >> c;
      if (std::cin.fail())
      {
        std::cout << "You Can't Write In Letters";
        return 0;
      }
        if (c == 0)
        {
          break;
        }
      if ((a < 0 && c > 0) || (a > 0 && c < 0))
      {
      count++;
      a = c;
      } 
    }
    return count;
}
