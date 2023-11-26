#include <iostream>
#include <iomanip>
#include <iosfwd>

char* resizeArray(char* array, size_t size, size_t newSize)
{
  char* newArray = new char[newSize+1];
  for (size_t i = 0; i < size; i++)
  {
    newArray[i] = array[i];
  }
  for (size_t j = size; j < newSize; j++)
  {
    newArray[j] = '0';
  }
  delete[] array;
  return newArray;
}

int main()
{
  char ch = 0;
  size_t readEl = 0;
  size_t size = 20;
  char* input = new char [size] {};
  std::cin >> std::noskipws;
  while (std::cin >> ch)
  {
    if (readEl < size)
    {
      input[readEl++] = ch;
      if (ch == '\n')
      {
        input[readEl - 1] = 0;
        break;
      }
    }
    else
    {
      input = resizeArray(input, size, size + 20);
      size += 20;
      input[readEl++] = ch;
    }
  }
  for (size_t i = 0; i < readEl - 1; i++)
  {
    for (size_t j = i + 1; j < readEl; j++)
    {
      if (input[i] == input[j])
      {
        std::cout << input[i];
        input[i] = '\0';
        input[j] = '\0';
      }
    }
  }
  std::cin >> std::skipws;
  std::cout << input << '\n';
  delete[] input;
  return 0;
}
