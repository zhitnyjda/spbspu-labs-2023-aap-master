#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

namespace likhachev
{
  struct Point {
    public:
      int x;
      int y;
      Point();
      Point(int newX, int newY);
      void operator()(int newNumber);
      Point& operator+=(const Point& rhs);
  };

  struct Matrix {
  public:
    Matrix(char type, int mCols, int mRows);
    void readFromFile(std::string fileName);
    void inputInFile(std::string fileName);
    Point getSize() const;
    int * getValues() const;
    int * values;
  private:
    Point size;
  };

  void changeMatrixWithSpiral(Matrix& matrix);
  int countNonRepeatColumns(Matrix& matrix);
};
#endif

// Lavran [ToDo] : Создать структуру "point"
// Lavran [ToDo] : Создать метод вывода матрицы в файл