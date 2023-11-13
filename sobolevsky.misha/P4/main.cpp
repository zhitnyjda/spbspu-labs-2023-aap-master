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
    std::cerr << "Первый аргумент должен быть интом\n";
    return 1;
  }

  sobolevsky::matrix currMatrix;
  if (number == 1 || number == 2)
  {
    size_t rows = 0, cols = 0;

    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Невозможно открыть input файл\n";
      return 2;
    }

    std::ofstream output(argv[3]);
    if (!output.is_open())
    {
      std::cerr << "Невозможно открыть output файл\n";
      return 2;
    }

    if (number == 1)
    {
      int statMatrix[10000] = {};
      if (!(currMatrix.countMatrix(input, statMatrix, (cols * rows))))
      {
        std::cerr << "Размер матрицы и кол-во чисел отличаются\n";
        return 2;
      }
      (currMatrix.isTrianglMatrix(statMatrix, rows, cols)) == true ? output << "true\n" : output << "false\n";
      return 0;
    }
    else
    {
      int * dynMatrix = new int[rows * cols];
      if (!(currMatrix.countMatrix(input, dynMatrix, (cols * rows))))
      {
        std::cerr << "Размер матрицы и кол-во чисел отличаются\n";
        delete[] dynMatrix;
        return 2;
      }
      (currMatrix.isTrianglMatrix(dynMatrix, rows, cols)) == true ? output << "true\n" : output << "false\n";
      delete[] dynMatrix;
      return 0;
    }
  }
  else
  {
    std::cerr << "Первый аргумент должен быть либо 1 либо 2\n";
    return 1;
  }
}
