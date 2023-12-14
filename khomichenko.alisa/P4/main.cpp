#include <iostream>
#include <fstream>
#include "inputArray.hpp"
int main(int argc, char ** argv)
{
  using namespace khomichenko;
  if (argc !=4)
  {
    std::cerr<<"something wrong.\n";
    return 1;
  }
  //argv[1] -номер задания
  int num=0;
  try
  {
    num=std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr<<"can not parse a value\n";
    return 1;
  }
  if (num > 2 || num < 1)
  {
    std::cerr<<"first parameter is out of range\n";
    return 1;
  }
  //argv[2]-имя файла с матрицей
  size_t rows;
  size_t cols;

  std::ifstream input (argv[2]);

  input>> rows>> cols;
  if (!input)
  {
    std::cerr<<"can not read file\n";
    return 2;
  }
  std::cout<<rows<<" "<<cols<<"\n";
  int firstMatrix[10000]={0};
  int* Matrix = firstMatrix;
  if (num==2)
  {
    Matrix=new int[rows * cols];
  }
  int hadRead = inputArray(input, Matrix, rows, cols);
  if (hadRead != std::min(rows,cols))
  {
    std::cerr<<"not all elements were read\n";
    if (num==2)
    {
      delete [] Matrix;
    }
    return 2;
  }
  //argv[3]-имя файла для вывода результатов
  if (num==2)
  {
    delete [] Matrix;
  }
  //std::ofstream output (argv[3]);
  //output << Matrix << "\n";
}

