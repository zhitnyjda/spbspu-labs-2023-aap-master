#include <iostream>
#include <fstream>
#include "findCntLocMin.hpp"
#include "inputArray.hpp"

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
  std::ifstream input(argv[2]);
  int rows, cols;
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << " Cannot read an input.\n";
    return 2;
  }
  if (num == 1)
  {
    int matrix[rows * cols];
    for (int i = 0; i < rows * cols; i++)
    {
      input >> matrix[i];
    }
    resultNum = matrixStuff::findCntLocMin(matrix, rows, cols);
  }
  else if (num == 2)
  {
    int * matrix = new int [rows * cols];
    try
    {
      readArray::inputArray(input, matrix, rows * cols, rows * cols);
    }
    catch(...)
    {
      std::cerr <<"Error matrix cannot read.\n";
      delete [] matrix;
      return 2;
    }
    resultNum = matrixStuff::findCntLocMin(matrix, rows, cols);
    delete [] matrix;
  }
  else
  {
    std::cerr << "Error num != 1 or num != 2.\n";
    return 1;
  }
  std::ofstream output(argv[3]);
  output << resultNum;
  return 0;
}
