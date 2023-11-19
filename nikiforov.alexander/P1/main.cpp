#include <iostream>
#include "CountMinSequence.hpp"

using namespace nikiforov;

int main() 
{
  const int max_count = std::numeric_limits< int >::max();
  const int min_count = std::numeric_limits< int >::min();
  int num = 0;
  int beforenum = min_count;
  Sequence arrMin;
  do
  {
    if (!(std::cin >> num)) 
    {
      throw std::invalid_argument("Wrong input");
      return 1;
    }
    else if (num < min_count || num > max_count) 
    {
      throw std::overflow_error("Too many number or too few number");
      return 2;
    }

    arrMin(beforenum, num);
  } while (num != 0);
  
  int result = arrMin.printSequence();
  std::cout << result;

	return 0;
}