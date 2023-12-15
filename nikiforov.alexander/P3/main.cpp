#include <iostream>
#include <cstring>
#include <iomanip>
#include "Func.hpp"

using namespace nikiforov;
int main()
{
  try
  {
    char c = 0;
    size_t size = 0;
    size_t read = 0;
    char* str1 = new char[size] {};
    char* str2 = new char[size] {};
    std::cin >> std::noskipws;

    while ((std::cin >> c) && (c != '\n'))
    {
      nikiforov::AddElem(str1, size, read);
      str1[read++] = c;
    }

    size_t len1 = read;
    size = 0;
    read = 0;

    while ((std::cin >> c) && (c != '\n'))
    {
      nikiforov::AddElem(str2, size, read);
      str2[read++] = c;
    }

    size_t len2 = read;
    std::cin >> std::skipws;
    std::cout << '\n' << nikiforov::result(str1, str2, len1, len2) << '\n';
    
    delete[] str1;
    delete[] str2;
    return 0;
  }
  catch (const std::exception&)
  {
    std::cerr << "Memory allocation error!\n";
    return 1;
  }
}
