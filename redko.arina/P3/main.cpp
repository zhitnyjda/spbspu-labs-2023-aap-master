#include <iostream>
#include "getString.hpp"
#include "buildWithoutInt.hpp"

int main()
{
  try
  {
    const int add = 10;
    char * str = new char[add];
    int lenght = redko::getString(str, add);
    char * strResult = new char[lenght];
    int lenResult = redko::buildWithoutInt(strResult, str, lenght);
    delete[] str;
    for (int i = 0; i < lenResult; i++)
    {
      std::cout << strResult[i];
    }
    delete[] strResult;
    return 0;
  }
  catch (std::bad_alloc)
  {
    std::cerr << "Error: can't allocate memory\n";
    return 1;
  }
}
