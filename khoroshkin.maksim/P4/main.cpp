#include "functions.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Error: should contain 4 parameters\n";
    return 1;
  }

  int num;
  try
  {
   num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << e.what();
    return 1;
    }

  if (num > 2 || num < 1)
  {
    std::cerr << "Error: I can accept only 1 or 2\n";
    return 2;
  }
  else if (num == 1)
  {
    int statMatrix[1000] = { 0 };
    khoroshkin::matrix Matrix;
    int Rows, Cols;
    std::ifstream inputFile(argv[2]);
    inputFile >> Rows >> Cols;
    if (!inputFile)
    {
      std::cerr << "Cannot read an input.\n";
      return 2;
    }
    Matrix.inputArray(inputFile,statMatrix,Rows*Cols);
    inputFile.close();
    std::ofstream outputFile(argv[3]);
    if (!outputFile.is_open())
    {
      std::cerr << "Cannot open an output.\n";
      return 2;
    }
    outputFile << Matrix.minSumOfParallelArray(statMatrix, Rows, Cols);
    return 0;
  }
  else
  {
    khoroshkin::matrix Matrix;
    int Rows, Cols;
    std::ifstream inputFile(argv[2]);
    inputFile >> Rows >> Cols;
    if (!inputFile)
    {
      std::cerr << "Cannot read an input.\n";
      return 2;
    }
    int * dynamicMatrix = new int[Rows * Cols];
    Matrix.inputArray(inputFile, dynamicMatrix, Rows * Cols);
    inputFile.close();
    std::ofstream outputFile(argv[3]);
    if (!outputFile.is_open())
    {
      std::cerr << "Cannot open an output.\n";
      return 2;
    }
    outputFile << Matrix.minSumOfParallelArray(dynamicMatrix, Rows, Cols);
    return 0;
  }
}