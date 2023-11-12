#include <iostream>
#include <fstream>
#include "funcs.hpp"

int main(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr << "Передано мало аргументов\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Передано много аргументов\n";
    return 1;
  }
  
  int number;
  try
  {
    number = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Первый аргумент задан неправильно\n";
    return 1;
  }
  
  if (number == 1 || number == 2)
  {
    size_t rows = 0, cols = 0;
    
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Cannot read an input.\n";
      return 2;
    }

    std::ofstream output(argv[3]);
    if (!output.is_open())
    {
      std::cerr << "Can't open an output file!\n";
      return 2;
    }

    size_t counter = 0;
    if (number == 1)
    {
      int statMatrix[10000] = {};
      if (!(sobolevsky::matrix::countMatrix(input, statMatrix, (cols * rows), counter)))
      {
        std::cerr << "Размер матрицы и кол-во чисел отличаются\n";
        return 2;
      }

    }
    else
    {
      int * dynMatrix = new int[rows * cols];
      if (!(sobolevsky::matrix::countMatrix(input, dynMatrix, (cols * rows), counter)))
      {
        std::cerr << "Размер матрицы и кол-во чисел отличаются\n";
        delete[] dynMatrix;
        return 2;
      }

    }
  }
  else
  {
    std::cerr << "Первый аргумент задан неправильно\n";
    return 1;
  }
  
}
