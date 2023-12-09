#include <iostream>
#include <cstring>
#include <string.h>
#include "myStruct.hpp"

size_t countGlobal = 0;

int main()
{
  //size_t countGlobal = 0;
  using namespace mihalchenko;

  char element = 0;

  DinString s1(1, '0');
  DinString s2(1, '0');

  std::cin >> std::noskipws;

  while ((std::cin >> element) && (element != '\n'))
  {
    if (s1.counterCurrent < s1.size)
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
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
        return 1;
      }
    }
  }
  s1.dinOutput();

  while ((std::cin >> element) && (element != '\n'))
  {
    if (s2.counterCurrent < s2.size)
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

  char * resultStr;
  size_t counterLenMas;
  countGlobal = 0;
  resultStr = findIdenticalChars(s1.dinstr, s2.dinstr, s1.size, s2.size);
  (s1.size > s2.size) ? (counterLenMas = s2.size) : (counterLenMas = s1.size);
  counterLenMas = arr_uniq(resultStr, countGlobal);

  for (size_t i = 0; i < counterLenMas; i++)
  {
    std::cout << resultStr[i];
  }
  std::cout << std::endl;

  delete[] resultStr;
  return 0;
}
