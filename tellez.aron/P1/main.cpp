#include <iostream>
#include <stdexcept>
#include "getSequence.hpp"

int main()
{
  try
  {
    int result = getSequence();
    if (result < 0)
    {
      throw std::overflow_error("Error: Too short sequence.\n");
    }
      std::cout << "Longest decreasing length: " << count << "\n";
    }
    catch (const std::overflow_error& e)
    {
      std::cerr << e.what() << std::endl;
      return 1;
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      return 2;
    }
    return 0;
}
