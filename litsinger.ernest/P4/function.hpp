#ifndef FUNCTION_HPP
#define FUNCTION_HPP
namespace litsinger
{
  int fillArguments(int, const char* []);
  int readArray();
  int MaximalSum(int inputArr[100][100], int line, int column);
  int MaximalSumma(int** inputArr[100][100], int line, int column);
  class Matrix
  {
  public:
    int line;
    int column;
    int* values;
    void fillArray();
  };
}
#endif
