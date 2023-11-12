#include <iostream>
int main() {
  int m, n;
  std::cin >> m >> n;
  int **matrix = new int *[m];
  for (int i = 0; i < m; i++)
  {
    matrix[i] = new int[n];
    for (int j = 0; j < n; j++)
    {
      std::cin >> matrix[i][j];
    }
  }
  minusSpiralElements(matrix, m, n);
  printMatrix(matrix, m, n);
  for (int i = 0; i < m; i++)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
  return 0;
}
