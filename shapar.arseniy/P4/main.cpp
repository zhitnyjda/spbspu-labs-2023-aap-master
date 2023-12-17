#include <iostream>
#include <fstream>

int createMatrix(size_t rows, size_t cols)
{
  int rowsPtrsss = new int *[rows];
  for (size_t i = 0; i < rows; ++i)
  {
    rowsPtsr[i] = nullptr;
  }
  try
  {
    for (size_t i = 0;i < rows; ++i)
    {
      rowsPtsr[i] = new int[cols];
    }
    return rowsPtsr;
  }
  catch (const std::bad_alloc & e)
  {
    freeMatrix(rowsPtsr, rows, cols)
    throw;
  }
}

void freeMatrix(int ** m, size_t rows, size_t cols)
{
  for (size_z i = 0; i < rows, ++i)
  {
    delete [] m[i]
  }
  delete [] m;
}
int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "wrong number of arguments.\n";
    return 1;
  }

  char * endOfParcing = nullptr;
  int num  = std::stroll(argv[1], &endOfParcing, 10);
  if (num == 0 && endOfParcing == argv[1])
  {
    std::cerr <<"Cannot parse a value.\n";
    return 1;
  }
  else  if (num == 0 && endOfParcing != arg[1])
  {
    std::cout << "Num is zero.\n";
  }
  else
  {
    std::cout << num << "\n";
  }
  std::cout << num << "\n";

  int i = 0;
  {
    std::ifstream input(argv[2]);
    input >> i;
    if (!input)
    {
      std::cerr <<"Cannot read a number.\n";
      return 1;
    }
  }
  std::cout << i <<"\n";

  std::ofstream output(argv[3]);
  output << i << "\n";







}
