#include "func.hpp"

void sequaence_counter(const int& a, const int& b, const int& c, int& count, int& counter)
{
  count++;
  if (count > 2 && b < a && b > c && c != 0)
  {
    counter++;
  }
}
