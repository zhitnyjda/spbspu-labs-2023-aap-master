#include <iostream>
#include "findingCount.hpp"

int main()
{
  int count = 0;
  try
  {
    count = findingCount();
  }
  catch (std::invalid_argument const& e1)
  {
    std::cout << e1.what() << "\n";
    return 1;
  }
  catch (std::logic_error const& e2)
  {
    std::cout << e2.what() << "\n";
    return 2;
  }
  std::cout << count << "\n";
}
