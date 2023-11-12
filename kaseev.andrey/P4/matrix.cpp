#include "matrix.hpp"
#include <vector>

size_t NumberOfDiagonals(const std::vector<std::vector<int>>& matrix)
{
  int count = 0;
  for (int i = 0; i < matrix.size(); ++i) {
    if (matrix[i][i] != 0) {
      int j = i + 1;
      while (j < matrix.size() && matrix[j][j] != 0 && matrix[j][j] != matrix[i][i]) {
        ++count;
        ++j;
      }
    }
  }
  return count;
}

void writeResult(std::ostream& output, int result) {
  output << result;
}
