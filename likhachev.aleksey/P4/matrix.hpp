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
      Point& operator%(const Point& rhs);
  };

  void inputMatrixFromFile(Point size, std::ifstream& inStream, int* values);
  void outputMatrixToFile(Point size, std::ofstream& outStream, int* values);

  void coutMatrix(Point size, int* values);
  void changeMatrixWithSpiral(Point size, int* values);
  int countNonRepeatColumns(Point size, int* values);
};
#endif