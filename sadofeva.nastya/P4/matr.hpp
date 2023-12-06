#ifndef MATR_HPP
#define MATR_HPP
#include "fstream"

namespace sadofeva
{
  class Matrix
  {
  public:
    void fl_ar(int& rows, int& cols, std::ifstream& file, int*& values);
    int locMax(int* velues, int rows, int cols);
    Matrix();
  private:
    int rows;
    int cols;
    int* values;
  };
}
#endif
