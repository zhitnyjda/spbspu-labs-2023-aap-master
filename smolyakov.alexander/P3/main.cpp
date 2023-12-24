#include <iostream>
#include "dynamicStringReader.hpp"
#include "repeatingDigitsCheck.hpp"

int main()
{
  using namespace cringecode;
  DynamicStringReader stringReader = DynamicStringReader(10);
  char* string;
  try
  {
    string = stringReader.read(std::cin);
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << "Could not allocate memory for the string. Detais: " << e.what() << '\n';
    return 1;
  }
  std::cout << (containsRepeatingDigits(string, stringReader.getLength()) ? '1' : '0') << '\n';
  return 0;
}
