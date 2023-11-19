#include <iostream>
#include <exception>
#include "moreThanPrevious.hpp"
#include "numberOfSignChanges.hpp"
#include "afterMaximum.hpp"

int main()
{
  panov::NumberOfSignChanges numberOfSignChanges;
  panov::MoreThanPrevious moreThanPrevious;
  panov::AfterMaximum afterMaximum;
  try
  {
    if (!std::cin)
    {
      std::cerr << "Not a sequence.\n";
      return 1;
    }
    size_t value = 0;
    do
    {
      std::cin >> value;
      numberOfSignChanges(value);
      moreThanPrevious(value);
      afterMaximum(value);
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
  std::cout << "first\n";
  std::cout << numberOfSignChanges() << "\n";
  std::cout << "second\n";
  std::cout << moreThanPrevious() << "\n";
  std::cout << "third\n";
  std::cout << (afterMaximum()) << "\n";
  return 0;
}
