#include <iostream>
#include <string>
#include <string.h>
#include "myStruct.hpp"
 
//size_t addArr = 10;
 
int main()
{
  char element = 0;    
  DinString s1(10, '0');
  DinString s2(10, '0');
 
  std::cin >> std::noskipws;
 
  while ((std::cin >> element) && (element != '\n'))
  {
    if (s1.counterCurrent < s1.size)
    {
        s1.dinAppend(element);
    }
    else
    {
        s1.dinResize();
        s1.dinAppend(element);
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
  return 0;
}
