#include <fstream>
#include "arrayModifications.h"

void inputArray(std::istream &cin, int *array, int n, int m)
{
  for (int i = 0; i < n * m; ++i) {
    cin >> array[i];
  }
}

void printArray(std::ostream &cout, int *array, int n, int m)
{
  cout << n << " " << m << " ";
  for (int i = 0; i < n * m; ++i) {
    cout << array[i] << " ";
  }
}

void setRight(int &dx, int &dy, int &x, int &y, int &move)
{
  move = 1;
  dx = 1;
  dy = 0;
  ++x;
  --y;
}

void setTop(int &dx, int &dy, int &x, int &y, int &move)
{
  move = 2;
  dx = 0;
  dy = -1;
  --x;
  --y;
}

void setLeft(int &dx, int &dy, int &x, int &y, int &move)
{
  move = 3;
  dx = -1;
  dy = 0;
  --x;
  ++y;
}

void setBottom(int &dx, int &dy, int &x, int &y, int &move)
{
  move = 4;
  dx = 0;
  dy = 1;
  ++x;
  ++y;
}

bool checkPosition(const bool *map, int x, int y, int m)
{
  return !map[(y - 1) * (m + 2) + x] ||
         !map[(y + 1) * (m + 2) + x] ||
         !map[y * (m + 2) + x - 1] ||
         !map[y * (m + 2) + x + 1] ||
         !map[y * (m + 2) + x];
}

void generateMap(bool *map, int n, int m){
  for (int i = 0; i < (n + 2) * (m + 2); ++i) {
    map[i] = false;
  }
  for (int i = 0; i < n + 2; ++i) {
    map[i * (m + 2)] = true;
    map[(i + 1) * (m + 2) - 1] = true;
  }
  for (int i = 0; i < m + 2; ++i) {
    map[i] = true;
    map[(n + 1) * (m + 2) + i] = true;
  }
}

void spiralIncrease(int *array, int n, int m)
{
  bool map[(n + 2) * (m + 2)];
  generateMap(map, n, m);

  int x = 1, y = n, move = 1, dx = 1, dy = 0;
//  1 - right
//  2 - top
//  3 - left
//  4 - bottom
  int i = 1;
  while (checkPosition(map, x, y, m)) {
    array[(y - 1) * m + x - 1] += i++;
    map[y * (m + 2) + x] = true;
    x += dx;
    y += dy;
    if (map[y * (m + 2) + x]) {
      switch (move) {
        case 1:
          setTop(dx, dy, x, y, move);
          break;
        case 2:
          setLeft(dx, dy, x, y, move);
          break;
        case 3:
          setBottom(dx, dy, x, y, move);
          break;
        case 4:
          setRight(dx, dy, x, y, move);
          break;
      }
    }
  }
}
