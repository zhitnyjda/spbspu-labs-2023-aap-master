#include "funcs.hpp"
#include <iostream>

namespace sobolevsky
{
  size_t matrix::countMatrix(std::ifstream& in, size_t counter)
  {
    char i;
    while (!in.eof()) 
    {
        in.get(i);
        if (isdigit(i))
        {
          counter++;
        }
        else
        {
          std::cerr << ("в матрице могут быть только числа\n");
          return 2;
        }
    }
    return counter;
  }


}