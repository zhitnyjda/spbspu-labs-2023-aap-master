#include <iostream>
#include <fstream>
#include <string>
#include "matrix_methods.hpp"
#include "functions.hpp"

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

    int stat[10000] = {0};
    int* arr;
    if (num == 1)
    {
      arr = stat;
    }
    else if (num == 2)
    {
      arr = new int[rows*cols];
    }
    try
    {
      inputToArr(inputFile, arr, rows*cols);
    }
    catch (const std::runtime_error& e)
    {
      std::cerr << e.what();
      if (num == 2)
      {
        delete[] arr;
      }
      return 3;
    }
    outputString += getIncreasedMatrixInline(arr, rows, cols);
    if (num == 2)
    {
      delete[] arr;
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
