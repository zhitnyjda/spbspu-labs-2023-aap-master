#include "dopFunc.hpp"
#include <iostream>
#include <cctype>

bool mihalchenko::ifAlp(char* argv1)
{
  unsigned int c = 0;
  bool fl = true;

  while (argv1[c] && fl)
  {
    if (std::isalpha(argv1[c]) == true)
    {
      fl = false;
      std::cout << argv1[c];
      break;
    }
    else
    {
      std::cout << argv1[c];
      fl = true;
    }
    c++;
  }
  return fl;
}
