#include <iostream>
#include <exception>
#include "moreThanPrevious.hpp"
#include "NumberOfSignChanges.hpp"
#include "afterMaximum.hpp"

int main()
{
  panov::NumberOfSignChanges numberOfSignChanges;
  panov::MoreThanPrevious moreThanPrevious;
  panov::AfterMaximum afterMaximum;
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
  if (std::cin.fail())
  {
    std::cerr << "Input error" << "\n";
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
