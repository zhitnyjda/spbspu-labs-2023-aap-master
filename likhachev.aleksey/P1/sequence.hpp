#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
namespace likhachev
{
  struct Sequence {
  public:
    Sequence();
    int read();
    bool have_samge_sing() const;
    int getLmax() const;
    int getLmin() const;
    int getCvalue() const;
    int getPvalue() const;
    int getCount() const;
  private:
    int prevValue;
    int currValue;
    size_t count;
    int localMax;
    int localMin;
  };
};
#endif
