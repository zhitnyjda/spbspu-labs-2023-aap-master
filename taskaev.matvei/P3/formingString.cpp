#include "formingString.hpp"

char* taskaev::formingString(const char* string, size_t& size, size_t newSize)
{
  char* newString = new char[size + 10];
  for (size_t i = 0; i < newSize; i++)
  {
	newString[i] = string[i];
  }
  newSize += 10;
  return newString;
}
