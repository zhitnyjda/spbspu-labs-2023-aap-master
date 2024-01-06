#include "sequences.hpp"
#include <iostream>
#include <cctype>

int likhachev::readSequence(char *array)
{

  int max_size = 10;
  int size = 0;
  char *inputData[2] = { nullptr, nullptr };
  inputData[0] = new char[max_size];
  char *input = inputData[0];
  char c = ' ';
  std::cin >> std::noskipws;

  while (std::cin >> c && c != '\n')
  {
    input[size] = c;
    size++;

    if (size == max_size)
    {
      max_size *= 2;

      int oldInputId = (input == inputData[0]) ? 0 : 1;
      int newInputId = (oldInputId + 1) % 2;

      inputData[newInputId] = new char[max_size];
      if(!inputData[newInputId])
      {
        delete[] input;
        delete[] inputData[oldInputId];
        std::cin >> std::noskipws;
        throw std::logic_error("Error: not enough space for array\n");
      }

      copyCharArray(inputData[oldInputId], inputData[newInputId], size);
      input = inputData[newInputId];
      delete[] inputData[oldInputId];
    }

  }

  int inputId = (input == inputData[0]) ? 0 : 1;
  delete[] array;
  array = new char[size];
  if (!array) {
    delete[] input;
    delete[] inputData[inputId];
    std::cin >> std::noskipws;
    throw std::logic_error("Error: not enough space for array\n");
  }
  copyCharArray(input, array, size);

  delete[] input;
  delete[] inputData[inputId];
  std::cin >> std::noskipws;
  return size;
}

void likhachev::copyCharArray(char *copyFrom, char *copyTo, int size)
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

int likhachev::strDoesHasSame(char *array1, int size1, char *array2, int size2)
{
  int haseSame = 0;

  int i = 0;
  int j = 0;
  while (i < size1 && !haseSame) {
    while (j < size2 && !haseSame) {
      if (array1[i] == array2[j]) {
        haseSame = 1;
      }
      j++;
    }
    j = 0;
    i++;
  }

  return haseSame;
}

int likhachev::strRemoveDigits(char *array, int size)
{
  char *newArray = new char[size];

  int counter = 0;
  for (int i = 0; i < size; i++) {
    if (!std::isdigit(array[i])) {
      newArray[counter] = array[i];
      counter++;
    }
  }

  delete[] array;
  array = new char[counter];
  copyCharArray(newArray, array, counter);

  return counter;
}
