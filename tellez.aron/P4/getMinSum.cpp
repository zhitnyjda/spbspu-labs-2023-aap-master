#include "getMinSum.hpp"
#include <stdexcept>

size_t calculateSum(const size_t* arr, size_t m, size_t n, size_t startRow, size_t startCol)
{
  size_t sum = 0;
  for (size_t i = 0; i < m && i + startCol < n; ++i)
  {
    sum += arr[(i + startRow) * n + i + startCol] + arr[(i + startCol) * n + i + startRow];
  }
  return sum;
}

size_t getMinSum(const size_t* arr, size_t m, size_t n)
{
  if (m == 0 || n == 0)
    return 0;
  if (m != n)
  throw std::invalid_argument("matrix must be square");
  size_t minSum = arr[0];
  for (size_t i = 1; i < m + n - 1; ++i)
  {
    size_t row = (i < m) ? i : m - 1;
    size_t col = (i < m) ? 0 : i - m + 1;
    size_t sum = calculateSum(arr, m, n, row, col);
    if (sum < minSum)
      minSum = sum;
  }
  return minSum;
}
