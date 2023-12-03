#include "point.hpp"

likhachev::Point::Point():
  x(0),
  y(0)
{}

likhachev::Point::Point(int newX, int newY):
  x(newX),
  y(newY)
{}

likhachev::Point likhachev::Point::operator+(const Point& rhs)
{
  x += rhs.x;
  y += rhs.y;
  return *this;
}

likhachev::Point likhachev::Point::operator-(const Point& rhs)
{
  x -= rhs.x;
  y -= rhs.y;
  return *this;
}

likhachev::Point& likhachev::Point::operator+=(const Point& rhs)
{
  *this = *this + rhs;
  return *this;
}

likhachev::Point& likhachev::Point::operator-=(const Point& rhs)
{

  *this = *this - rhs;
  return *this;
}
