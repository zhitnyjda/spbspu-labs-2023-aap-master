#include "readingString.hpp"
#include "formingString.hpp"

char * taskaev::readingString(std::istream& input, int size, int newSize)
{
  char* string = new char[size];
  int sizeNum = 0;
  input >> std::noskipws;
  do
  {
    if (size == sizeNum)
    {
      char * newString = taskaev::formingString(string, sizeNum, newSize);
      delete[] string;
      string = newString;
      size += newSize;
    }
  }
  while ((input >> string[sizeNum] ) && (string[sizeNum++] != '\n'));
  string[sizeNum != 0 ? sizeNum - 1 : sizeNum] = '\0';
  if (string[0] == '\0')
  {
    delete[] string;
    return string;
  }
  input >> std::skipws;
  return string;
}
