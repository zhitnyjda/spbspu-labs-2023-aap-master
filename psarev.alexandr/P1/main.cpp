#include <iostream>
#include "myFunc.hpp"

int main()
{
  psarev::maxLen myMaxLen;
  try
  {
    int value = 0;
    std::cin.exceptions(std::istream::failbit);
    std::cin >> value;

    while (value != 0) {
      myMaxLen(value);
      std::cin >> value;
    }
    if (myMaxLen.seq_len == 0 && value == 0)
    {
      throw std::logic_error("Error: Not a sequence!\n");
    }
  }
  catch(const std::logic_error & e)
  {
    std::cerr << e.what();
    return 2;
  }
  catch(const std::istream::failure & e)
  {
    std::cerr << "Error: Wrong input!\n";
    return 1;
  }
  std::cout << myMaxLen() << "\n";
  return 0;
}
