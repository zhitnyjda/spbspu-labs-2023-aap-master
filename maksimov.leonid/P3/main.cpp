#include <iostream>
#include "comparison.hpp"
#include "delvow.hpp"
#include "addarr.hpp"
#include "delzero.hpp"

int main()
{
  size_t sizeStr = 10;
  char* str = new char[10]{};
  while (str[sizeStr - 2] != '\n')
  {
    try
    {
      str = addarr(std::cin, str, sizeStr);
      str = delzero(str, sizeStr);
    }
    catch (const std::exception& ex)
    {
      std::cerr << "Could not read an element of the string\n";
      return 1;
    }
  }
  for (size_t i = 0; i < sizeStr; i++)
  {
    std::cout << str[i] << '\t' << int(str[i]) << '\t' << i << '\n';
  }
  std::cout << "[HAS-SAM]: " << arr::comparison(str, sizeStr, "abc") << '\n';
  arr::delVow(str, sizeStr);
  std::cout << "[RMV-VOW]: ";
  for (size_t i = 0; i < sizeStr; i++)
  {
    std::cout << str[i];
  }
  delete[] str;
  return 0;
}
