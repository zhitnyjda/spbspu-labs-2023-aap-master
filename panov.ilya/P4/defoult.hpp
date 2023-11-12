#ifndef defoult_HPP
#define defoult_HPP
namespace panov
{
  int fillsArguments(int, const char* []);
  int read();
  class Matrix
  {
  public:
    int line;
    int column;
    int* values;
    void ArrayThatFills();
    void printAvgOfNeigbours()const;
  private:
    double findAverageOfNeighbours(int, int)const;
  };
}
#endif