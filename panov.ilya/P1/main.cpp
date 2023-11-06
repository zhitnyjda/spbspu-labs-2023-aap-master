#include <iostream>
#include <exception>
#include "nchar.hpp"
#include "numOfchar.hpp"

int main()
{
  ranov::NumOfchar numOfchar;
  panov::Nchar nchar;
  try
  {
    std::cin.exceptions(std::istream::failbit);
    int value = 0;
    int score = 0;
    do
    {
      std::cin >> value;
      numOfchar(value);
      std::cin >> value;
      nchar(value);
    }
    while (value != 0);
  }
  catch (const std::istream::failure & e)
  {
    std::cerr << "OnlyNumberPLS" << "\n";
    return 1;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << nchar() << "\n";
  std::cout << numOfchar() << "\n";
  return 0;
}
