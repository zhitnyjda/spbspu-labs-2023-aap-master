#include <iostream>
#include <fstream>
#include <cstdlib>
#include "findCntLocMin.hpp"
#include "inputArray.hpp"

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Something wrong, I can feel it.\n";
    return 1;
  }
  char* endNum;
  int num = std::strtoll(argv[1], &endNum, 10);
  if (*endNum != '\0')
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
      if (!input)
      {
        std::cerr << "Error read an input./n";
        return 2;
      }
    }
    resultNum = taskaev::findCntLocMin(matrix, rows, cols);
  }
  else if (num == 2)
  {
    int * matrix = new int [rows * cols];
    if((taskaev::inputArray(input, matrix, rows * cols, rows * cols)) == (rows*cols))
    {
      resultNum = taskaev::findCntLocMin(matrix, rows, cols);
      delete [] matrix;
    }
    else
    {
      std::cerr <<"Error matrix cannot read.\n";
      delete [] matrix;
      return 2;
    }
  }
  else
  {
    std::cerr << "Error num != 1 or num != 2.\n";
    return 2;
  }
  std::ofstream output(argv[3]);
  output << resultNum;
  return 0;
}
