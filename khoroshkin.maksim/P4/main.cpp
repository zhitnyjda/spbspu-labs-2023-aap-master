#include <iostream>
#include <fstream>
#include "functions.hpp"

int main(int argc, char ** argv)
{
  try
  {
    if (argc != 4)
    {
      throw std::logic_error("Error: should contain 4 parameters\n");
    }
    int num = std::stoll(argv[1]);
    if (num > 2 || num < 1)
    {
      throw std::logic_error("Error: I can accept only 1 or 2\n");
    }
    else if (num == 1)
    {
      int statMatrix[1000] = { 0 };
      khoroshkin::matrix Matrix;
      std::ifstream inputFile(argv[2]);
      int Rows, Cols;
      inputFile >> Rows >> Cols;
      if (!inputFile)
      {
        throw std::invalid_argument("Cannot read an input.\n");
      }
      try
      {
        Matrix.inputArray(inputFile, statMatrix, Rows * Cols);
      }
      catch(const std::runtime_error & e)
      {
        std::cerr << e.what() << '\n';
        return 2;
      }
      inputFile.close();
      std::ofstream outputFile(argv[3]);
      if (!outputFile.is_open())
      {
        throw std::invalid_argument("Cannot open an output.\n");
      }
      outputFile << Matrix.minSumOfParallelArray(statMatrix, Rows, Cols);
      return 0;
    }
    else
    {
      khoroshkin::matrix Matrix;
      std::ifstream inputFile(argv[2]);
      int Rows, Cols;
      inputFile >> Rows >> Cols;
      if (!inputFile)
      {
        throw std::invalid_argument("Cannot read an input.\n");
      }
      int * dynamicMatrix = new int[Rows * Cols];
      try
      {
        Matrix.inputArray(inputFile, dynamicMatrix, Rows * Cols);
      }
      catch(const std::runtime_error & e)
      {
        std::cerr << e.what() << '\n';
        delete[] dynamicMatrix;
        return 2;
      }
      inputFile.close();
      std::ofstream outputFile(argv[3]);
      if (!outputFile.is_open())
      {
        delete[] dynamicMatrix;
        throw std::invalid_argument("Cannot open an output.\n");
      }
      outputFile << Matrix.minSumOfParallelArray(dynamicMatrix, Rows, Cols);
      delete[] dynamicMatrix;
      return 0;
    }
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what();
    return 1;
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << e.what();
    return 2;
  }
}
