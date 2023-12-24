#include <iostream>
#include "dynamicStringReader.hpp"
#include "repeatingDigitsCheck.hpp"

int main()
{
  using namespace cringecode;
  DynamicStringReader stringReader = DynamicStringReader(10);
  char* string = stringReader.read(std::cin);
  if (containsRepeatingDigits(string, stringReader.getLength()))
  {
    std::cout << "Ja" << '\n';
  }
  else
  {
    std::cout << "Nein" << '\n';
  }
}
