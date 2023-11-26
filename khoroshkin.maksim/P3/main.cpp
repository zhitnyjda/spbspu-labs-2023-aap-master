#include <iostream>
#include "functions.hpp"

int main()
{
  try
  {
    char * string = new char[10];
    int length = khoroshkin::inputLine(string);
    std::cout << khoroshkin::getFrequency(string, length) << '\n';
    delete[] string;
    return 0;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Cannot allocate memory\n";
    return 1;
  }
}