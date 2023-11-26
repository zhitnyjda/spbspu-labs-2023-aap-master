#include <iostream>
#include "functions.hpp"

int main()
{
  try
  {
    int len = 0;
    const int add = 10;
    char* str = new char[add];
    char c;
    std::cin >> std::noskipws;
    do
    {
      std::cin >> c;
      str[len++] = c;
      if (len % add == 0)
      {
        char* strNew = new char[len + add];
        for (int i = 0; i < len; i++)
        {
          strNew[i] = str[i];
        }
        delete[] str;
        str = strNew;
      }
    } while (c != '\n');
    std::cin >> std::skipws;
    char* strResult = new char[len];
    int lenResult = redko::buildWithoutInt(strResult, str, len);
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
