#include <iostream>
#include "functions.hpp"

int main()
{
  char * str1 = new char[10]{};
  size_t len1 = zheleznyakov::readLine(str1);
  char * str2 = new char[10]{};
  size_t len2 = zheleznyakov::readLine(str2);
  delete [] str1;
  delete [] str2;
  return 0;
}
