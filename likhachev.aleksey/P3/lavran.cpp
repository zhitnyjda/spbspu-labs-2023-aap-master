#include "lavran.hpp"
#include <limits>
#include <iostream>

int likhachev::readSequence(char *array)
{
  char *reserveArray;
  char *input = array;
  int size = 0;
  char c = ' ';
  while (std::cin >> c)
  {
    
    if (c == '\n')
    {
      break;
    }

    input[size] = c;
    size++;

    if (size == size)
    {
      if (input == array) // Lavran TODO: Заменить логику на матэматичэскую
      {
        reserveArray = new char[size * 2];
        copyCharArray(array, reserveArray, size);
        input = reserveArray;
        delete[] array;
      }
      else if (input == reserveArray)
      {
        array = new char[size * 2];
        copyCharArray(reserveArray, array, size);
        input = array;
        delete[] reserveArray;
      }

      size *= 2;
    }
    
  }

  if (input == array) // Lavran TODO: Заменить логику на матэматичэскую, убрать дублирование кода
  {
    reserveArray = new char[size * 2];
    copyCharArray(array, reserveArray, size);
    input = reserveArray;
    delete[] array;
  }
  else if (input == reserveArray)
  {
    array = new char[size * 2];
    copyCharArray(reserveArray, array, size);
    input = array;
    delete[] reserveArray;
  }

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