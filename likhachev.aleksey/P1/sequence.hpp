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
      int getCount() const;
    private:
      int currValue;
      size_t count;
      int localMax;
      int localMaxCount;
      void checkLocalMax();
  };

  struct SequenceSignChangeCount
  {
    public:
      SequenceSignChangeCount();
      void operator()(int newNumber);
      int operator()() const;
      int getCount() const;
    private:
      int currValue;
      size_t count;
      int singChangeCount;
      void checkSamgeSign(int newNumber);
  };
};
#endif
