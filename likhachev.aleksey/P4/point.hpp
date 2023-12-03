#ifndef POINT_HPP
#define POINT_HPP

namespace likhachev
{
  struct Point {
    public:
      int x;
      int y;
      Point();
      Point(int newX, int newY);
      void operator()(int newNumber);
      Point operator+(const Point& rhs);
      Point operator-(const Point& rhs);
      Point& operator+=(const Point& rhs);
      Point& operator-=(const Point& rhs);
  };
}
#endif
