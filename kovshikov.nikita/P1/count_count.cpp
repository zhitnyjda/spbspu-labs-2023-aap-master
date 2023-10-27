#include "count_count.hpp"
#include <iostream>
namespace kovshikov
{
  size_t count_count(size_t num, size_t count)
  {
    if (num % 2 == 0)
    {
      count += 1;
    }
    else
    {
      count = 0;
    }
    return count;
  }
}
