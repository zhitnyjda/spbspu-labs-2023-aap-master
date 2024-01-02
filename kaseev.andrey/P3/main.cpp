#include <iostream>
#include "WorkWithString.hpp"

int main()
{
  char* str1 = kaseev::readLine();
  const char* str2 = "def ";
  try
  {
    char *newStr = kaseev::interleaveStrings(str1, str2);
    delete[] str1;
    delete[] str2;
    if (newStr == nullptr)
    {
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
