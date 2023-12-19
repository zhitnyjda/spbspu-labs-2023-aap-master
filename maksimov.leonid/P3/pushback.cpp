#include "pushback.hpp"

void arr::pushBack(size_t& size, char*& str, bool& flag)
{
  char temp = 0;
  char* new_str = new char[size + 10] {};
  for (size_t i = 0; i < size; i++)
  {
    new_str[i] = str[i];
  }
  int count = 0;
  while ((std::cin >> temp) && count < 9 && flag)
  {
    if (temp == '\0')
    {
      throw std::exception("Could not read an element of the string\n");
    }
    new_str[size + count] = temp;
    count++;
    if (temp == '\n' || !flag)
    {
      flag = 0;
      break;
    }
  }
  new_str[size + count] = temp;
  size += 10;
  delete[] str;
  str = new_str;
}
