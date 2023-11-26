#include "lavran.hpp"
#include <limits>
#include <iostream>

likhachev::CharSequence::CharSequence() : array1(new char[size]{}), array2(new char[size]{}),
                      input(array1), size(10)
{
}

void likhachev::CharSequence::read()
{
  int counter = 0;
  char c = ' ';
  while (std::cin >> c)
  {
    if (c == '\n')
    {
      break;
    }

    input[counter] = c;
    counter++;

    if (counter == size)
    {
      switchInput();
    }
  }

  size = counter;
}

void likhachev::CharSequence::outValues()
{
  for (int i = 0; i < size; i++)
  {
    std::cout << input[i];
  }
}

void likhachev::CharSequence::switchInput()
{
  if (input == array1)
  {
    array2 = new char[size * 2];
    moveValues(1);
    input = array2;
    delete[] array1;
  }
  else if (input == array2)
  {
    array1 = new char[size * 2];
    moveValues(0);
    input = array1;
    delete[] array2;
  }

  size *= 2;
}

void likhachev::CharSequence::moveValues(int isStraight)
{
  if (isStraight)
  {
    for (int i = 0; i < size; i++)
    {
      array2[i] = array1[i];
    }
  }
  else
  {
    for (int i = 0; i < size; i++)
    {
      array1[i] = array2[i];
    }
  }
}
