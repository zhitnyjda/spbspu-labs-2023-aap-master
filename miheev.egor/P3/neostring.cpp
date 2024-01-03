#include "neostring.hpp"
#include <iostream>
#include <iomanip>

namespace miheev
{
  void expandString(char* toExpand, size_t& receiverSize, size_t additionalSize)
  {
    char* temp = new char[receiverSize]{};
    for (size_t i = 0; i < receiverSize; i++)
    {
      temp[i] = toExpand[i];
    }
    delete[] toExpand;
    toExpand = temp;
    receiverSize += additionalSize;
    temp = nullptr;
  }

  size_t readString(char* receiver, size_t receiverSize)
  {
    size_t additionalSize = 20;
    std::cin >> std::noskipws;
    char c = 0;
    size_t firstFree = 0;
    while (std::cin >> c)
    {
      if (c == '\n')
      {
        receiver[firstFree] = 0;
        break;
      }
      if (firstFree == receiverSize)
      {
        expandString(receiver, receiverSize, additionalSize);
      }
      receiver[firstFree] = c;
      firstFree++;
    }
    std::cin >> std::skipws;
    return firstFree - 1;
  }
}