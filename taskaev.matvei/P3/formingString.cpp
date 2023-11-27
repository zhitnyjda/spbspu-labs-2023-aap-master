#include "formingString.hpp"

char* taskaev::formingString(const char* string, int& size, int newSize)
{
  char* newString = new char[size + 10];
  for (int i = 0; i < newSize; i++)
  {
	newString[i] = string[i];
  }
  newSize += 10;
  return newString;
}
