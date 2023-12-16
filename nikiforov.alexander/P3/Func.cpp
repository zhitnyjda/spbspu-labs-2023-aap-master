#include "Func.hpp"
#include <iostream>

size_t nikiforov::result(char* str1, char* str2, size_t len1, size_t len2) {
  size_t count = 0;
  if (len1 == 0 || len2 == 0)
  {
    throw std::overflow_error("Too short sequence\n");
    delete[] str1;
    delete[] str2;
  }
  for (size_t i = 0; i < len1; i++)
  {
    for (size_t j = 0; j < len2; j++)
    {
      if (str1[i] == str2[j] && str1[i] != ' ')
      {
        count++;
        break;
      }
    }
  }
  return count;
  delete[] str1;
  delete[] str2;
}
