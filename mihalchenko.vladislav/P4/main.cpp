#include <iostream>
#include <fstream>
#include "matrix.hpp"
#include "inputArray.hpp"
#include "outputArray.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Something wrong, I can feel it.\n";
    return 1;
  }

  int num;

  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Cannot parse a value!!!!";
    return 1;
  }

  std::ifstream input(argv[2]);

  size_t rows = 0, cols = 0;
  input >> rows >> cols;
  {
    if (!input)
    {
      std::cerr << "Cannot read an input.\n";
      return 2;
    }
  }

  if (num == 1)
  {
    int * matrix = new int[rows * cols];
    size_t result = readArray::inputArray(input, matrix, rows * cols, rows * cols);
    if (!input)
    {
      std::cerr << "Read " << result << "elements...\n";
      delete [] matrix;
      return 3;
    }
    writeArray::outputArray(argv[3], matrix, rows, cols);
    return 0;
  }
  if (num == 2)
  {
    int ** m1 = nullptr;
    int ** m2 = nullptr;
    try
    {
      m1 = matrixLife::createMatrix(rows, cols);
      m2 = matrixLife::createMatrix(rows, cols);
      matrixLife::freeMatrix(m1, rows, cols);
      matrixLife::freeMatrix(m2, rows, cols);
    }
    catch(...)
    {
      //delete [] matrix;
      matrixLife::freeMatrix(m1, rows, cols);
      matrixLife::freeMatrix(m2, rows, cols);
      return 3;
    }
    //delete [] matrix;
    std::ofstream output(argv[3]);
    output << rows << " " << cols << "\n";
    return 0;
  }
  else
    return 2;
  {
    //std::ofstream output(argv[3]);
    //output << rows << " " << cols << "\n";
  }
  return 0;
}
