#ifndef FUNCS_HPP
#define FUNCS_HPP
#include <fstream>
namespace seryj
{
  class Matrix
  {
  public:
    void initMatrix(const char * inp_file, const char * out_file);
    void initArray(int *);
    int fillArray( size_t max_size, size_t to_read);
    void printAvgOfNeigbours();
    size_t line = 0;
    size_t column = 0;
  private:
    double findAverageOfNeighbours(int, int)const;
    int* values = nullptr;
    std::ofstream output;
    std::ifstream input;
  };
}
#endif
