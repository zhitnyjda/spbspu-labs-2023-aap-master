#include <iostream>
#include <iomanip>
#include "checkChars.hpp"
int main()
{
  std::cin >> std::noskipws;
  size_t read = 0, size = 0;
  char Char = 0;
  char * array = new char[size]{};
  while ((std::cin >> Char) && (Char != '\n'))
  {
    array[read++] = Char;
    if (read == size)
    {
      try
      {
        char * newarray = new char[size + add]{};
        for(size_t i = 0; i < size; i++)
        {
          newarray[i] = array[i];
        }
        delete[] array;
        char * array = newarray;
        delete[] newarray;
        size += add;
      }
      catch(const std::bad_alloc &e)
      {
        std::cerr << "Error big\n";
        return 1;
      }
    }
  }
  delete[] array;
  return 0;
}
