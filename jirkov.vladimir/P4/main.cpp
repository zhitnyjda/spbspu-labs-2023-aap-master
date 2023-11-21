#include <iostream>
#include <fstream>
#include "decreaseSpiralElements.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Something Wrong!\n";
    return 1;
  }
  int Num = 0;
  try
  {
    Num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Incorrect First argument\n";
    return 1;
  }
  if ((Num != 1) && (Num != 2))
  {
    std::cerr << "Wrong value of first argument!\n";
    return 1;
  }
  else
  {
    jirkov::matrix Matrix;
    std::ifstream input(argv[2]);
    size_t m = 0, n = 0;
    if (!(input >> m >> n))
    {
      std::cerr << "Can't read input file\n";
      return 2;
    }
    std::ofstream output(argv[3]);
    if (!output.is_open()) {
      std::cerr << "Output file do not open!\n";
      return 2;
    }
    int **matrix = new int *[m];
    for (int i = 0; i < m; i++)
    {
      matrix[i] = new int[n];
      for (int j = 0; j < n; j++)
      {
        std::cin >> matrix[i][j];
      }
    }
    Matrix.decreaseSpiralElements(matrix, m, n);
    std::cout << "Transformed matrix:\n";
    Matrix.printMatrix(matrix, m, n);
    for (int i = 0; i < m; i++)
    {
      delete[] matrix[i];
    }
    delete[] matrix;
  }
  return 0;
}
