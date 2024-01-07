#include "neostring.hpp"
#include <iostream>
#include <iomanip>

namespace miheev
{
  size_t findSize(char* string)
  {
    size_t size = 0;
    if (string == nullptr)
    {
      return size;
    }
    while (string[size] != '\0')
    {
      size++;
    }
    return size;
  }
  void expandString(char** toExpand, size_t& receiverSize)
  {
    char* temp = new char[receiverSize + additionalSize]{};
    for (size_t i = 0; i < receiverSize; i++)
    {
      temp[i] = *(*toExpand + i);
    }
    delete[] *toExpand;
    *toExpand = temp;
    receiverSize += additionalSize;
    temp = nullptr;
  }

  size_t readString(char** receiver)
  {
    size_t receiverSize = 0;
    if (*receiver != nullptr)
    {
      size_t receiverSize = 0;
      while (*(*receiver + receiverSize) != '\0')
      {
        receiverSize++;
      }

    }
    size_t additionalSize = 5;
    std::cin >> std::noskipws;
    char c = 0;
    size_t firstFree = 0;
    while (std::cin >> c)
    {
      if (firstFree >= receiverSize)
      {
        expandString(receiver, receiverSize, additionalSize);
      }
      if (c == '\n')
      {
        *(*receiver + firstFree) = 0;
        break;
      }
      *(*receiver + firstFree++) = c;
    }
    std::cin >> std::skipws;
    return firstFree - 1;
  }
}
