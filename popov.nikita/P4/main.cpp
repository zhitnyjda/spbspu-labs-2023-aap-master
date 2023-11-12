#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }

  //argv[1]
  char * endOfParcing = nullptr;
  int num = std::strtoll(argv[1], &endOfParcing, 10);

  //argv[2]
  int rows = 0;
  int cols = 0;
  int max = 0;
  int sum = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (num == 1)
  {
    int a[10000] = {0};
    for (int i = 1; i <= rows * cols; ++i)
    {
      int value = 0;
      input >> value;
      a[i] = value;
    }
    for (int j = 1; j <= 2; ++j)
    {
      sum = 0;
      if (j == 1)
      {
        for (int i = 1; i < cols; ++i)
        {
          sum = 0;
          sum = sum + a[i];
          for (int q = 1; q < i; ++q)
          {
            sum = sum + a[i + (q * (rows - 1))];
          }
          if ((sum > max) and (i * j != 1))
          {
            max = sum;
          }
          if (i * j == 1)
          {
            if (max < a[j * i])
            {
              max = a[j * i];
            }
          }
        }
      }
      if (j == 2)
      {
        int count = rows;
        for (int w = rows * 2;w <= rows * cols;w + rows)
        {
          sum = 0;
          sum = a[w];
          count = count - 1;
          for (int e = 1; e < count; ++e)
          {
            sum = sum + a[w + (e * (rows - 1))];
          }
          if ((sum > max) and (w != rows * cols))
          {
            max = sum;
          }
          if (w == rows * cols)
          {
            if (max < a[w])
            {
              max = a[w];
            }
          }
        }
      }
    }
  }


  //argv[3]
//  std::ofstream output(argv[3]);
  //output << i << "\n";

}
