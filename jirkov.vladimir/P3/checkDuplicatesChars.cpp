#include "checkDuplicatesChars.hpp"

size_t checkDuplicatesChars(const char* str, size_t size)
{
  for (size_t i = 0; i < size - 1; i++)
  {
    if (str[i] == str[i + 1])
    {
      return 1;
    }
  }
  return 0;
}
