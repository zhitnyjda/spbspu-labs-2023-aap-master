#include "Funcs.hpp"
#include <fstream>
#include <cmath>
namespace seryj
{
  size_t fillArray(size_t max_size, size_t to_read, std::ifstream & input, int * values)
  {
    for (size_t i = 0; i < std::min(to_read, max_size); ++i)
    {
      if (!(input >> *(values + i)))
        return i;
    }
    return std::min(to_read, max_size);
  }
  void printAvgOfNeigbours(size_t line , size_t column, std::ofstream & output, int * values)
  {
    output << line << " ";
    output << column << " ";
    for (size_t i = 0; i < line; i++)
      for (size_t j = 0; j < column; j++)
      {
        output << findAverageOfNeighbours(i, j, line, column, values) << " ";
      }
  }
  double findAverageOfNeighbours(size_t curr_line, size_t curr_column, size_t max_line, size_t max_column, int * values)
  {
    int count = 0;
    double sum = 0;
    for (size_t i = curr_line; i <= curr_line + 2; i++)
      for (size_t j = curr_column; j <= curr_column + 2; j++)
      {
        if (j > 0 && j <= max_column && i > 0 && i <= max_line)
        {
          sum += *(values + (i-1) * max_line + j - 1);
          count++;
         }
      }
    count--;
    sum -= *(values + curr_line * max_line + curr_column);
    return round(sum / count * 10) / 10;
  }
}
