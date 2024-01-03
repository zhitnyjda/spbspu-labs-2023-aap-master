#include "neostring.hpp"
#include <iostream>
#include <iomanip>

namespace miheev
{
  void expandString(char** toExpand, size_t& receiverSize, size_t additionalSize)
  {
    char* temp = new char[receiverSize + additionalSize]{};
    for (size_t i = 0; i < receiverSize; i++)
    {
      temp[i] = (*toExpand)[i];
    }
    delete[] *toExpand;
    *toExpand = temp;
    receiverSize += additionalSize;
    temp = nullptr;
  }

  size_t readString(char** receiver, size_t receiverSize)
  {
    size_t additionalSize = 5;
    std::cin >> std::noskipws;
    char c = 0;
    size_t firstFree = 0;
    while (std::cin >> c)
    {
      if (firstFree >= receiverSize)
      {
        std::cout << *(*receiver + firstFree - 1) << '\n';
        expandString(receiver, receiverSize, additionalSize);
      }
      if (c == '\n')
      {
        std::cout << "first free - " << firstFree << "\nsize - " << receiverSize << '\n';
        std::cout << *(*receiver + firstFree - 1) << '\n';
        *(*receiver + firstFree) = 0;
        break;
      }
      std::cout << c << '\n' << "ff = " << firstFree << '\n';
      *(*receiver + firstFree++) = c;
    }
    std::cin >> std::skipws;
    return firstFree - 1;
  }
}
