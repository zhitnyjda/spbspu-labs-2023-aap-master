#include <iostream>
#include <fstream>
#include "functions.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Error: should contain 4 parameters\n";
    return 1;
  }
  int num;
  if (!(khoroshkin::isNumber(argv[1])))
  {
    std::cerr << "Error: first parameter can accept only 1 or 2\n";
    return 1;
  }
  else
  {
    num = std::stoll(argv[1]);
  }
  if (num > 2 || num < 1)
  {
    std::cerr << "Error: I can accept only 1 or 2\n";
    return 1;
  }
  else if (num == 1)
  {
    try
    {
     int statMatrix[1000] = { 0 };
     int Rows, Cols;
     {
       std::ifstream inputFile(argv[2]);
       khoroshkin::fillingRowsAndCols(inputFile, Rows, Cols);
       int successOrNO = khoroshkin::inputArray(inputFile, statMatrix, Rows * Cols);
       if (successOrNO != Rows*Cols)
       {
         std::cerr << "Error: was filled only " << successOrNO+1 << " elements";
         return 2;
       }
       std::ofstream outputFile(argv[3]);
       khoroshkin::fillingOutputFile(outputFile, statMatrix, Rows, Cols);
     }
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what();
      return 2;
    }
  }
  else
  {
    int Rows, Cols;
    try
    {
      std::ifstream inputFile(argv[2]);
      khoroshkin::fillingRowsAndCols(inputFile, Rows, Cols);
    }
    catch(const std::logic_error & e)
    {
      std::cerr << e.what() << '\n';
      return 2;
    }
    int * dynamicMatrix = new int[Rows * Cols];
    try
    {
      int successOrNO = khoroshkin::inputArray(inputFile, dynamicMatrix, Rows * Cols);
      if (successOrNO != Rows*Cols)
      {
        std::cerr << "Error: was filled only " << successOrNO << " elements";
        delete[] dynamicMatrix;
        return 2;
      }
      std::ofstream outputFile(argv[3]);
      khoroshkin::fillingOutputFile(outputFile, dynamicMatrix, Rows, Cols);
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what();
      delete[] dynamicMatrix;
      return 2;
    }
    delete[] dynamicMatrix;
  }
  return 0;
}
