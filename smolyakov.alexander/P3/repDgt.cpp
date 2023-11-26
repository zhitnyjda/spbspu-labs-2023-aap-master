#include "repDgt.hpp"
#include <cctype>

int containsRepeatingDigits(char * string, std::size_t length)
{
  int count[10] = {0};
  for (std::size_t i = 0; i < length; i++)
  {
    if (std::isdigit(string[i]))
    {
      short index = string[i] - '0';
      if (++count[index] > 1)
      {
	return 1;
      }
    }
  }
  return 0;
}
