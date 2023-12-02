#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cstring>
#include "getMinSum.hpp"
#include "readMatrix.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Invalid number of arguments." << '\n';
    return 1;
  }
  size_t* matrix = nullptr;
  try
  {
    size_t num = std::stoi(argv[1]);
    if (num != 1 && num != 2)
    {
      throw std::invalid_argument("Invalid parameter. Use 1 or 2.");
    }
    size_t rows = 0;
    size_t columns = 0;
    std::ifstream file(argv[2]);
    file >> rows >> columns;
    if (!file)
    {
      std::cerr << "Error: Unable to read matrix dimensions from file...\n";
      return 1;
    }
    std::vector<size_t> static_matrix(10000);
    if (num == 1)
    {
      matrix = static_matrix.data();
    }
    else
    {
      matrix = new size_t[rows * columns];
    }
    size_t result = readMatrix(file, matrix, rows, columns);
    if (result != rows * columns)
    {
      std::cerr << "Can't read the whole array check the elements \n";
      return 2;
    }
    std::ofstream out(argv[3]);
    size_t min_sum = getMinSum(matrix, rows, columns);
    out << min_sum << "\n";
    if (num == 2)
    {
      delete[] matrix;
    }
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Error:\n" << e.what() << '\n';
    if (matrix != nullptr &&  std::strcmp(argv[1], "2") == 0)
    {
      delete[] matrix;
    }
    return 1;
  }
  return 0;
}
