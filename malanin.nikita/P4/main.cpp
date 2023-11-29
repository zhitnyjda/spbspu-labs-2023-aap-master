#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Smt wrong , I can feel it... \n";
    return 1;
  }

  //arg[1] - номер задания
/* char * end_parcing = nullptr;
  int num_input = std::strtoll(argv[1], &end_parcing, 10);
  if (num_input == 0 && end_parcing == argv[1])
  {
    std::cerr << "Can not parce a value... \n";
    return 1;
  }
  else if (num_input == 0 && end_parcing != argv[1])
  {
    std::cout << "Num is zero... \n";
  }
  else
  {
    std::cout << num_input << "\n";
  } */
// Аналог на C++

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
  output << num << "\n";

}
