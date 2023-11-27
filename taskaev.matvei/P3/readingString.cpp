#include "readingString.hpp"
#include "formingString.hpp"

char* taskaev::readingString(std::istream& input)
{
  int size = 10;
  int newSize = 0;
  char* string = new char[size]{};
  char c = 0;
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
    string[newSize++] = c;
  }
  while ((input >> c) && (c != '\n')
  if (!string[0])
  {
    throw std::logic_error("The string is remowed, no string.");
  }
  input >> std::skipws;
  return string;
}
