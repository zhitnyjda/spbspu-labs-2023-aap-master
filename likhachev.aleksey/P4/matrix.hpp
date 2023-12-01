#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

namespace likhachev
{
  struct Matrix {
  public:
    Matrix(char type, int mCols, int mRows);
    void read(std::string);
    int getCols() const;
    int getRows() const;
    int * getValues() const;
    int * values;
  private:
    int cols;
    int rows;
  };

  void changeMatrixWithSpiral(Matrix& matrix);
  int countNonRepeatColumns(Matrix);
};
#endif

// Lavran [ToDo] : Создать структуру "point"
// Lavran [ToDo] : Создать метод вывода матрицы в файл