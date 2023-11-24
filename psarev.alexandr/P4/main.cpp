#include <iostream>
#include <fstream>
#include "matrixFuncs.hpp"

int main(int argc, char * argv[])
{
  if (argc != 4) {
    std::cerr << "Error: Wrong amount of parameters!\n";
    return 1;
  }
  int taskNum = 0;
  try
  {
    taskNum = std::stoll(argv[1]);
    if ((*argv[1] != '1') && (*argv[1] != '2')) {
      std::cerr << "Error: Wrong first argument value or type!\n";
      return 1;
    }
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Error: First argument must be an integer!\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  size_t rows = 0, cols = 0;
  if (!(input >> rows >> cols)) {
    std::cerr << "Error: Can't read input file!\n";
    return 2;
  }

  int verdict = 0;
  size_t counter = 0;
  if (taskNum == 1) {
    int arr[10000] = { 0 };
    if (psarev::inputMatrix(input, arr, rows*cols, counter) != (rows*cols)) {
      std::cerr << "Error: Mismatch of dimension and values!\n";
      return 2;
    }
    verdict = psarev::isTriMatrix(arr, rows, cols);
  } else if (taskNum == 2) {
    int* arr = new int[rows * cols];
    if (psarev::inputMatrix(input, arr, rows*cols, counter) != (rows*cols)) {
      std::cerr << "Error: Mismatch of dimension and values!\n";
      delete[] arr;
      return 2;
    }
    verdict = psarev::isTriMatrix(arr, rows, cols);
    delete[] arr;
  }

  std::ofstream output(argv[3]);
  if (!output.is_open()) {
    std::cerr << "Error: Can't open an output file!\n";
    return 2;
  }
  verdict == 1 ? output << "true\n": output << "false\n";

  return 0;
}
