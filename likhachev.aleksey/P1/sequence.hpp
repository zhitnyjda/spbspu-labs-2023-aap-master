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
      void checkLocalMax();
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
      int getCount() const;
    private:
      void checkSamgeSign(int newNumber);
      int currValue;
      size_t count;
      int singChangeCount;
  };
};
#endif
