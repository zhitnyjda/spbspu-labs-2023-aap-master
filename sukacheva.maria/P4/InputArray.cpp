#include "InputArray.hpp"
#include <iostream>
#include <algorithm>

size_t sukacheva::inputMatrix(std::istream& in, int* matrix, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    in >> matrix[i];
    if (!input)
    {
      std::cerr << "Cannot read an array.\n";
      return i;
    }
  return size;
}
