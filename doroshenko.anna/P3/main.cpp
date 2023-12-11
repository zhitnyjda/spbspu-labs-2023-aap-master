#include <iostream>
#include <iomanip>
#include <iosfwd>
#include "resizeArray.hpp"

int main()
{
  char ch = 0;
  size_t readEl = 0;
  size_t size = 20;
  try
  {
    char* input = new char [size] {};
    std::cin >> std::noskipws;
    while (std::cin >> ch)
    {
      if (ch == "\0")
      {
        std::cerr << "Could not read an element of the string\n";
        return 1;
      }
      else if (readEl < size)
      {
        input[readEl++] = ch;
        if (ch == '\n')
        {
          input[readEl - 1] = 0;
          break;
        }
      }
      else
      {
        input = doroshenko::resizeArray(input, size, size + 20);
        size += 20;
        input[readEl++] = ch;
      }
    }
    bool pair = false;
    for (size_t i = 0; i < readEl - 1; i++)
    {
      for (size_t j = i + 1; j < readEl; j++)
      {
        if (input[i] == input[j])
        {
          pair = true;
          input[j] = '\0';
        }
      }
      if (pair == true)
      {
        std::cout << input[i];
        input[i] = '\0';
        pair = false;
      }
    }
    std::cin >> std::skipws;
    std::cout << input << '\n';
    delete[] input;
    return 0;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Allocation error\n";
    return 1;
  }
}
