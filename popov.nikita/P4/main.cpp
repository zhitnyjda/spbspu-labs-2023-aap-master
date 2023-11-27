#include <iostream>
#include <fstream>
#include "maximumSumStat.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  char * endOfParcing = nullptr;
  int num = std::strtoll(argv[1], &endOfParcing, 10);
  int rows = 0;
  int cols = 0;
  int max = 0;
  int sum = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (rows == 0 and cols == 0)
  {
    return 0;
  }
  if (num == 1)
  {
    using namespace popov;
    maxSumStat maxsSumStat;
    int a[10000] = {0};
    for (int i = 1; i <= rows * cols; ++i)
    {
      int value = 0;
      input >> value;
      a[i] = value;
    }
    maxsSumStat(a, &rows, &cols, &sum, &max);
    std::ofstream out(argv[3]);
    out << max;
  }
}
