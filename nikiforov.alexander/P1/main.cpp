#include <iostream>
#include "CountMinSequence.hpp"
#include <limits>
#include <cstddef>

using namespace nikiforov;

int main()
{
  try
  {
    const int min_count = std::numeric_limits< int >::min();
    int num = 0;
    int beforenum = min_count;
    Sequence arrMin;
    do
    {
      std::cin >> num;
      arrMin(std::cin, beforenum, num);
    } while (num != 0);

    size_t result = arrMin.printSequence();
    std::cout << result;
  }
  catch (const std::logic_error& e) {
    std::cout << e.what() << "\n";
    return 1;
  }
  catch (const std::overflow_error& e)
  {
    std::cout << e.what();
    return 2;
  }
return 0;
}
