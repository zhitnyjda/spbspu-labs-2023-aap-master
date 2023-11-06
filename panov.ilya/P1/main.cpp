#include <iostream>
#include <exception>
#include "nchar.hpp"
#include "numOfchar.hpp"

int main()
{
  panov::Nchar nchar;
  try
  {
    std::cin.exceptions(std::istream::failbit);
    int value = 0;
    do
    {
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

  ranov::NumOfchar numOfchar;
  try
  {
    std::cin.exceptions(std::istream::failbit);
    int score = 0;
    do
    {
      std::cin >> score;
      numOfchar(score);
    }
    while (score != 0);
  }
  catch (const std::istream::failure& i)
  {
    std::cerr << "OnlyNumberPLS" << "\n";
    return 1;
  }
  catch (const std::logic_error& i)
  {
    std::cerr << i.what() << "\n";
    return 1;
  }
  std::cout << numOfchar() << "\n";
  return 0;
}
