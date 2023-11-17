#include <iostream>
#include <fstream>
#include "findNumRowLsr.hpp"
#include "inputArray.hpp"

int main(int argc, char ** argv)
{
  using namespace matrixStuff;
  using namespace readArray;
  
  if (argc != 4)
  {
    std::cerr << "Wrong number of arguments.\n";
    return 1;
  }
  
  try
  {
    long long num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Can't parse a value. \n";
    return 1;
  }
  long long num = std::stoll(argv[1]);
  
  size_t rows = 0, cols = 0;
  {
    std::ifstream input(argv[2]);
    input >> rows;
    input >> cols;
    if (!input)
    {
      std::cerr << "Can't read an input. \n";
      return 2;
    }
  }
  
  if (num == 1)
  {
    int smatrix[10000];
    {
      std::ifstream input(argv[2]);
      input.seekg(3);
      for (int i = 0; i < rows * cols; i++)
      {
        input >> smatrix[i];
        if (!input)
        {
          std::cerr << "Can't read an input.\n";
          return 2;
        }
      }
    }
    {
      std::ofstream output(argv[3]);
      output << matrixStuff::findNumRowLsr(smatrix, rows, cols) << "\n";
    }
  }
  
  else if (num == 2)
  {
    int * dmatrix = new int[rows * cols];
    {
      std::ifstream input(argv[2]);
      input.seekg(3);
      try
      {
        readArray::inputArray(input, dmatrix, rows * cols, rows * cols);
      }
      catch(const std::exception & e)
      {
        std::cerr << e.what();
        delete [] dmatrix;
        return 2;
      }
    }
    {
      std::ofstream output(argv[3]);
      output << matrixStuff::findNumRowLsr(dmatrix, rows, cols) << "\n";
    }
    delete [] dmatrix;
  }
  
  else
  {
    std::cerr << "Argument num must be either 1 or 2. \n";
    return 2;
  }
  
  return 0;
}
