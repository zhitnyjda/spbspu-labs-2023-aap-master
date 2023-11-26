#include <iostream>
#include <fstream>
#include <cstring>
#include "funcs.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Передано не 4 аргумента\n";
    return 1;
  }

  int number;
  try
  {
    for (size_t i=0; i < strlen(argv[1]); i++)
    {
      if (!(isdigit(argv[1][i])))
      {
        std::cerr << "Первый аргумент должен быть интом\n";
        return 1;
      }
    }
    number = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Первый аргумент должен быть интом\n";
    return 1;
  }

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

    int * arr = nullptr;
    if (number == 1)
    {
      int matrix[10000] = {};
      arr = matrix;
      size_t counter = sobolevsky::sizeMatrix(input, arr, (cols * rows));
      if (counter != (cols*rows))
      {
        std::cerr << "Размер матрицы и кол-во чисел отличаются\n";
        return 2;
      }
      (sobolevsky::isTrianglMatrix(arr, rows, cols)) == true ? output << "true\n" : output << "false\n";
      return 0;
    }
    else
    {
      int * matrix = new int[cols * rows];
      arr = matrix;
      size_t counter = sobolevsky::sizeMatrix(input, arr, (cols * rows));
      if (counter != (cols*rows))
      {
        std::cerr << "Размер матрицы и кол-во чисел отличаются\n";
        delete[] arr;
        return 2;
      }
      (sobolevsky::isTrianglMatrix(arr, rows, cols)) == true ? output << "true\n" : output << "false\n";
      delete[] arr;
      return 0;
    }
  }
  else
  {
    std::cerr << "Первый аргумент должен быть либо 1 либо 2\n";
    return 1;
  }
}
