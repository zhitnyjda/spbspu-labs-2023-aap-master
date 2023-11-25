#include "matrix.hpp"

namespace MatrixStuff {
  size_t NumberOfDiagonals(int *matrix, int n, int m) {
    if (matrix == nullptr)
    {
      return 0;
    }
    size_t count = 0;
    for (int i = 0; i < n; ++i) {
      bool containsZero = false;

      for (int j = 0; j < m; ++j) {
        int index = i * m + j;

        if (i == j && matrix[index] == 0) {
          containsZero = true;
          break;
        } else if (i != j && matrix[index] == 0) {
          containsZero = true;
          break;
        }
      }

      if (!containsZero) {
        count++;
      }
    }
    if (matrix[m - 1] == 0)
    {
      count++;
    }
    return count;
  }

  void writeResult(std::ostream &output, int result)
  {
    output << result;
  }

  void readMatrix(std::istream &input, int *matrix, int n, int m) {
    for (int i = 0; i < n * m; ++i) {
      if (!(input >> matrix[i])) {
        throw std::logic_error("invalid input");
      }
    }
  }
}
