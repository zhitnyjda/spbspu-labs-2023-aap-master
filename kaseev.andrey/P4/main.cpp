#include <iostream>
#include <fstream>
#include "matrix.cpp"

int main(int argc, char **argv)
{
  if (argc > 4)
  {
    throw (std::invalid_argument("There are more arguments than should be!"));
  }
  if (argc < 4)
  {
    throw (std::invalid_argument("There are not enough arguments!"));
  }
  int num = std::strtoll(argv[1], nullptr, 10);
  if (num != 1 && num != 2)
  {
    throw(std::invalid_argument("Invalid argument!"));
  }
  //argv[2] - имя файла с матрицей
  size_t rows = 0, cols = 0;
  {
    std::ifstream file(argv[2]);
    file >> rows >> cols;
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        file >> matrix[i][j];
      }
    }
    if (!file.is_open())
    {
      std::cerr << "Cannot read an input.\n";
      return 2;
    }
  }
  if (rows <= 0 || cols <= 0)
  {
    std::cerr << "Invalid matrix dimensions." << std::endl;
    return {};
  }
  std::ofstream output(argv[3]);
  if (num == 1)
  {
    int matrix[10000] = {};
    size_t count = matrixStuff::NumberOfDiagonals(matrix);
    std::ofstream outputFile(argv[3]);
    if (outputFile.is_open())
    {
      writeResult(outputFile, count);
      outputFile.close();
    }
    else
    {
      std::cerr << "Unable to open the output file." << std::endl;
    }
  }
  else
  {
    int *matrix = new int[rows * cols];
    size_t count = matrixStuff::NumberOfDiagonals(matrix);
    std::ofstream outputFile(argv[3]);
    if (outputFile.is_open())
    {
      writeResult(outputFile, count);
      outputFile.close();
    }
    else
    {
      std::cerr << "Unable to open the output file." << std::endl;
    }
    delete[] matrix;
  }
}