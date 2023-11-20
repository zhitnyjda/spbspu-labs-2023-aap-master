#include "CountMinSequence.hpp"
#include <iostream>

using namespace nikiforov;

int main()
{
  try
  {
    const int min_count = std::numeric_limits< int >::min();
    int num = 0;
    int beforenum = min_count;
    size_t lenth = 0;
    Sequence arrMin;
    do
    {
      std::cin >> num;
      arrMin(std::cin, beforenum, num);
      lenth++;
    } while (num != 0);

    if (lenth == 1) {
      throw std::overflow_error("Too short sequence");
    }

    size_t result = arrMin();
    std::cout << result;
  }
  catch (const std::logic_error& e) {
    std::cout << e.what() << "\n";
    return 1;
  }
  catch (const std::overflow_error& e)
  {
    std::cout << e.what() << "\n";
    return 2;
  }
return 0;
}
