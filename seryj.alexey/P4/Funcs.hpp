#ifndef FUNCS_HPP
#define FUNCS_HPP
#include <fstream>
namespace seryj
{
  size_t fillArray( size_t max_size, size_t to_read, std::ifstream, int *);
  void printAvgOfNeigbours(size_t line, size_t column, std::ofstream output, int* values);
  double findAverageOfNeighbours(size_t curr_line, size_t curr_column, size_t max_line, size_t max_column, int* values) const;
}
#endif
