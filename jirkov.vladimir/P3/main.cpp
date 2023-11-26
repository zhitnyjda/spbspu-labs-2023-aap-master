#include <iostream>
#include <iomanip>
int main()
{
  size_t read = 0;
  char sym = 0;
  size_t size
  std::cin >> std::noskipws;
  char * array = new char[size]{};
  while ((std::cin >> sym) && (sym != '\n'))
  {
    array[read++] = sym;
    if (read == size)
    {
      try
      {
        char * newarray = new char[size + add]{};
        for(size_t i = 0; i < size; i++)
        {
          newarray[i] = array[i];
        }
        delete[] array;
        char * array = newarray;
        delete[] newarray;
        size += add;
      }
      catch(const std::bad_alloc &e)
      {
        std::cerr << "Error big\n";
        return 1;
      }
    }
  }
  delete[] array;
  return 0;
}
