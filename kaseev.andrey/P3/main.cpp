#include "string.hpp"
#include <iostream>

int main()
{
  char* str1 = kaseev::readLine();
  char* str2 = kaseev::readLine();
  try
  {
    char *newStr = kaseev::interleaveStrings(str1, str2);
    delete[] str1;
    delete[] str2;
    if (newStr == nullptr)
    {
      delete[] newStr;
      throw std::logic_error("Invalid input");
    }
    std::cout << newStr;
    delete[] newStr;
    return 0;
  }
  catch (std::exception &err)
  {
    std::cerr << err.what() << "\n";
    return 1;
  }
}
