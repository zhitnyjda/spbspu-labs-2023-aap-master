#include <iostream>
#include <iomanip>

void swapStrings ( char * first, char * second, int size, const char * type)
{
  for (int i = 0; i < size;  i++)
  {
    second[i]=first[i];
  }
}

char * createBiggerString (int * size, char * first)
{
  char * secondInput = new char [(*size)+(*size)]{};
  swapStrings(first, secondInput, (*size), "second");
  (*size)+=(*size);
  delete [] first;
  first = new char [(*size)]{};
  swapStrings(secondInput, first, (*size), "first");
  delete [] secondInput;
  return first;
}

int main()
{
  int size = 20;
  char * firstInput = new char[size]{};
  char c = 0;
  size_t read = 0;
  std::cin >> std::noskipws;
  while ((std::cin >> c) && (read < size))
  {
    firstInput[read++] = c;
    if (c == '\n')
    {
      firstInput[read - 1] = 0;
      break;
    }
    firstInput =(c != '\n' && read == size)? createBiggerString (&size, firstInput): firstInput;
  }
  std::cin >> std::skipws;
  delete [] firstInput;
}
