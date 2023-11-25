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
  return indexOfLastFree;
}

void extendString(char* str, size_t strSize, size_t buffSize)
{
  size_t sizeExtended = strSize + buffSize;
  char* temp = new char[sizeExtended];
  copyBufferToString(str, strSize, 0, temp, sizeExtended);
  str = temp;
  temp = nullptr;
}

bool cinToBuffer(char* buffer, size_t buffSize)
{
  std::cin >> std::noskipws;
  size_t buffIndex = 0;
  char c = 0;
  while (std::cin >> c)
  {
    std::cout << "buffIndex = " << buffIndex << '\n';
    buffer[buffIndex++] = c;
    if (c == '\n')
    {
      buffer[buffIndex - 1] = 0;
      break;
    }
    if(buffIndex >= buffSize)
    {
      return false;
    }
  }
  std::cin >> std::skipws;
  std::cout << buffIndex << " ?= " << buffSize << '\n';
  return true;
}

int main(int argc, char* argv[])
{
  const size_t BUFF_SIZE = 5;
  char buffer[BUFF_SIZE] = {0};
  char* str = new char[BUFF_SIZE]{};
  size_t strIndex = 0;

  std::cout << cinToBuffer(buffer, BUFF_SIZE) << '\n';
  printArr(buffer, BUFF_SIZE);

  return 1;
}