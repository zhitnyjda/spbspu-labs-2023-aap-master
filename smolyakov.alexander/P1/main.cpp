#include <iostream>

bool testSet(const int * const values);
bool anyValue(const bool * const values);
void clearArray(int * const values);

struct SequenceCounter
{
public:
  int getPythagoreanTriplesCount() const
  {
    return triples_;
  }

  size_t getLength() const
  {
    return elementsCount_;
  }

  void operator()(int v)
  {
    elementsCount_++;
    n3_ = n2_;
    n2_ = n1_;
    n1_ = v;
    if (validate() && elementsCount_ > 2)
    {
      clear();
      triples_++;
    }
  }

private:
  size_t elementsCount_;
  int triples_;
  int n1_;
  int n2_;
  int n3_;

  void clear()
  {
    n1_ = 0;
    n2_ = 0;
    n3_ = 0;
  }

  bool validate() const
  {
    int squares[3];
    squares[0] = n1_ * n1_;
    squares[1] = n2_ * n2_;
    squares[2] = n3_ * n3_;
    bool c1 = (squares[0] == squares[1] + squares[2]);
    bool c2 = (squares[1] == squares[0] + squares[2]);
    bool c3 = (squares[2] == squares[0] + squares[1]);
    return c1 || c2 || c3;
  }
};

int main()
{
  SequenceCounter sequenceCounter{};
  int number;

  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Could not read a number.\n";
      return 1;
    }
    if (number != 0)
    {
      sequenceCounter(number);
    }
  }
  while (number != 0);

  if (sequenceCounter.getLength() < 1)
  {
    std::cerr << "The sequence is too short.\n";
    return 2;
  }

  std::cout << sequenceCounter.getPythagoreanTriplesCount() << '\n';
  return 0;
}

bool testSet(const int * const values)
{
  int squares[3];
  for (int i = 0; i < 3; i++)
  {
    squares[i] = values[i] * values[i];
  }

  bool conditions[3];
  conditions[0] = (squares[0] == squares[1] + squares[2]);
  conditions[1] = (squares[1] == squares[0] + squares[2]);
  conditions[2] = (squares[2] == squares[0] + squares[1]);
  return anyValue(conditions);
}

bool anyValue(const bool * const values)
{
  bool flag = false;
  const int arrayLength = 3;
  for (int i = 0; i < arrayLength; i++)
  {
    flag = (values[i] || flag);
  }
  return flag;
}

void clearArray(int * const values)
{
  const int arrayLength = 3;
  for (int i = 0; i < arrayLength; i++)
  {
    values[i] = 0;
  }
  return;
}
