//DIF-LAT
#include "str.hpp"
#include "buffer.hpp"
#include <cctype>
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

void cleanBuffer(char* buffer, size_t buffSize)
{
  for (size_t i = 0; i < buffSize; i++)
  {
    buffer[i] = 0;
  }
}

size_t copyBufferToString(char* buffer, size_t buffSize, size_t startIndex, char* str, size_t& strSize);

size_t extendString(char* str, size_t strSize, size_t buffSize)
{
  size_t sizeExtended = strSize + buffSize;
  char* temp = new char[sizeExtended];
  copyBufferToString(str, strSize, 0, temp, sizeExtended);
  str = temp;
  temp = nullptr;
  return sizeExtended;
}

size_t copyBufferToString(char* buffer, size_t buffSize, size_t startIndex, char* str, size_t& strSize)
{
  // returns index of the first free cell
  if (startIndex + buffSize > strSize)
  {
    strSize = extendString(str, strSize, buffSize);
  }
  size_t indexOfLastFree = startIndex;
  while (indexOfLastFree < startIndex + buffSize && buffer[indexOfLastFree - startIndex])
  {
    std::cout << buffer[indexOfLastFree - startIndex] << '\n';
    str[indexOfLastFree] = buffer[indexOfLastFree - startIndex];;
    indexOfLastFree++;
  }
  return indexOfLastFree;
}

bool cinToBuffer(char* buffer, size_t buffSize)
{
  printArr(buffer, buffSize);
  std::cin >> std::noskipws;
  size_t buffIndex = 0;
  char c = 0;
  while (std::cin >> c)
  {
    std::cout << "c = " << c << '\n';
    buffer[buffIndex++] = c;
    if (c == '\n')
    {
      buffer[buffIndex - 1] = 0;
      break;
    }
    if(buffIndex >= buffSize)
    {
      printArr(buffer, buffSize);
      return false;
    }
  }
  std::cin >> std::skipws;
  return true;
}

// Знал бы как использовать хэш-талбицу - было бы проще, ну а пока реализуем за n^2

int main(int argc, char* argv[])
{
  using namespace miheev;
  const size_t BUFF_SIZE = 5;
  Buffer buffer(BUFF_SIZE);
  String str;

  bool isEnd = false;
  while(!isEnd)
  {
    buffer.clean();
    isEnd = buffer.fillFromCin();
    str.fillFromBuff(buffer);
  }
  str.print();

  return 0;
}

