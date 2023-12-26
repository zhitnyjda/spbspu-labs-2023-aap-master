#include <iostream>
#include <cctype>
#include "noInt.hpp"

int main()
{
  using namespace popov;
  const int add = 15;
  char * input = new char[add]{};
  int len = 0;
  int count = 1;
  std::cin >> std::noskipws;
  char c;
  do
  {
    std::cin >> c;
    input[len++] = c;
    if (len - (add * count) == 0)
    {
      ++count;
      char * biggerinput = new char[add + len];
      for(int i = 0; i < len; i++)
      {
        biggerinput[i] = input[i];
      }
      delete [] input;
      input = biggerinput;
    }
  }while (c != '\n');
  std::cin >> std::skipws;
  char * res = new char[len]{};
  noInt(res, input, len);
  std::cout << res;
  delete [] input;
  delete [] res;
  return 0;
}
