#include "matrix.hpp"

namespace MatrixStuff {
  size_t NumberOfDiagonals(int *matrix, int n, int m) {
    if (matrix == nullptr)
    {
      return 0;
    }
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
      bool containsZero = false;

      for (int j = 0; j < m; ++j)
      {
        int index = i * m + j;

        if ((i == j && matrix[index] == 0) || matrix[m - 1] == 0)
        {
          containsZero = true;
          break;
        } else if (i != j && matrix[index] == 0)
        {
          containsZero = true;
          break;
        }
      }

      if (!containsZero)
      {
        count++;
      }
    }
    return count;
  }

  void writeResult(std::ostream &output, int result, bool UpperTriangularMatrix)
  {
    if (UpperTriangularMatrix)
    {
      output << result << "\n" << "true";
    }
    else
    {
      output << result << "\n" << "false";
    }
  }

  bool readMatrix(std::istream &input, int *matrix, int n, int m)
  {
    bool marker = true;
    for (int i = 0; i < n * m; ++i)
    {
      if (!(input >> matrix[i])) {
        return false;
      }
    }
    return marker;
  }

  bool upperTriangularMatrix(int *matrix, int n, int m)
  {
    if (matrix == nullptr)
    {
      return false;
    }
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        int index = i * m + j;
        if (i > j && matrix[index] != 0)
        {
          return false;
        }
      }
    }
    return true;
  }
}
