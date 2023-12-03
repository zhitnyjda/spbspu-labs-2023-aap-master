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
    void inputFromFile(std::ifstream& inStream);
    void outputToFile(std::ofstream& outStream);
    Point getSize() const;
    int * getValues() const;
    int * values;
  private:
    Point size;
  };

  void coutMatrix(Matrix& matrix);
  void changeMatrixWithSpiral(Matrix& matrix);
  int countNonRepeatColumns(Matrix& matrix);
};
#endif