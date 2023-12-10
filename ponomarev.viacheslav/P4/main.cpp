#include <iostream>
#include <fstream>

size_t inputArray(std::istream & in, int * matrix, size_t lenArray)
{
  for (size_t i = 0; i < lenArray; i++)
  {
    if (!(in >> matrix[i]))
    {
      return i;
    }
  }
  return lenArray;
}

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "I feel that something wrong-_-.\n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Cannot parse a value.\n";
    return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "Wrong first argument value, expected 1 or 2.\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t rows = 0, cols = 0;
  if (!(input >> rows >> cols))
  {
    std::cerr << "Error from reading numbers from a file.\n";
    return 2;
  }
  int fixMatrix[10000] = { 0 };
  int * matrix = (num == 2) ? new int[rows * cols] : fixMatrix;
  if (inputArray(input, matrix, rows * cols) != (rows * cols))
  {
    std::cerr << "The wrong number of matrix elements.\n";
    if (num == 2)
    {
      delete[] matrix;
    }
    return 2;
  }
  std::ofstream output(argv[3]);
  for (size_t i = 0; i < (rows * cols); i++)
  {
  output << matrix[i] << "\n";
  }
  if (num == 2)
  {
    delete[] matrix;
  }
  return 0;
}
