#include "pushback.hpp"

void arr::pushBack(size_t& size, char*& str, bool& flag)
{
  std::skipws;
  char temp = 0;
  char* new_str = new char[size + 10] {};
  for (size_t i = 0; i < size; i++)
  {
    new_str[i] = str[i];
  }
  int count = 0;
  while ((std::cin >> temp) && count < 9 && flag)
  {
    new_str[size + count] = temp;
    count++;
    if (temp == '\n' || !flag)
    {
      flag = 0;
      break;
    }
  }
  if (temp != '\0')
  {
    if (temp == 0)
    {
      delete[] new_str;
      throw std::exception();
    }
  }
  new_str[size + count] = temp;
  size += 10;
  delete[] str;
  str = new_str;
  std::cin >> std::noskipws;
}
