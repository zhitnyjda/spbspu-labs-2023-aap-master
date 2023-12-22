#include <iostream>
#include <cctype>

int main()
{
  const int add = 15;
  char * input = new char[add]{};
  int len = 0;
  int count = 1;
  std::cin >> std::noskipws;
  char c;
  do
  {
    std::cin >> c;
    if (isdigit(c) == 0)
    {
      input[len++] = c;
    }
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
  std::cout << input;
  delete [] input;
}
