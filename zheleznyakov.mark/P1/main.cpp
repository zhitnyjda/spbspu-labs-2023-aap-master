#include <iostream>
#include <exception>
#include "functions.hpp"

int main()
{
  int counter = 0;
  try
  {
    int element = 0;
    int previousElement = 0;
    std::cin.exceptions(std::istream::failbit);
    std::cin >> element;
    zheleznyakov::compareCurrentAndPrevious(counter, element, previousElement);
    while (element != 0)
    {
      std::cin >> element;
      zheleznyakov::compareCurrentAndPrevious(counter, element, previousElement);
    }
  }
  catch (const std::istream::failure & e)
  {
    std::cerr << "Error: only valid integers are accepted\n";
    return 1;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  std::cout << counter << '\n';
  return 0;
}
