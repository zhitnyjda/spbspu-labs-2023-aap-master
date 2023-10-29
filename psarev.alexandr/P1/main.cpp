#include "myFunc.hpp"
#include <iostream>

int main()
{
  int seq_len = 0;
  int max_len = 0;
  try 
  {
    int value = 0;
    std::cin.exceptions(std::istream::failbit);
    std::cin >> value;
    int prev_value = value;

    while (value != 0) {
      psarev::maxLen(value, prev_value, seq_len, max_len);
      prev_value = value;
      std::cin >> value;
    }
    if (seq_len == 0 && value == 0)
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
  std::cout << max_len << "\n";
  return 0;
}
