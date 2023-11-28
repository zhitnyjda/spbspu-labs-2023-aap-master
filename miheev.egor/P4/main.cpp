#include "structs.hpp"
#include "functions.hpp"
#include <iostream>
#include <cstddef>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
  try
  {
    // checking params
    using namespace miheev;
    if (argc != 4)
    {
      std::cerr << "Wrong amount of arguments\n";
      return 1;
    }
    //initing params
    long long num = 0;
    try
    {
      num = std::stoll(argv[1]);
    }
    catch(const std::invalid_argument& e)
    {
      std::cerr << "can't interpret first argument as integer\n";
      return 1;
    }

    size_t cols = 0, rows = 0;

    // reading matrix from file
    std::ifstream inputFile(argv[2]);
    inputFile >> rows >> cols;
    if (!inputFile)
    {
      std::cerr << "Can't read input\n";
      return 2;
    }

    std::string outputString = std::to_string(rows) + " " + std::to_string(cols);

    if (num == 1)
    {
      int sarr[10000] = {0};
      try
      {
      inputToArr(inputFile, sarr, rows*cols);
      outputString += getIncreasedMatrixInline(sarr, rows, cols);
      }
      catch(const std::runtime_error& e)
      {
        std::cout << e.what();
        return 3; // temporary
      }
      catch(...)
      {
        std::cout << "Unexpected error while trying to init arr\n";
        return 3; // temporary
      }
    }
    else if (num == 2)
    {
      int* darr = new int[rows*cols]{};
      try
      {
        inputToArr(inputFile, darr, rows*cols);
        outputString += getIncreasedMatrixInline(darr, rows, cols);
        delete[] darr;
      }
      catch(const std::runtime_error& e)
      {
        delete[] darr;
        std::cerr << e.what();
        return 3; // temporary
      }
      catch(...)
      {
        delete[] darr;
        std::cerr << "unexpected error\n";
        return 3; // temporary
      }
    }

    inputFile.close();
    std::ofstream outFile(argv[3]);
    outFile << outputString;

    return 0;
  }
  catch(const std::logic_error& logic_e)
  {
    std::cerr << logic_e.what();
    return 1;
  }
  catch(const std::runtime_error& e)
  {
    std::cout << e.what();
    return 2;
  }
}
