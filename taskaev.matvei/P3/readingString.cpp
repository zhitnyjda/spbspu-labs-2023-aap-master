#include "readingString.hpp"

char* taskaev::readingString(std::istream& input)
{
  size_t size = 10;
  size_t newSize = 0;
  char* string = new char[size];
  input >> std::noskipws;
  do
  {
    if ( size == newSize)
    {
      try
      {
        char* newString = taskaev::formingString(string, size, newSize);
        delete[] string;
        string = newString;
      }
      catch (const std::exception& e)
      {
        delete[] string;
        throw std::error_bad("Error forming string.");
      }
    }
  }
  while ((input >> string[newSize]) && (string[newSize++] != '\n')
  if (newSize == 0)
  {
    string[0] = '\0';
    return string;
  }
  string[newSize - 1] = '\0';
  return string;
}
