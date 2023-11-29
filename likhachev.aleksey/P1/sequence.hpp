#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
namespace likhachev
{
  struct SequenceLocalMaxCount
  {
    public:
      SequenceLocalMaxCount();
      void operator()(int newNumber);
      int operator()() const;
      void checkLocalMax();
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
      int operator()() const;
      void checkSamgeSign(int newNumber);
      int getCount() const;
    private:
      int prevValue;
      int currValue;
      size_t count;
      int singChangeCount;
  };
};
#endif
