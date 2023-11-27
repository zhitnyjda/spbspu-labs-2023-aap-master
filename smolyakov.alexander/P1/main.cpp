#include <iostream>
#include <limits>
#include <stdexcept>

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
    const size_t maxCount = std::numeric_limits< size_t >::max();
    if (elementsCount_ == maxCount)
    {
      throw new std::logic_error("The sequence is too long.");
    }

    if (v == 0)
    {
      return;
    }

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
    try
    {
      sequenceCounter(number);
    }
    catch (const std::logic_error & e)
    {
      std::cerr << "Could not read a number. Details:\n" << e.what();
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
