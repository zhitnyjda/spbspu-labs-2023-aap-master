#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
#include "getMinSum.hpp"
int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cout << "Invalid number of arguments." << '\n';
    return 1;
  }
  size_t rows = 0;
  size_t columns = 0;
  std::ifstream file(argv[2]);
  file >> rows >> columns;
  if (!file)
  {
    std::cout << "Error.";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    size_t  static_matrix[10000];
    for (size_t i = 0; i < rows * columns; i++)
    {
      file >> static_matrix[i];
      if (!file)
      {
        std::cout << "Error..";
        return 1;
      }
    }
    std::ofstream out(argv[3]);
    out << getMinSum(static_matrix, rows, columns) << "\n";
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    if (rows != columns)
    {
      std::cerr << "Matrix must be square" << '\n';
      return 1;
    }
    size_t * dynamic_matrix = new size_t[rows * columns];
    for (size_t i = 0; i < rows * columns; i++)
    {
      file >> dynamic_matrix[i];
      if (!file)
      {
        std::cout << "Error...";
        delete[] dynamic_matrix;
        return 1;
      }
    }
    std::ofstream out(argv[3]);
    try
    {
      size_t minSum = getMinSum(reinterpret_cast<const size_t*>(dynamic_matrix), rows, columns);
      out << minSum << "\n";
    }
    catch (const std::invalid_argument &e)
    {
      delete[] dynamic_matrix;
      std::cout << "Error:\n";
      std::cout << e.what();
      return 0;
    }
    delete[] dynamic_matrix;
  }
  else
  {
    std::cout << "No such parameter";
    return 1;
  }
  return 0;
}
