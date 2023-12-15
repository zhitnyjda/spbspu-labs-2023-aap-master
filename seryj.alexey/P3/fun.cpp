#include "fun.hpp"
#include <iostream>
char * seryj::changeArray(char* old_line, int max_size)
{
  char * new_line = new char[max_size*2];
  if(!new_line)
    throw std::logic_error("Error: not enough space for array\n");
  for (int i = 0; i < max_size; i++)
  {
    new_line[i] = old_line[i];
  }
  delete[] old_line;
  return new_line;
}
size_t seryj::counterOfEqualPairs(char* values, int real_size)
{
  int count = 0;
  for (int i = 0; i < real_size; i++)
    for (int j = i + 1; j < real_size; j++)
    {
      count += (values[i] == values[j]);
    }
  return count;
}
char* seryj::readLine(size_t& real_size)
{
  size_t max_size = 10;
  char* line = new char[max_size];
  char current_char = '0';
  std::cin >> std::noskipws;
  while (std::cin >> current_char && current_char != '\n')
  {
    if(real_size >= max_size)
    {
      try
      {
        line = seryj::changeArray(line, max_size);
      }
      catch (std::logic_error const& e)
      {
        delete[] line;
        throw std::logic_error(e.what());
      }
      max_size *= 2;
    }
    line[real_size] = current_char;
    real_size++;
  }
  if (!real_size)
  {
    std::cerr << "Error: zero sequence\n";
    delete[] line;
    throw std::logic_error("Error: zero sequence\n");
  }
  std::cin >> std::noskipws;
}
