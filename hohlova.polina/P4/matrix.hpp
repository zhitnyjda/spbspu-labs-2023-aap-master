#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace hohlova
{
  class matrix
  {
  public:
    size_t inputArray(std::ifstream & in, int * matrix, size_t sizem, size_t toRead);
    int ** createMatrix(size_t rows, size_t cols);
    void freeMatrix(int ** matrix, size_t rows);
    void freeMatrix(int ** matrix, size_t rows, size_t cols);
    size_t countRows(int currRow, int currCol);
  private:
    size_t rows;
    size_t cols;
    int currRow;
    int currCol;
    int * matrix;
    size_t sizem;
    size_t toRead;
  };
}
#endif
