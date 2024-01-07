#include "neostring.hpp"
#include <iostream>
#include <iomanip>

namespace miheev
{
  size_t readString(char** receiver)
  {
    size_t receiverSize = 0;
    if (*receiver != nullptr)
    {
      while (*(*receiver + receiverSize) != '\0')
      {
        receiverSize++;
      }
    }
    const size_t additionalSize = 5;
    std::cin >> std::noskipws;
    char c = 0;
    size_t firstFree = 0;
    while (std::cin >> c)
    {
      if (firstFree >= receiverSize)
      {
        char* temp = new char[receiverSize + additionalSize]{};
        for (size_t i = 0; i < receiverSize; i++)
        {
          temp[i] = *(*receiver + i);
        }
        delete[] *receiver;
        *receiver = temp;
        receiverSize += additionalSize;
        temp = nullptr;
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
