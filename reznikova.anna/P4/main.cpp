#include <iostream>
#include <fstream>
#include "findNumRowLsr.hpp"
#include "inputArray.hpp"

int main(int argc, char ** argv)
{
  using namespace reznikova;
  
  if (argc != 4)
  {
    std::cerr << "Wrong number of arguments.\n";
    return 1;
  }
  
  long long num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Can't parse a value.\n";
    return 1;
  }
  
  size_t rows = 0, cols = 0;
  {
    std::ifstream input(argv[2]);
    input >> rows;
    input >> cols;
    if (!input)
    {
      std::cerr << "Can't read an input.\n";
      return 2;
    }
    
    size_t result = 0;
    if (num == 1)
    {
      int smatrix[10000];
      for (size_t i = 0; i < rows * cols; i++)
      {
        input >> smatrix[i];
        if (!input)
        {
          std::cerr << "Wrong input. Readed only " << i << " out of " << (rows * cols) << "\n";
          return 2;
        }
      }
      result = reznikova::findNumRowLsr(smatrix, rows, cols);
    }
    
    else if (num == 2)
    {
      int * dmatrix = new int[rows * cols];
      size_t readed = 0;
      readed = reznikova::inputArray(input, dmatrix, rows * cols, rows * cols);
      if (readed != (rows * cols))
      {
        std::cerr << "Wrong input. Readed only " << readed << " out of " << (rows * cols) << "\n";
        delete [] dmatrix;
        return 2;
      }
      result = reznikova::findNumRowLsr(dmatrix, rows, cols);
      delete [] dmatrix;
    }
    
    else
    {
      std::cerr << "Argument num must be either 1 or 2. \n";
      return 2;
    }
    
    std::ofstream output(argv[3]);
    output << result << "\n";
  }
  
  return 0;
}
