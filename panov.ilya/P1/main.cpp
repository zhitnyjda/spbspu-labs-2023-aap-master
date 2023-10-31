#include <iostream>
#include "numberOfSequenceCharacterChanges.hpp"

int main()
{
  int value = 0;
  try
  {
    value = numberOfSequenceCharacterChanges(std::cin);
  }
  catch (std::logic_error const& error)
  {
    std::cout << error.what() << "\n";
    return 0;
  }
std::cout << value << "\n";
}

