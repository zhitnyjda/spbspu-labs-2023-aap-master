#include "getMinSum.hpp"
#include <stdexcept>
#include <limits>

size_t getMinSum(const size_t * arr, size_t m, size_t n)
{
  if (m == 0 || n == 0)
    return 0;

  if (m != n)
    throw std::invalid_argument("La matriz debe ser cuadrada");

  size_t minSum = arr[0]; // Inicializamos con el primer elemento

  for (size_t i = 1; i < m; ++i)
  {
    size_t sum = 0;
    for (size_t j = 0; j <= i; ++j)
      sum += arr[i * n + j] + arr[j * n + i];
    if (sum < minSum)
      minSum = sum;
  }

  for (size_t j = 1; j < n; ++j)
  {
    size_t sum = 0;
    for (size_t i = 0; i < m && i + j < n; ++i)
      sum += arr[i * n + i + j] + arr[(i + j) * n + i];
    if (sum < minSum)
      minSum = sum;
  }

  return minSum;
}
