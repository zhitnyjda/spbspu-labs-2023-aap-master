#include <iostream>
#include "pushback.hpp"
#include "comparison.hpp"
#include "delvow.hpp"

int main()
{
  std::cin >> std::noskipws;
  size_t sizeStr = 0;
  char* str = new char[0]{};
  bool flag = 1;
  while (flag)
  {
    try
    {
      arr::pushBack(sizeStr, str, flag);
    }
    catch (const std::exception& ex)
    {
      std::cerr << ex.what();
    }
  }
  std::cout << "[HAS-SAM]: " << arr::comparison(str, sizeStr, "abc") << '\n';
  arr::delVow(str, sizeStr);
  std::cout << "[RMV-VOW]: ";
  for (size_t i = 0; i < sizeStr; i++)
  {
    std::cout << str[i];
  }
  std::cin >> std::skipws;
  delete[] str;
  return 0;
}
