#ifndef FUNCS_HPP
#define FUNCS_HPP
#include <fstream>
namespace seryj
{
  class Matrix
  {
  public:
    size_t initMatrix(const char * inp_file, const char * out_file);
    void initArray(int *);
    int fillArray( size_t max_size, size_t to_read);
    void printAvgOfNeigbours();
  private:
    double findAverageOfNeighbours(size_t, size_t)const;
    int* values = nullptr;
    size_t line = 0;
    size_t column = 0;
    std::ofstream output;
    std::ifstream input;
  };
}
#endif
