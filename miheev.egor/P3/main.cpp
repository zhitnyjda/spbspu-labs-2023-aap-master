//DIF-LAT
#include <iostream>
#include <iomanip>

void printArr(char* arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    std::cout << arr[i];
  }
  std::cout << '\n';
}

size_t copyBufferToString(char* buffer, size_t buffSize, size_t startIndex, char* str, size_t strSize)
{
  // returns index of the first free cell
  size_t indexOfLastFree = startIndex;
  while (indexOfLastFree < startIndex + buffSize)
  {
    str[indexOfLastFree] = buffer[indexOfLastFree - startIndex];
    indexOfLastFree++;
  }

  printArr(str, strSize);
  return indexOfLastFree;
}


int main(int argc, char* argv[])
{
  const size_t BUFF_SIZE = 5;
  char buffer[BUFF_SIZE];
  char* str = new char[BUFF_SIZE]{};
  char c = 0;
  size_t buffIndex = 0;

  std::cin >> std::noskipws;
  while ((std::cin >> c) && (buffIndex < BUFF_SIZE))
  {
    buffer[buffIndex++] = c;
    if (c == '\n')
    {
      buffer[buffIndex - 1] = 0;
      break;
    }
  }
  std::cin >> std::skipws;
  // std::cout << buffer << '\n';
  copyBufferToString(buffer, BUFF_SIZE, 0, str, BUFF_SIZE);
  return 1;
}