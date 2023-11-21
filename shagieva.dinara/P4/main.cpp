#include <iostream>
#include <fstream>
#include "matrix.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Wrong number of input parameters.\n";
    return 1;
  }

  int task = 0;

  try
  {
    task = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Cannot read the value of task.\n";
    return 1;
  }

  if (task != 1 && task != 2)
  {
    std::cerr << "Task does not exist.\n";
    return 1;
  }

  std::ifstream input;
  input.open(argv[2]);

  std::ofstream output;
  output.open(argv[3]);

  using namespace shagieva;
  Matrix matrix;

  input >> matrix.numberOfRows;
  input >> matrix.numberOfColumns;

  if (!input)
  {
    std::cerr << "Cannot read matrix data";
    return 2;
  }

  if (!output.is_open())
  {
    std::cerr << "Cannot open an output file.\n";
    return 2;
  }

  int result = 0;

  if (task == 1)
  {
    int staticArray[10000] = { 0 };
    matrix.values = staticArray;

    try
    {
      matrix.read(input);
    }
    catch (const std::invalid_argument & e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }

    result = matrix.findMaxColumn();
    output << result;
  }

  if (task == 2)
  {
    int * dynamicArray = new int[matrix.numberOfRows * matrix.numberOfColumns];
    matrix.values = dynamicArray;

    try
    {
      matrix.read(input);
    }
    catch (const std::invalid_argument & e)
    {
      std::cerr << e.what() << "\n";
      delete[] dynamicArray;
      return 2;
    }

    result = matrix.findMaxColumn();
    output << result;
    delete[] dynamicArray;
  }
  return 0;
}
