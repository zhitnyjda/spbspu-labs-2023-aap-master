#include <iostream>
#include "functions.hpp"

int main()
{
  char * string = new char[10];
  int length = khoroshkin::inputLine(string, 10);
  if (length < 3)
  {
    std::cerr << "Error: Too short string\n";
    delete[] string;
    return 1;
  }
  try
  {
    char * result = khoroshkin::getFrequency(string, length);
    std::cout << result << '\n';
    delete[] result;
    delete[] string;
    return 0;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error: Cannot allocate memory\n";
    delete[] string;
    return 1;
  }
}
