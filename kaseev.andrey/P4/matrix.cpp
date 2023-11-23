#include "matrix.hpp"

namespace MatrixStuff {
  size_t NumberOfDiagonals(int *matrix, int size)
  {
    int count = 0;
    for (int n = 0; n < size; ++n)
    {
      if (matrix[n * size + n] != 0)
      {
        int m = n + 1;
        while (m < size && matrix[m * size + m] != 0 && matrix[m * size + m] != matrix[n * size + n])
        {
          ++count;
          ++m;
        }
      }
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
        delete matrix;
        throw std::logic_error("invalid input");
      }
    }
  }
}
