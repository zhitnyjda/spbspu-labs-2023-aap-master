#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

namespace likhachev
{
  struct Matrix {
  public:
    Matrix(int mCols, int mRows);
    void read(std::string);
    int getCols() const;
    int getRows() const;
    int * getValues() const;
  private:
    int cols;
    int rows;
    int * values;
  };

  Matrix createSpiralMatrix(int cols, int rows);
  int countNonRepeatColumns(Matrix);
};
#endif
