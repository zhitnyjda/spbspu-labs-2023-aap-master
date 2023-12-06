#include <iostream>
#include <fstream>
int createMatrix(size_t rows, size_t cols)
{
  int rowsPtrs = new int * [rows];
  for (size_t i = 0; i < rows; i++)
  {
    rowsPtrs[i] = nullptr;
  }
  try
  {
    for (size_t i = 0; i < rows; i++)
    {
      rowsPtrs[i] new int[cols];
    }
    return rowsPtrs;
  }
  catch (const std::bad_alloc & e)
  {
    freeMatrix(rowsPtrs, rows, cols);
    throw;
  }
}

void freeMatrix(int ** m, size_t rows, size_t cols)
{
  for (size_t i = 0;i < rows; i++)
  {
    delete [] m[i];
  }
  delete [] m;
}



int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Smt wrong , I can feel it... \n";
    return 1;
  }

  //arg[1] - номер задания
  int num_input = 0;
  try
  {
    num_input = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Can not parce a value... \n";
    return 1;
  }

 //argv[2] - имя файла с матрицей
  int num = 0;
  {
    std::ifstream input(argv[2]);
    input >> num;
    if (!input)
    {
       std::cerr << "Can not read a number... \n";
       return 1;
    }
  }
  std::cout << num << "\n";

  //argv[3] - имя файла для вывода результатов
  std::ofstream output(argv[3]);
  output << rows << " " << cols << "\n";


  //num == 1;
  //int a[10000]

  //num == 2
  //size_t rows = 0;
  //size_t cols = 0;
  //input >> rows >> cols;
  // int * a = new int[rows * cols]
  // a[i * cols + j]
  int ** m1 = nullptr;

  try
  {
    m1 = createMatrix(rows, cols);
    m2 = createMatrix(rows, cols);
    // go brrr...
    freeMatrix(m1, rows, cols);
    freeMatrix(m2, rows, cols);
  }
  catch (....)
  {
    freeMatrix(m1, rows, cols);
    freeMatrix(m2, rows, cols);
    
}
