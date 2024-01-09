#include "newarr.hpp"
#include "delzero.hpp"

char* newarr(std::istream& in, size_t& sizeStr)
{
  size_t lenStr = 10;
  char* str = new char[lenStr]{};
  char temp = 0;
  size_t dataIndex = 0;
  in >> std::noskipws;
  while (in >> temp && temp != '\n')
  {
    dataIndex++;
    if (dataIndex < lenStr)
    {
      str[dataIndex] = temp;
    }
    else
    {
      lenStr *= 2;
      char* newStr = new char[lenStr]{};
      for (size_t i = 0; i < lenStr; i++)
      {
        newStr[i] = str[i];
      }
      delete[] str;
      str = newStr;
    }
  }
  if (temp == 0)
  {
    delete[] str;
    throw std::exception();
  }
  in >> std::skipws;
  str = delzero(str, lenStr);
  sizeStr = lenStr;
  return str;
}
