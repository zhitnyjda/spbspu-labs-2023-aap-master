#include "structs.hpp"
#include "functions.hpp"
#include <iostream>
#include <cstddef>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
  try
  {
    // checking params
    using namespace miheev;
    if (argc != 4)
    {
      throw std::invalid_argument("wrong arguments. Programm takes 3 positional");
    }
    //initing params
    long long num = 0;
    try
    {
      num = std::stoll(argv[1]);
    }
    catch(const std::invalid_argument& e)
    {
      std::cerr << "can't interpret first argument as integer\n";
      return 1;
    }

    size_t cols = 0, rows = 0;

    // reading matrix from file
    std::ifstream inputFile(argv[2]);
    inputFile >> rows >> cols;
    if (!inputFile)
    {
      std::cerr << "Can't read input\n";
      return 2;
    }

    Matrix matrix(rows, cols, num);
    size_t size = rows*cols;
    if(num == 1)
    {
      int arr[10000] = {0};
      inputToArr(inputFile, arr, size);
      matrix.initArr(arr);
    }
    else if(num == 2)
    {
      int* arr = new int[rows*cols]{};
      inputToArr(inputFile, arr, size);
      matrix.initArr(arr);
    }

    inputFile.close();

    matrix.increasePeriphery();
    std::cout << matrix.getMatrixInline() << '\n';
    // в связи с описанной проблемой, приделываю костыль,
    // чтобы программа работала
    std::string matrixInline = matrix.getMatrixInline();
    std::ofstream outFile(argv[3]);
    std::cout << matrix.getMatrixInline() << '\n';
    if (outFile.is_open())
    {
      std::cout << matrixInline << '\n';
      outFile << matrix.getNRows() << ' ' << matrix.getNCols() << ' ' << matrixInline;
    }

    return 0;
  }
  catch(const std::logic_error& logic_e)
  {
    std::cerr << logic_e.what();
    return 1;
  }
  catch(const std::runtime_error& e)
  {
    std::cout << e.what();
    return 2;
  }
}
