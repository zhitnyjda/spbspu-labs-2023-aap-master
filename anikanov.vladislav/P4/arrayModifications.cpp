#include <fstream>
#include "arrayModifications.h"

template<typename arrayType>
void inputArray(std::istream &cin, arrayType *array, int n, int m)
{
  for (int i = 0; i < n * m; ++i) {
    cin >> array[i];
  }
}

template<typename arrayType>
void printArray(std::ostream &cout, arrayType array, int n, int m)
{
  cout << n << " " << m << " ";
  for (int i = 0; i < n * m; ++i) {
    cout << array[i] << " ";
  }
}

template<typename arrayType>
void spiralIncrease(arrayType *array, int n, int m)
{
  bool map[(n + 2) * (m + 2)];
  for (bool &i: map) {
    i = false;
  }
  for (int i = 0; i < n + 2; ++i) {
    map[i * (m + 2)] = true;
    map[(i + 1) * (m + 2) - 1] = true;
  }
  for (int i = 0; i < m + 2; ++i) {
    map[i] = true;
    map[(n + 1) * (m + 2) + i] = true;
  }
  int x = 1, y = n, move = 1;
//  1 - right
//  2 - top
//  3 - left
//  4 - bottom
  int i = 1;
  while (!map[(y - 1) * (m + 2) + x] ||
         !map[(y + 1) * (m + 2) + x] ||
         !map[y * (m + 2) + x - 1] ||
         !map[y * (m + 2) + x + 1] ||
         !map[y * (m + 2) + x]) {
    switch (move) {
      case 1:
        array[(y - 1) * m + x - 1] += i++;
        map[y * (m + 2) + x] = true;
        ++x;
        if (map[y * (m + 2) + x]) {
          move = 2;
          --x;
          --y;
        }
        break;
      case 2:
        array[(y - 1) * m + x - 1] += i++;
        map[y * (m + 2) + x] = true;
        --y;
        if (map[y * (m + 2) + x]) {
          move = 3;
          --x;
          ++y;
        }
        break;
      case 3:
        array[(y - 1) * m + x - 1] += i++;
        map[y * (m + 2) + x] = true;
        --x;
        if (map[y * (m + 2) + x]) {
          move = 4;
          ++x;
          ++y;
        }
        break;
      case 4:
        array[(y - 1) * m + x - 1] += i++;
        map[y * (m + 2) + x] = true;
        ++y;
        if (map[y * (m + 2) + x]) {
          move = 2;
          ++x;
          --y;
        }
        break;
    }
  }
}
