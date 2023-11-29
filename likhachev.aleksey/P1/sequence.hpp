#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
namespace likhachev
{
  struct SequenceLocalMaxCount
  {
    public:
      SequenceLocalMaxCount();
      void operator()(int newNumber);
      void checkLocalMax();
      int getLomaxMaxCount() const;
      int getCount() const;
    private:
      int currValue;
      size_t count;
      int localMax;
      int localMaxCount;
  };

  struct SequenceSignChangeCount
  {
    public:
      SequenceSignChangeCount();
      void operator()(int newNumber);
      void checkSamgeSign(int newNumber);
      int getSignChangeCount() const;
      int getCount() const;
    private:
      int prevValue;
      int currValue;
      size_t count;
      int singChangeCount;
  };
};
#endif
