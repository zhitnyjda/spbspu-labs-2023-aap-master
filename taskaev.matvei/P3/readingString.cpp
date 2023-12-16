#include "readingString.hpp"
#include "formingString.hpp"
#include <iostream>
#include <iomanip>

char * taskaev::readingString(std::istream& input)
{
  int size = 10;
  int newSize = 0;
  char* string = new char[size];
  input >> std::noskipws;
  do
  {
    if (size == newSize)
    {
      try
      {
        char * newString = taskaev::formingString(string, size, newSize);
        delete[] string;
        string = newString;
      }
      catch (const std::exception& e)
      {
        delete[] string;
        throw std::logic_error("Error: forming string, couldn't reed the string.");
      }
    }
  }
  while ((input >> string[newSize] ) && (string[newSize++] != '\n'));
  string[newSize != 0 ? newSize - 1 : newSize] = '\0';
  if (!string[0])
  {
    delete[] string;
    throw std::logic_error("Error: nothing was entered, an empty input.");
  }
  input >> std::skipws;
  return string;
}
