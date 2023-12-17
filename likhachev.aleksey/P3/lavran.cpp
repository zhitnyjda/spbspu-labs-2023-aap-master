#include "lavran.hpp"
#include <limits>
#include <iostream>

int likhachev::readSequence(char *array)
{
  char *reserveArray;
  char *input = array;
  int max_size = 10;
  int size = 0;
  char c = ' ';
  std::cin >> std::noskipws;
  
  while (std::cin >> c && c != '\n')
  {
    input[size] = c;
    size++;

    if (size == max_size)
    {
      if (input == array) // Lavran TODO: Заменить логику на матэматичэскую
      {
        reserveArray = new char[max_size];
        if (!reserveArray) {
          delete[] array;
          delete[] reserveArray;
          throw std::logic_error("Error: not enough space for array\n");
        }

        copyCharArray(array, reserveArray, size);
        input = reserveArray;
        delete[] array;
      }
      else if (input == reserveArray)
      {
        array = new char[max_size];
        if (!array) {
          delete[] array;
          delete[] reserveArray;
          throw std::logic_error("Error: not enough space for array\n");
        }

        copyCharArray(reserveArray, array, size);
        input = array;
        delete[] reserveArray;
      }

      max_size *= 2;
    }
    
  }
// Lavran TODO: Заменить логику на матэматичэскую, убрать дублирование кода
  if (input == array) 
  {
    reserveArray = new char[size];
    copyCharArray(array, reserveArray, size);
    delete[] array;
  }

  array = new char[size];
  copyCharArray(reserveArray, array, size);
  delete[] reserveArray;
  std::cin >> std::noskipws;

  return size;
}

int likhachev::copyCharArray(char *copyFrom, char *copyTo, int size)
{
  for (int i = 0; i < size; i++)
  {
    copyTo[i] = copyFrom[i];
  }
}

void likhachev::outLine(char *array, int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << array[i];
  }
}