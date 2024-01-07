#include <iostream>
#include <cstring>
#include <string.h>
#include "dinString.hpp"

size_t countGlobal = 0;

int main()
{
  using namespace mihalchenko;

  char element = 0;

  DinString s1(1);
  DinString s2(1);

  std::cin >> std::noskipws;

  while ((std::cin >> element) && (element != '\n'))
  {
    if (s1.getCounterCurrent() < s1.getSize())
    {
      s1.dinAppend(element);
    }
    else
    {
      try
      {
        s1.dinResize();
        s1.dinAppend(element);
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << '\n';
        return 1;
      }
    }
  }
  s1.dinOutput();

  while ((std::cin >> element) && (element != '\n'))
  {
    if (s2.getCounterCurrent() < s2.getSize())
    {
      s2.dinAppend(element);
    }
    else
    {
      s2.dinResize();
      s2.dinAppend(element);
    }
  }
  s2.dinOutput();

  char *resultStr = nullptr;
  size_t counterLenMas = 0;
  countGlobal = 0;
  resultStr = findIdenticalChars(s1.getDinstr(), s2.getDinstr(), s1.getSize(), s2.getSize());
  (s1.getSize() > s2.getSize()) ? (counterLenMas = s2.getSize()) : (counterLenMas = s1.getSize());

  counterLenMas = arrUniq(resultStr, countGlobal);

  for (size_t i = 0; i < counterLenMas; i++)
  {
    std::cout << resultStr[i];
  }
  std::cout << std::endl;

  if (resultStr != nullptr)
  {
    delete[] resultStr;
  }
  return 0;
}
