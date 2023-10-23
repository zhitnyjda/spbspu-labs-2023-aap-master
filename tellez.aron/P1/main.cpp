#include <iostream>
#include <stdexcept>
#include "functions.hpp"

int main()
{
  try
  {
    int result = getSequence();
    std::cout << result << "\n";
  }
  catch (std::istream::failure& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  return 0;
}
