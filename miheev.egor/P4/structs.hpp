#ifndef STRUCTS_HPP
#define STRUCTS_HPP
#include <cstddef>
#include <fstream>

namespace miheev
{
  class Matrix
  {
  private:
    size_t nRows_;
    size_t nCols_;
    long long mode_;
    int* matrix_;

  public:
    Matrix (size_t rows, size_t cols, long long mode);
    ~Matrix();
    void initWithIfstream(std::ifstream& in);
    void printSelf() const;
    void increaseRectBorder(size_t xStart, size_t yStart, size_t width, size_t height, int increment);
    void increasePeriphery();
    std::string getMatrixInline() const;
    size_t getNRows() const;
    size_t getNCols() const;
  };
}
#endif
