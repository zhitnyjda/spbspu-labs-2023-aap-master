#include <iostream>
#include <exception>
#include "nchar.hpp"
#include "numOfchar.hpp"
#include "rchar.hpp"

int main()
{
  panov::NumOfchar numOfchar;
  panov::Nchar nchar;
  panov::Rchar rchar;
  try
  {
    std::cerr.exceptions(std::istream::failbit);
    int value = 0;
    int c = 0;
    do
    {
      std::cin >> value;
      numOfchar(value);
      nchar(value);
      rchar(value);
    }
    while ((value != 0) || (c != 0));
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
  std::cout << "first\n";
  std::cout << numOfchar() << "\n";
  std::cout << "first\n";
  std::cout << nchar() << "\n";
  std::cout << "first\n";
  std::cout << rchar() << "\n";
  return 0;
}
