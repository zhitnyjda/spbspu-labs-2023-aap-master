#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{
  
  // читаем параметры командной строки (проверка на колличество)
  if (argc != 4)
  {
    std::cerr << "Wrong number of arguments.\n";
    return 1;
  }
  
  // читаем параметры командной строки (чтение параметра num и проверка на адекватность)
  try
  {
    long long num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Cannot parse a value\n";
    return 1;
  }
  long long num = std::stoll(argv[1]);
  
  // читаем input (колличество строк и столбцов)
  size_t rows = 0, cols = 0;
  {
    std::ifstream input(argv[2]);
    input >> rows;
    input >> cols;
    if (!input)
    {
      std::cerr << "Cannot read an input\n";
      return 2;
    }
  }
  
  if (num > 2)
  {
    std::cerr << "Argument num must be either 1 or 2\n";
    return 2;
  }
  else if (num == 1)   // для num 1 (статический массив)
  {
      int smatrix[10000];
      
      {
        std::ifstream input(argv[2]);
        input.seekg(3);
        for (int i = 0; i < rows * cols; i++)
        {
          input >> smatrix[i];
          if (!input)
          {
            std::cerr << "Cannot read an input.\n";
            return 2;
          }
        }
      }
      
  }
    
  // для num 2 динамический массив
  // ??????
  
  return 0;
}

