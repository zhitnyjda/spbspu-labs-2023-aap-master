#include "findCntLocMin.hpp"
#include "inputArray.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Something wrong, I can feel it.\n";
    return 1;
  }

  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (...)
  {
    std::cerr << "Cannot parse values\n";
    return 3;
  }
  int resultNum = 0;
  if (num == 1)
  {
    std::ifstream input(argv[2]);
    int rows = 0, cols = 0;
    input >> rows >> cols;
    int matrix[rows * cols];
    for (int i = 0; i< rows * cols; i++)
    {
      input >> matrix[i];
    }
    if (!input)
    {
      std::cerr << " Cannot read an input.\n";
      return 2;
    }
    resultNum = matrixStuff::findCntLocMin(matrix, rows, cols);
    {
      std::ofstream output(argv[3]);
      output << resultNum;
    }
    return 0;
  }
  else if (num == 2)
  {
    std::ifstream input(argv[2]);
    int rows = 0, cols = 0;
    input >> rows >> cols;
    int * matrix = new int [rows * cols];
    size_t result = 0;
    result = readArray::inputArray(input, matrix, rows * cols, rows * cols);
    if (!input)
    {
      std::cerr << " Error matrix.\n";
      delete [] matrix;
      return 2;
    }

    resultNum = matrixStuff::findCntLocMin(matrix, rows, cols);

    delete [] matrix;

    {
      std::ofstream output(argv[3]);
      output << resultNum;
    }
    return 0;
  }
  else
  {
    std::cerr << "Error num != 1 or num != 2.\n";
    return 1;
  }
}
