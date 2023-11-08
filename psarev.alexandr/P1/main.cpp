#include <iostream>
#include "maxLen.hpp"

int main()
{
  psarev::maxLen myMaxLen;
  try
  {
    int value = 0;

    do {
      std::cin >> value;
      myMaxLen(value);
    } while (value != 0);
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
