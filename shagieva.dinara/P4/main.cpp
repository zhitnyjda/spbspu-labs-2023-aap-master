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

  if (!input)
  {
    std::cerr << "Cannot read matrix data";
    return 2;
  }

  int numberOfRows = 0;
  input >> numberOfRows;

  int numberOfColumns = 0;
  input >> numberOfColumns;

  int * values = 0;
  int result = 0;

  if (task == 1)
  {
    int staticArray[10000] = { 0 };
    values = staticArray;
  }

  if (task == 2)
  {
    int * dynamicArray = new int[numberOfRows * numberOfColumns];
    values = dynamicArray;
  }

  try
  {
    read(input);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << e.what() << "\n";
    if (task == 2)
    {
      delete[] dynamicArray
    }
    return 2;
  }

  result = findMaxColumn();

  std::ofstream output;
  output.open(argv[3]);

  if (!output.is_open())
  {
    std::cerr << "Cannot open an output file.\n";
    return 2;
  }

  output << result;

  if (task == 2)
  {
    delete[] dynamicArray;
  }

  return 0;
}
