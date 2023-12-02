#include <iostream>
#include "functions.hpp"

int main()
{
  char * string = new char[10];
  try
  {
    int length = khoroshkin::inputLine(string, 10);
    char * result = khoroshkin::getFrequency(string, length);
    std::cout << result << '\n';
    delete[] result;
    delete[] string;
    return 0;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Cannot allocate memory\n";
    delete[] string;
    return 1;
  }
}
