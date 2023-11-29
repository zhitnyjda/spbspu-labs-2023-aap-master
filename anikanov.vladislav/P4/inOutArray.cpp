#include <fstream>
#include "inOutArray.h"

int inputArray(std::istream &cin, int *array, int n, int m)
{
  for (int i = 0; i < n * m; ++i) {
    if (!(cin >> array[i])) {
      return i;
    }
  }
  return n * m;
}

void const printArray(std::ostream &cout, int const *array, int n, int m)
{
  cout << n << " " << m << " ";
  for (int i = 0; i < n * m; ++i) {
    cout << array[i] << " ";
  }
}
