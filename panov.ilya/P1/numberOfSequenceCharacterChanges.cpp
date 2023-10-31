#include "numberOfSequenceCharacterChanges.hpp"
#include <iostream>
#include <cmath>

long long numberOfSequenceCharacterChanges(std::istream& cin)
{
  int c, a, count = 0;
  std::cout << "enter a number \n";
  std::cin >> a;
  if (std::cin.fail())
  {
    std::cout << "You Can't Write In Letters";
    exit(-1);
  }
    while (true)
    {
      std::cin >> c;
      if (std::cin.fail())
      {
        std::cout << "You Can't Write In Letters";
        exit(-1);
      }
      if (c == 0)
      {
        break;
      }
      if ((c > a))
      {
        count++;
      }
  a = c;
  }
return count;
}

